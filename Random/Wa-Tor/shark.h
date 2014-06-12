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
    Shark(): age(0) {}
    Shark(int a): age(a) {}
    
    static void setBreedingAge(int b) { int breedingAge = b; }
    static void setStarvationTimer(int s) { int starvationTimer = s; }
    
    char getPic() const { return pic; }
    
    void breed();
    void hunt();
    void move();
    //eatFish() { starvationTimer = 0; }
private:
    int age;
    static const int breedingAge, starvationTimer;
    char pic = 'S';
};

#endif	/* SHARK_H */