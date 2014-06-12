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
    Fish(): age(0) {}
    Fish(int a): age(a) {}
    
    static void setBreedingAge(int b) { int breedingAge = b; }
    char getPic() const { return pic; }
    
    void breed();
    void move();
private:
    int age;
    static const int breedingAge;
    char pic = 'F';
};

#endif	/* FISH_H */