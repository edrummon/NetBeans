#include "planet.h"

using std::vector;                      using std::cout;
using std::uniform_int_distribution;    using std::endl;
using std::mt19937;                     using std::pair;
using std::make_pair;

void tile::display() const {
    if (isEmpty())
        cout << '-';
    else if (pFish == nullptr)
        cout << pShark->getPic();
    else
        cout << pFish->getPic();
}

planet::planet(int width, int height, int numFish, int numSharks,
        int fishBreedingAge, int sharkBreedingAge, int sharkStarvationTimer):
planetWidth(width), planetHeight(height), aliveFish(numFish),
        aliveSharks(numSharks), lastAliveFish(0), lastAliveSharks(0) {
    
    for (int i = 0; i < planetHeight; ++i)
        sea.push_back( vector<tile>(planetWidth) );

    for (int i = 0; i < planetHeight; ++i) {
        for (int j = 0; j < planetWidth; ++j)
            sea[i].push_back( tile() );
    }
    
    Fish::setBreedingAge(fishBreedingAge);
    Shark::setBreedingAge(sharkBreedingAge);
    Shark::setStarvationTimer(sharkStarvationTimer);

    initPlanet(fishBreedingAge, sharkBreedingAge);
}

void planet::initPlanet(int fishBreedingAge, int sharkBreedingAge) {
    mt19937 pRNG = warmup();
    
    generateAndPlaceUnits(pRNG, fishBreedingAge, sharkBreedingAge);
    srand(time(NULL));
}

mt19937 planet::warmup() {
    std::array<int, mt19937::state_size> seed_data;
    std::random_device rd;
    std::generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    mt19937 pRNG(seq);
    return pRNG;
}

void planet::generateAndPlaceUnits(mt19937& pRNG, int fishBreedingAge, int sharkBreedingAge) {
    uniform_int_distribution<int> randYcoord(0, planetHeight-1);
    uniform_int_distribution<int> randXcoord(0, planetWidth-1);
    
    uniform_int_distribution<int> randFishAge(0, fishBreedingAge);
    uniform_int_distribution<int> randSharkAge(0, sharkBreedingAge);
    
    int randHeight = randYcoord(pRNG);
    int randWidth = randXcoord(pRNG);
    
    for (int i = 0; i != aliveFish; ++i) {
        while (!sea[randHeight][randWidth].isEmpty()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pFish.reset( new Fish(randFishAge(pRNG)) );
    }
    for (int i = 0; i != aliveSharks; ++i) {
        while (!sea[randHeight][randWidth].isEmpty()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pShark.reset( new Shark(randSharkAge(pRNG)) );
    }
}

void planet::updatePlanet() {
    int y = 0, x = 0;
    for (auto &vector : sea) {
        
        for (auto &tile : vector) {

            if (tile.hasFish() && !tile.pFish.get()->hasMoved()) {

                int newY = y, newX = x;
                findNeighborTile(newY, newX, &tile::isEmpty);
                sea[y][x].pFish.get()->move();
                
                if (newY == y && newX == x) { //fish is surrounded, if would otherwise reproduce then just set its age to 0
                    
                    if (tile.pFish.get()->timeToReproduce()) {
                        
                        sea[y][x].pFish.get()->reproduce();
                        
                    } else {
                        
                        sea[y][x].pFish.get()->grow();
                        
                    }
                    
                } else { //new tile for fish to move to has been found
                    
                    sea[newY][newX].pFish.reset( sea[y][x].pFish.release() );
                    
                    if (sea[newY][newX].pFish.get()->timeToReproduce()) {
                        
                        sea[newY][newX].pFish.get()->reproduce();
                        sea[y][x].pFish.reset( new Fish() );
                        ++aliveFish;
                        
                    } else {
                        
                        sea[newY][newX].pFish.get()->grow();
                        
                    }
                    
                }

            } else if (tile.hasShark() && !tile.pShark.get()->hasMoved()) {
                
                int newY = y, newX = x;
                findNeighborTile(newY, newX, &tile::hasFish);
                sea[y][x].pShark.get()->move();
                
                if (tile.pShark.get()->hasStarved()) {
                    
                    sea[y][x].pShark.reset();
                    --aliveSharks;
                    
                } else {

                    if (newY != y || newX != x) { //this shark has found a fish to eat

                        sea[y][x].pShark.get()->eatFish();
                        sea[newY][newX].pFish.reset();
                        sea[newY][newX].pShark.reset( sea[y][x].pShark.release() );
                        --aliveFish;
                        
                        if (sea[newY][newX].pShark.get()->timeToReproduce()) {

                            sea[newY][newX].pShark.get()->reproduce();
                            sea[y][x].pShark.reset( new Shark() );
                            ++aliveSharks;

                        } else {

                            sea[newY][newX].pShark.get()->grow();

                        }

                    } else { //no fish found, shark will move to a random neighbor tile, just like fish

                        sea[y][x].pShark.get()->noFoodFound();
                        findNeighborTile(newY, newX, &tile::isEmpty);

                        if (newY == y && newX == x) { //shark is surrounded (by sharks), if otherwise would reproduce then just set its age to 0

                            if (sea[y][x].pShark.get()->timeToReproduce()) {

                                sea[y][x].pShark.get()->reproduce();

                            } else {

                                sea[y][x].pShark.get()->grow();

                            }

                        } else {
                            
                            sea[y][x].pShark.get()->grow();
                            sea[newY][newX].pShark.reset( sea[y][x].pShark.release() );
                            
                        }

                    }

                }

            }
            x = (x+planetWidth+1)%planetWidth;
        }
        y = (y+planetHeight+1)%planetHeight;
    }
    
    for (auto &vec : sea) {
        std::for_each(vec.begin(), vec.end(), [&] (tile& t) {
            if (t.hasFish())
                t.pFish.get()->resetMoved();
            else if (t.hasShark())
                t.pShark.get()->resetMoved();
        });
    }
}

void planet::findNeighborTile(int& y, int& x, bool (tile::*func)() const) {
    int yMod = y+planetHeight;
    int xMod = x+planetWidth;
    
    int yAbove = (yMod-1)%planetHeight;
    int yBelow = (yMod+1)%planetHeight;
    int xLeft = (xMod-1)%planetWidth;
    int xRight = (xMod+1)%planetWidth;
    
    vector<pair<int, int> > neighborCoords; //stores coordinates of all 8 neighbor tiles
    
    neighborCoords.push_back(make_pair(yAbove, x));
    neighborCoords.push_back(make_pair(yAbove, xRight));
    neighborCoords.push_back(make_pair(y, xRight));
    neighborCoords.push_back(make_pair(yBelow, xRight));
    neighborCoords.push_back(make_pair(yBelow, x));
    neighborCoords.push_back(make_pair(yBelow, xLeft));
    neighborCoords.push_back(make_pair(y, xLeft));
    neighborCoords.push_back(make_pair(yAbove, xLeft));
    
    int uncheckedNeighbors = neighborCoords.size();
    int randVectorIndex = rand() % (uncheckedNeighbors--);
    
    int neighborCoordY = neighborCoords[randVectorIndex].first;
    int neighborCoordX = neighborCoords[randVectorIndex].second; //could redo most of this using shuffle and then pop_back in the while
    
    while (!(sea[neighborCoordY][neighborCoordX].*func)() && uncheckedNeighbors > 0) { //if function isn't true for this tile, remove it and try another random neighbor
        
        neighborCoords.erase(neighborCoords.begin() + randVectorIndex);
        randVectorIndex = rand() % (uncheckedNeighbors--);
        
        neighborCoordY = neighborCoords[randVectorIndex].first;
        neighborCoordX = neighborCoords[randVectorIndex].second;
        
    }
    if (uncheckedNeighbors != 0) { //an appropriate new tile was found, we didn't just run out of possibilities
        y = neighborCoordY;
        x = neighborCoordX;
    }
}

void planet::displaySea() const {
    for (int i = 0; i < planetHeight; ++i) {
        for (int j = 0; j < planetWidth; ++j) {
            sea[i][j].display();
        }
        cout << endl;
    }
}

void planet::displayPopulationChange() {
    int fishPopulationChange = aliveFish - lastAliveFish;
    int sharkPopulationChange = aliveSharks - lastAliveSharks;
    
    cout << "Fish: " << aliveFish << " change: "
            << ((fishPopulationChange > 0 ) ? "+" : "") << fishPopulationChange << "\t"
            << "Sharks: " << aliveSharks << " change: "
            << ((sharkPopulationChange > 0) ? "+" : "") << sharkPopulationChange << endl;
    
    lastAliveFish = aliveFish;
    lastAliveSharks = aliveSharks;
}