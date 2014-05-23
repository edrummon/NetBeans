#include "PatientType.h"
#include <string>

PatientType::PatientType() {
    lName = fName = insurance = "";
    priority = arrivalTimeHr = arrivalTimeMin = 0;
}

PatientType::PatientType(string lName, string fName, string insurance, int priority, int arrivalTimeHr, int arrivalTimeMin) {
    this->lName = lName;
    this->fName = fName;
    this->insurance = insurance;
    this->priority = priority;
    this->arrivalTimeHr = arrivalTimeHr;
    this->arrivalTimeMin = arrivalTimeMin;
}

PatientType::~PatientType() {
}

PatientType::PatientType(const PatientType& other) {
    lName = other.lName;
    fName = other.fName;
    insurance = other.insurance;
    priority = other.priority;
    arrivalTimeHr = other.arrivalTimeHr;
    arrivalTimeMin = other.arrivalTimeMin;
}

string PatientType::getFirstName() const {
    return fName;
}

string PatientType::getLastName() const {
    return lName;
}

int PatientType::getPriority() const {
    return priority;
}

int PatientType::getArrivalTimeHr() const {
    return arrivalTimeHr;
}

int PatientType::getArrivalTimeMin() const {
    return arrivalTimeMin;
}

bool PatientType::operator<(PatientType const& other) {
    if (priority != other.getPriority()) {
        return (priority < other.getPriority());
    } else {
        if (arrivalTimeHr != other.getArrivalTimeHr()) {
            return (other.getArrivalTimeHr() < arrivalTimeHr);
        } else {
            return (other.getArrivalTimeMin() < arrivalTimeMin);
        }
    }
}

bool PatientType::operator>(PatientType const& other) {
    if (priority != other.getPriority()) {
        return (priority > other.getPriority());
    } else {
        if (arrivalTimeHr != other.getArrivalTimeHr()) {
            return (other.getArrivalTimeHr() > arrivalTimeHr);
        } else {
            return (other.getArrivalTimeMin() > arrivalTimeMin);
        }
    }
}

void PatientType::operator=(const PatientType& other) {
    lName = other.lName;
    fName = other.fName;
    insurance = other.insurance;
    priority = other.priority;
    arrivalTimeHr = other.arrivalTimeHr;
    arrivalTimeMin = other.arrivalTimeMin;
}

bool PatientType::operator!=(PatientType const& other) {
    return (lName != other.lName || fName != other.fName || insurance != other.insurance
            || priority != other.priority || arrivalTimeHr != other.arrivalTimeHr
            || arrivalTimeMin != other.arrivalTimeMin);
}