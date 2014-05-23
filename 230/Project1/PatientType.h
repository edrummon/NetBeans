/* 
 * File:   PatientType.h
 * Author: Instinct
 *
 * Created on February 5, 2014, 4:30 PM
 */

#ifndef PATIENTTYPE_H
#define	PATIENTTYPE_H
using namespace std;
#include <string>

class PatientType {
    
public:
    PatientType();
    PatientType(string lName, string fName, string insurance, int priority, int arrivalTimeHr, int arrivalTimeMin);
    ~PatientType();
    PatientType(const PatientType& other);
    string getFirstName() const;
    string getLastName() const;
    int getPriority() const;
    int getArrivalTimeHr() const;
    int getArrivalTimeMin() const;
    
    bool operator>(PatientType const& other);
    bool operator<(PatientType const& other);
    void operator=(const PatientType& other);
    bool operator!=(PatientType const& other);
    
private:
    string lName, fName, insurance;
    int priority, arrivalTimeHr, arrivalTimeMin;
};

#endif
