/* 
 * File:   ArrayType.h
 * Author: Instinct
 *
 * Created on February 5, 2014, 4:21 PM
 */

#ifndef ARRAYTYPE_H
#define	ARRAYTYPE_H
#include "PatientType.h"
#include <string>

class ArrayType {
    
public:
    ArrayType();
    ~ArrayType();
    ArrayType(const ArrayType& other);
    void addPatient(PatientType P);
    void removePatient();
    int findPosition(string fName, string lName) const;
    PatientType nextPatient();
    void printList() const;
    
    void operator=(const ArrayType& other);
    
private:
    PatientType *ERList;
    int SIZE;
    int numPatients;
};

#endif