/* 
 * File:   PatientType.h
 * Author: Instinct
 *
 * Created on February 8, 2014, 9:45 PM
 */

#ifndef PATIENTTYPE_H
#define	PATIENTTYPE_H

#include <string>

class PatientType {
public:
    PatientType();
    ~PatientType();
private:
    std::string fName, lName, insurance;
    int priority, arrivalTimeHr, arrivalTimeMin;
};

#endif	/* PATIENTTYPE_H */

