#include "PatientType.h"

PatientType::PatientType() {
    fName = lName = insurance = "";
    priority = arrivalTimeHr = arrivalTimeMin = 0;
}

PatientType::PatientType(std::string fName, std::string lName, std::string insurance, int priority, int arrivalTimeHr, int arrivalTimeMin) {
    this->fName = fName;
    this->lName = lName;
    this->insurance = insurance;
    this->priority = priority;
    this->arrivalTimeHr = arrivalTimeHr;
    this->arrivalTimeMin = arrivalTimeMin;
}

PatientType::~PatientType() {
}

PatientType::PatientType(const PatientType& other) {
    fName = other.fName;
    lName = other.lName;
    insurance = other.insurance;
    priority = other.priority;
    arrivalTimeHr = other.arrivalTimeHr;
    arrivalTimeMin = other.arrivalTimeMin;
}

void PatientType::setfName(std::string newfName) {
    fName = newfName;
}

void PatientType::printPatient(PatientType P) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(20) << P.getlName() << std::setw(15) << P.getfName();
    std::cout.setf(std::ios::right);
    std::cout << std::setw(8) << P.getPriority() << std::setw(11) << P.getArrivalTimeHr() 
            << ":" << std::setw(2) << P.getArrivalTimeMin() << std::endl;
}

bool PatientType::operator>(const PatientType& other) {
    if (priority != other.priority) {
        return (priority > other.priority);
    } else if (arrivalTimeHr != other.arrivalTimeHr) {
        return (other.arrivalTimeHr < arrivalTimeHr);
    } else {
        return (other.arrivalTimeMin < arrivalTimeMin);
    }
}

bool PatientType::operator<(const PatientType& other) {
    if (priority != other.priority) {
        return (priority < other.priority);
    } else if (arrivalTimeHr != other.arrivalTimeHr) {
        return (other.arrivalTimeHr > arrivalTimeHr);
    } else {
        return (other.arrivalTimeMin > arrivalTimeMin);
    }
}

bool PatientType::operator!=(const PatientType& other) {
    return (fName != other.fName && lName != other.lName && 
            insurance != other.insurance && priority != other.priority &&
            arrivalTimeHr != other.arrivalTimeHr && 
            arrivalTimeMin != other.arrivalTimeMin);
}

void PatientType::operator=(const PatientType& other) {
    fName = other.fName;
    lName = other.lName;
    insurance = other.insurance;
    priority = other.priority;
    arrivalTimeHr = other.arrivalTimeHr;
    arrivalTimeMin = other.arrivalTimeMin;
}