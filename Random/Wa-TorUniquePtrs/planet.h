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
    
    std::unique_ptr<Fish> pFish;
    std::unique_ptr<Shark> pShark;
};

class planet {
public:
    planet() { planetWidth = planetHeight = activeFish = activeSharks = 0; }
    planet(int, int, int, int, int, int, int);
    
    void initPlanet(int, int);

    std::mt19937 warmup();
    void generateAndPlaceUnits(std::mt19937&, int, int);
    
    void updatePlanet();
    void findNeighborTile(int&, int&, bool (tile::*func)() const);
    
    void displaySea() const;
private:
    int planetWidth, planetHeight;
    int activeFish, activeSharks;
    
    std::vector<std::vector<tile> > sea;
};

#endif	/* PLANET_H */