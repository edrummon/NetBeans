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
    Fish(): age(0), moved(false) {}
    Fish(int a): age(a), moved(false) {}
    
    static void setBreedingAge(int b) { int breedingAge = b; }
    char getPic() const { return pic; }
    
    void grow() { ++age; }
    void reproduce() { age = 0; }
    
    void move() { moved = true; }
    void reset() { moved = false; }
    
    bool hasMoved() const { return moved; }
    bool timeToReproduce() const { return age == breedingAge; }
private:
    int age;
    static const int breedingAge;
    char pic = 'F';
    bool moved;
};

#endif	/* FISH_H */