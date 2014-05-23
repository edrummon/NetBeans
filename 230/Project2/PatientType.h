/* 
 * File:   PatientType.h
 * Author: Instinct
 *
 * Created on February 7, 2014, 5:31 PM
 */

#ifndef PATIENTTYPE_H
#define	PATIENTTYPE_H
#include <string>
#include <iostream>
#include <iomanip>

class PatientType {
public:
    PatientType();
    PatientType(std::string, std::string, std::string, int, int, int);
    ~PatientType();
    PatientType(const PatientType& other);
    std::string getfName() const {return fName;}
    std::string getlName() const {return lName;}
    int getPriority() const {return priority;}
    int getArrivalTimeHr() const {return arrivalTimeHr;}
    int getArrivalTimeMin() const {return arrivalTimeMin;}
    void setfName(std::string);
    static void printPatient(PatientType P);
    
    bool operator>(const PatientType& other);
    bool operator<(const PatientType& other);
    bool operator!=(const PatientType& other);
    void operator=(const PatientType& other);
private:
    std::string fName, lName, insurance;
    int priority, arrivalTimeHr, arrivalTimeMin;
};

#endif	/* PATIENTTYPE_H */