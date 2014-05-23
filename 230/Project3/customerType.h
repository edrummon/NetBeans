/* 
 * File:   customerType.h
 * Author: Instinct
 *
 * Created on February 11, 2014, 8:20 PM
 */

#ifndef CUSTOMERTYPE_H
#define	CUSTOMERTYPE_H

class CustomerType {
public:
    CustomerType();
    CustomerType(int, int);
    ~CustomerType();
    CustomerType(const CustomerType& other);
    void incrementWaitTime() {waitTime++;}
    int& getArrivalTime() {return arrivalTime;}
    int& getWaitTime() {return waitTime;}
    int& getID() {return ID;}
    
    CustomerType& operator=(const CustomerType& other);
private:
    int ID, arrivalTime, waitTime;
};

#endif	/* CUSTOMERTYPE_H */