#include "ArrayType.h"
#include <iostream>
using namespace std;

ArrayType::ArrayType() {
    SIZE = 300;
    ERList = new PatientType[SIZE];
    numPatients = 0;
}

ArrayType::~ArrayType() {
    delete [] ERList;
}

ArrayType::ArrayType(const ArrayType& other) {
    numPatients = other.numPatients;
    *ERList = *(other.ERList);
}

void ArrayType::addPatient(PatientType P) {
    if (numPatients == 0) {
        ERList[0] = P;
    } else  if (P < ERList[numPatients-1]) {
        ERList[numPatients] = P;
    } else {
        for (int i = 0; i < numPatients; i++) {
            if (P > ERList[i]) {
                for (int j = numPatients-1; j >= i; j--) {
                    ERList[j+1] = ERList[j];
                }
                ERList[i] = P;
                break;
            }
        }
    }
    numPatients++;
}

void ArrayType::removePatient() {
    for (int i = 0; i < numPatients; i++) {
        ERList[i] = ERList[i+1];
    }
    numPatients--;
}

int ArrayType::findPosition(string lName, string fName) const {
    for (int i = 0; i < numPatients; i++) {
        if ((ERList[i].getLastName() == lName) && (ERList[i].getFirstName() == fName)) {
            return i+1;
        }
    }
    return -1; //no match found
}

PatientType ArrayType::nextPatient() {
    if (numPatients != 0) {
        return ERList[0];
    } else {
        PatientType P("No more patients", "", "", 0, 0, 0);
        return P;
    }
}

void ArrayType::printList() const {
    cout << endl << "Current Time: " << endl;
    cout << "Last Name,\t" << "First Name\t" << "Priority\t" << "Arrival Time" << endl;
    for (int i = 0; i < numPatients; i++) {
        cout << ERList[i].getLastName() << "\t\t" << ERList[i].getFirstName() << "\t\t"
                << ERList[i].getPriority() << "\t\t" << ERList[i].getArrivalTimeHr() << ":"
                << ERList[i].getArrivalTimeMin() << endl;
    }
}

void ArrayType::operator=(const ArrayType& other) {
    if (&other != this) {
        delete [] ERList;
        PatientType *ERList = new PatientType[SIZE];
        for (int i = 0; i < other.numPatients; i++) {
            ERList[i] = other.ERList[i];
        }
    }
}