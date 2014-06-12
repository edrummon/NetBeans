/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:33 AM
 */

#include "planet.h"

using std::cout;        using std::endl;
using std::cin;

int main(int argc, char** argv) {
    
    planet x(5, 5, 5, 5, 5, 5, 5);
    x.displaySea();
    cout << "here";
    //x.updatePlanet();

    return 0;
}