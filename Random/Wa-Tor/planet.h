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
};

class planet {
public:
    planet() { planetWidth = planetHeight = lastAliveFish = lastAliveSharks = 0; }
    planet(int, int, int, int, int, int, int);
    
    void initPlanet(int, int, int, int);

    std::mt19937 warmup();
    
    void generateFish(std::mt19937&, int, int);
    void generateSharks(std::mt19937&, int, int);
    void placement(std::mt19937&);
    
    void updatePlanet();
    void findNeighborTile(int&, int&, bool (tile::*func)() const);
    
    void displaySea() const;
    void displayPopulationChange();
    void cleanAliveVectors();
private:
    int planetWidth, planetHeight;
    int lastAliveFish, lastAliveSharks;
    
    std::vector<std::vector<tile> > sea;
    std::vector<std::shared_ptr<Fish> > aliveFish;
    std::vector<std::shared_ptr<Shark> > aliveSharks;
};

#endif	/* PLANET_H */