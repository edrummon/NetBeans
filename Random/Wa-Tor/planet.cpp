#include "planet.h"

using std::vector;                      using std::shared_ptr;
using std::uniform_int_distribution;    using std::cout;
using std::endl;

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
    std::mt19937 pRNG = warmup();
    
    generateFish(pRNG, numFish, fishBreedingAge);
    generateSharks(pRNG, numSharks, sharkBreedingAge);
    
    placement(pRNG);
}

std::mt19937 planet::warmup() {
    std::array<int, std::mt19937::state_size> seed_data;
    std::random_device rd;
    std::generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 pRNG(seq);
    return pRNG;
}

void planet::generateFish(std::mt19937& pRNG, int numFish, int fishBreedingAge) {
    uniform_int_distribution<int> randFishAge(0, fishBreedingAge);
    
    for (int i = 0; i < numFish; ++i) {
        shared_ptr<Fish> f(new Fish(randFishAge(pRNG)));
        activeFish.push_back(f);
    }
}

void planet::generateSharks(std::mt19937& pRNG, int numSharks, int sharkBreedingAge) {
    uniform_int_distribution<int> randSharkAge(0, sharkBreedingAge);
    
    for  (int i = 0; i < numSharks; ++i) {
        shared_ptr<Shark> s(new Shark(randSharkAge(pRNG)));
        activeSharks.push_back(s);
    }
}

void planet::placement(std::mt19937& pRNG) {
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

void planet::updatePlanet() {
    int y = 0, x = 0;
    for (auto &v : sea) {
        for (auto &t : v) {
            if (t.hasFish()) {
                int newY = y, newX = x;
                findEmptyNeighborTile(newY, newX);
                sea[newY][newX].pFish = sea[y][x].pFish;
                sea[y][x].pFish = nullptr;
            } else if (t.hasShark()) {
                int newY = y, newX = x;
                //change findEmptyNeighborTile to also take a function, t.hasFish() passes isOccupied()
                //and t.hasShark() passes hasFish()
            }
            ++x;
        }
        ++y;
    }
}

void planet::findEmptyNeighborTile(int& y, int& x) {
    if (!sea[(y+planetHeight-1)%planetHeight][x].isOccupied()) {
        y = (y+planetHeight-1)%planetHeight;
    } else if (!sea[(y+planetHeight-1)%planetHeight][(x+planetWidth+1)%planetWidth].isOccupied()) {
        y = (y+planetHeight-1)%planetHeight;
        x = (x+planetWidth+1)%planetWidth;
    } else if (!sea[y][(x+planetWidth+1)%planetWidth].isOccupied()) {
        x = (x+planetWidth+1)%planetWidth;
    } else if (!sea[(y+planetHeight+1)%planetHeight][(x+planetWidth+1)%planetWidth].isOccupied()) {
        y = (y+planetHeight+1)%planetHeight;
        x = (x+planetWidth+1)%planetWidth;
    } else if (!sea[(y+planetHeight+1)%planetHeight][x].isOccupied()) {
        y = (y+planetHeight+1)%planetHeight;
    } else if (!sea[(y+planetHeight+1)%planetHeight][(x+planetWidth-1)%planetWidth].isOccupied()) {
        y = (y+planetHeight+1)%planetHeight;
        x = (x+planetWidth-1)%planetWidth;
    } else if (!sea[y][(x+planetWidth-1)%planetWidth].isOccupied()) {
        x = (x+planetWidth-1)%planetWidth;
    } else if (!sea[(y+planetHeight-1)%planetHeight][(x+planetWidth-1)%planetWidth].isOccupied()) {
        y = (y+planetHeight-1)%planetHeight;
        x = (x+planetWidth-1)%planetWidth;
    } else if (!sea[(y+planetHeight-1)%planetHeight][x].isOccupied()) {
        y = (y+planetHeight-1)%planetHeight;
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