/* 
 * File:   shark.h
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:40 AM
 */

#ifndef SHARK_H
#define	SHARK_H

class Shark {
public:
    Shark(): age(0), breedingAge(1), starvationTimer(2) {}
    Shark(int a, int breedAge, int starve): age(a), breedingAge(breedAge), starvationTimer(starve) {}
    
    breed();
    hunt();
    move();
    eatFish() { starvationTimer = 0; }
private:
    int age, breedingAge, starvationTimer;
};

#endif	/* SHARK_H */