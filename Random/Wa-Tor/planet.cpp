#include "planet.h"

using std::vector;                      using std::shared_ptr;
using std::uniform_int_distribution;    using std::cout;
using std::endl;                        using std::mt19937;

void tile::display() const {
    if (!isOccupied())
        cout << '-';
    else if (pFish == nullptr)
        cout << pShark->getPic();
    else
        cout << pFish->getPic();
}

planet::planet(int width, int height, int numFish, int numSharks,
        int fishBreedingAge, int sharkBreedingAge, int sharkStarvationTimer):
planetWidth(width), planetHeight(height) {
    
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
        activeFish.push_back(f);
    }
}

void planet::generateSharks(mt19937& pRNG, int numSharks, int sharkBreedingAge) {
    uniform_int_distribution<int> randSharkAge(0, sharkBreedingAge);
    
    for  (int i = 0; i < numSharks; ++i) {
        shared_ptr<Shark> s(new Shark(randSharkAge(pRNG)));
        activeSharks.push_back(s);
    }
}

void planet::placement(mt19937& pRNG) {
    uniform_int_distribution<int> randYcoord(0, planetHeight-1);
    uniform_int_distribution<int> randXcoord(0, planetWidth-1);
    
    int randHeight = randYcoord(pRNG);
    int randWidth = randXcoord(pRNG);
    for (int i = 0; i < activeFish.size(); ++i) {
        while (sea[randHeight][randWidth].isOccupied()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pFish = activeFish[i];
    }
    for (int i = 0; i < activeSharks.size(); ++i) {
        while (sea[randHeight][randWidth].isOccupied()) {
            randHeight = randYcoord(pRNG);
            randWidth = randXcoord(pRNG);
        }
        sea[randHeight][randWidth].pShark = activeSharks[i];
    }
}

shared_ptr<Fish> fishReset(shared_ptr<Fish> f) {
    f.get()->reset();
    return f;
}

shared_ptr<Shark> sharkReset(shared_ptr<Shark> s) {
    s.get()->reset();
    return s;
}

void planet::updatePlanet() {
    int y = 0, x = 0;
    for (auto &vector : sea) {
        
        for (auto &tile : vector) {
            
            if (tile.hasFish() && !tile.pFish.get()->hasMoved()) {

                if (tile.pFish.get()->timeToReproduce()) {
                    
                    //normal move stuff (maybe take some code from the ELSE and move it above this IF)
                    //but then make new fish in oldY oldX spot and both ages = 0
                    
                } else {

                    int newY = y, newX = x;
                    findNeighborTile(newY, newX, &tile::isOccupied);
                    sea[newY][newX].pFish = sea[y][x].pFish;
                    sea[newY][newX].pFish.get()->move();
                    sea[newY][newX].pFish.get()->grow();
                    sea[y][x].pFish = nullptr;

                }

            } else if (tile.hasShark() && !tile.pShark.get()->hasMoved()) {
                
                int newY = y, newX = x;
                findNeighborTile(newY, newX, &tile::hasFish);
                if (newY != y || newX != x) { //this shark has found a fish to eat
                    
                    sea[newY][newX].pFish = nullptr;
                    sea[newY][newX].pShark = sea[y][x].pShark;
                    sea[newY][newX].pShark.get()->eatFish();
                    
                } else { //no fish found, shark will move to a random neighbor tile, just like fish do
                    
                    findNeighborTile(newY, newX, &tile::isOccupied);
                    sea[newY][newX].pShark = sea[y][x].pShark;
                    sea[newY][newX].pShark.get()->noFood();
                    
                }
                
                sea[y][x].pShark = nullptr;
                sea[newY][newX].pShark.get()->move();
                sea[newY][newX].pShark.get()->grow();
                
            }
            x = (x+planetWidth+1)%planetWidth;
        }
        y = (y+planetHeight+1)%planetHeight;
    }
    std::transform(activeFish.begin(), activeFish.end(), activeFish.begin(), ::fishReset);
    std::transform(activeSharks.begin(), activeSharks.end(), activeSharks.begin(), ::sharkReset);
}

void planet::findNeighborTile(int& y, int& x, bool (tile::*func)() const) {
    int yMod = y+planetHeight;
    int xMod = x+planetWidth;
    
    int yAbove = (yMod-1)%planetHeight;
    int yBelow = (yMod+1)%planetHeight;
    int xLeft = (xMod-1)%planetWidth;
    int xRight = (xMod+1)%planetWidth;
    
    if (!(sea[yAbove][x].*func)()) {
        y = yAbove;
    } else if (!(sea[yAbove][xRight].*func)()) {
        y = yAbove;
        x = xRight;
    } else if (!(sea[y][xRight].*func)()) {
        x = xRight;
    } else if (!(sea[yBelow][xRight].*func)()) {
        y = yBelow;
        x = xRight;
    } else if (!(sea[yBelow][x].*func)()) {
        y = yBelow;
    } else if (!(sea[yBelow][xLeft].*func)()) {
        y = yBelow;
        x = xLeft;
    } else if (!(sea[y][xLeft].*func)()) {
        x = xLeft;
    } else if (!(sea[yAbove][xLeft].*func)()) {
        y = yAbove;
        x = xLeft;
    } else if (!(sea[yAbove][x].*func)()) {
        y = yAbove;
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