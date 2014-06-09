/* 
 * File:   planet.h
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:44 AM
 */

#ifndef PLANET_H
#define	PLANET_H

#include <vector>
#include "cell.h"

class planet {
public:
    planet() { planetWidth = planetHeight = 0; }
    planet(int width, int height): planetWidth(width), planetHeight(height) { std::vector<std::vector<cell> > sea(height, std::vector<cell>(width)); }
private:
    int planetWidth, planetHeight;
    std::vector<std::vector<cell> > sea;
};

#endif	/* PLANET_H */