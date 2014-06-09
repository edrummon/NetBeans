/* 
 * File:   fish.h
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:40 AM
 */

#ifndef FISH_H
#define	FISH_H

class Fish {
public:
    Fish(): age(0), breedingAge(1) {}
    Fish(int a, int breedAge): age(a), breedingAge(breedAge) {}
    
    breed();
    move();
private:
    int age, breedingAge;
};

#endif	/* FISH_H */