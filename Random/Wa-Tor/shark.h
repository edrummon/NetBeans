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
    Shark(): age(0), timeSinceFood(0), moved(false) {}
    Shark(int a): age(a), timeSinceFood(0), moved(false) {}
    
    static void setBreedingAge(int b) { breedingAge = b; }
    static void setStarvationTimer(int s) { starvationTimer = s; }
    
    char getPic() const { return pic; }
    
    void grow() { ++age; }
    void reproduce() { age = 0; }
    void eatFish() { timeSinceFood = 0; }
    void noFoodFound() { ++timeSinceFood; }
    
    void move() { moved = true; }
    void resetMoved() { moved = false; }
    
    bool hasMoved() const { return moved; }
    bool timeToReproduce() const { return age == breedingAge; }
    bool hasStarved() { return timeSinceFood == starvationTimer; }
private:
    int age, timeSinceFood;
    static int breedingAge, starvationTimer;
    char pic = 'S';
    bool moved;
};

#endif	/* SHARK_H */