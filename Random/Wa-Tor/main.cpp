/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:33 AM
 */

#include <time.h>
#include "planet.h"

using std::cout;        using std::endl;
using std::cin;

void wait(int seconds) {
    int endwait = clock() + seconds * CLOCKS_PER_SEC * .5;
    while (clock() < endwait) {}
}

int main(int argc, char** argv) {
    
    int width, height, numFish, numSharks, fishBreedingAge,
            sharkBreedingAge, sharkStarvationTimer, numIterations;
    
    cout << "Simulation parameters: ";
    cin >> width >> height >> numFish >> numSharks >> fishBreedingAge
            >> sharkBreedingAge >> sharkStarvationTimer >> numIterations;
    cout << endl;
    
    planet Wa_Tor(width, height, numFish, numSharks, fishBreedingAge,
            sharkBreedingAge, sharkStarvationTimer);
    
    Wa_Tor.displaySea();

    for (int iteration = 0; iteration != numIterations; ++iteration) {
        Wa_Tor.updatePlanet();
        wait(1);
        cout << endl;
        Wa_Tor.displaySea();
    }

    return 0;
}