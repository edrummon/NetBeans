#include "planet.h"

using std::vector;                      using std::shared_ptr;
using std::uniform_int_distribution;    using std::cout;
using std::endl;                        using std::mt19937;
using std::pair;                        using std::make_pair;

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
planetWidth(width), planetHeight(height), lastAliveFish(0), lastAliveSharks(0) {
    
    for (int i = 0; i < planetHeight; ++i) {
        vector<tile> v(planetWidth);
        sea.push_back(v);
    }
    for (int i = 0; i < planetHeight; ++i) {
        for (int j = 0; j < planetWidth; ++j) {
            sea[i][j] = tile();
        }
    }
    
    Fish::setBreedingAge(fishBreedingAge);
    Shark::setBreedingAge(sharkBreedingAge);
    Shark::setStarvationTimer(sharkStarvationTimer);

    initPlanet(numFish, numSharks, fishBreedingAge, sharkBreedingAge);
}

void planet::initPlanet(int numFish, int numSharks, int fishBreedingAge, int sharkBreedingAge) {
    mt19937 pRNG = warmup();
    
    generateFish(pRNG, numFish, fishBreedingAge);
    generateSharks(pRNG, numSharks, sharkBreedingAge);
    
    placement(pRNG);
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

void planet::generateFish(mt19937& pRNG, int numFish, int fishBreedingAge) {
    uniform_int_distribution<int> randFishAge(0, fishBreedingAge);
    
    for (int i = 0; i < numFish; ++i) {
        shared_ptr<Fish> f(new Fish(randFishAge(pRNG)));
        aliveFish.push_back(f);
    }
}

void planet::generateSharks(mt19937& pRNG, int numSharks, int sharkBreedingAge) {
    uniform_int_distribution<int> randSharkAge(0, sharkBreedingAge);
    
    for  (int i = 0; i < numSharks; ++i) {
        shared_ptr<Shark> s(new Shark(randSharkAge(pRNG)));
        aliveSharks.push_back(s);
    }
}

void planet::placement(mt19937& pRNG) {
    uniform_int_distribution<int> randYcoord(0, planetHeight-1);
    uniform_int_distribution<int> randXcoord(0, planetWidth-1);
    
    int randHeight = randYcoord(pRNG);
    int randWidth = randXcoord(pRNG);
    for (int i = 0; i < aliveFish.size(); ++i) {
        while (!sea[randHeight][randWidth].isEmpty()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pFish = aliveFish[i];
    }
    for (int i = 0; i < aliveSharks.size(); ++i) {
        while (!sea[randHeight][randWidth].isEmpty()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pShark = aliveSharks[i];
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
                    
                } else {
                    
                    sea[newY][newX].pFish = sea[y][x].pFish;
                    
                    if (tile.pFish.get()->timeToReproduce()) {
                        
                        sea[newY][newX].pFish.get()->reproduce();
                        shared_ptr<Fish> f(new Fish());
                        aliveFish.push_back(f);
                        sea[y][x].pFish = aliveFish[aliveFish.size()-1];
                        
                    } else {
                        
                        sea[newY][newX].pFish.get()->grow();
                        sea[y][x].pFish = nullptr;
                        
                    }
                    
                }

            } else if (tile.hasShark() && !tile.pShark.get()->hasMoved()) {
                
                int newY = y, newX = x;
                findNeighborTile(newY, newX, &tile::hasFish);
                sea[y][x].pShark.get()->move();
                
                if (tile.pShark.get()->hasStarved()) {
                    
                    sea[y][x].pShark = nullptr;
                    
                } else {

                    if (newY != y || newX != x) { //this shark has found a fish to eat

                        sea[y][x].pShark.get()->eatFish();
                        sea[newY][newX].pFish = nullptr;
                        sea[newY][newX].pShark = sea[y][x].pShark;
                        
                        if (tile.pShark.get()->timeToReproduce()) {

                            sea[newY][newX].pShark.get()->reproduce();
                            shared_ptr<Shark> s(new Shark());
                            aliveSharks.push_back(s);
                            sea[y][x].pShark = aliveSharks[aliveSharks.size()-1];

                        } else {

                            sea[newY][newX].pShark.get()->grow();
                            sea[y][x].pShark = nullptr;

                        }

                    } else { //no fish found, shark will move to a random neighbor tile, just like fish

                        sea[y][x].pShark.get()->noFoodFound();
                        findNeighborTile(newY, newX, &tile::isEmpty);

                        if (newY == y && newX == x) { //shark is surrounded (by sharks), if otherwise would reproduce then just set its age to 0

                            if (tile.pShark.get()->timeToReproduce()) {

                                sea[y][x].pShark.get()->reproduce();

                            } else {

                                sea[y][x].pShark.get()->grow();

                            }

                        } else {
                            
                            sea[y][x].pShark.get()->grow();
                            sea[newY][newX].pShark = sea[y][x].pShark;
                            sea[y][x].pShark = nullptr;
                            
                        }

                    }

                }
                
            }
            x = (x+planetWidth+1)%planetWidth;
        }
        y = (y+planetHeight+1)%planetHeight;
    }
    std::for_each(aliveFish.begin(), aliveFish.end(),
            [&] (shared_ptr<Fish> f) { f.get()->resetMoved(); });
    std::for_each(aliveSharks.begin(), aliveSharks.end(),
            [&] (shared_ptr<Shark> s) { s.get()->resetMoved(); });
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
    cleanAliveVectors();
    cout << "Fish: " << aliveFish.size() << " change: " << int (aliveFish.size()) - lastAliveFish
            << "\t" << "Sharks: " << aliveSharks.size() << " change: "
            << int (aliveSharks.size()) - lastAliveSharks << endl;
    
    lastAliveFish = aliveFish.size();
    lastAliveSharks = aliveSharks.size();
}

void planet::cleanAliveVectors() {
    for (auto fishIter = aliveFish.begin(); fishIter != aliveFish.end(); ++fishIter) {
        if (fishIter->use_count() == 1) {
            aliveFish.erase(fishIter);
            --fishIter;
        }
    }
    for (auto sharkIter = aliveSharks.begin(); sharkIter != aliveSharks.end(); ++sharkIter) {
        if (sharkIter->use_count() == 1) {
            aliveSharks.erase(sharkIter);
            --sharkIter;
        }
    }
}