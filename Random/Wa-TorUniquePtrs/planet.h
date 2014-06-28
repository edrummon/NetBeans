/* 
 * File:   planet.h
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:44 AM
 */

#ifndef PLANET_H
#define	PLANET_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <utility>
#include <vector>
#include "fish.h"
#include "shark.h"

struct tile {
    tile(): pFish(nullptr), pShark(nullptr) {}
    
    bool isEmpty() const { return pFish == nullptr && pShark == nullptr; }
    bool hasFish() const { return pFish != nullptr; }
    bool hasShark() const { return pShark != nullptr; }
    
    void display() const;
    
    std::shared_ptr<Fish> pFish;
    std::shared_ptr<Shark> pShark;
    //maybe delete active vectors in planet and make these unique_ptrs, by default 
    //they'll be nullptr but can give them a new raw pointer with pFish.reset(new Fish())
    //but then counting fish/sharks each tick is a pain in the ass? new private planet ints: numFish/numSharks?
};

class planet {
public:
    planet() { planetWidth = planetHeight = 0; }
    planet(int, int, int, int, int, int, int);
    
    void initPlanet(int, int, int, int);

    std::mt19937 warmup();
    void generateFish(std::mt19937&, int, int);
    void generateSharks(std::mt19937&, int, int);
    void placement(std::mt19937&);
    
    void updatePlanet();
    void findNeighborTile(int&, int&, bool (tile::*func)() const);
    
    void displaySea() const;
private:
    int planetWidth, planetHeight;
    
    std::vector<std::vector<tile> > sea;
    std::vector<std::shared_ptr<Fish> > activeFish;
    std::vector<std::shared_ptr<Shark> > activeSharks;
};

#endif	/* PLANET_H */