#include "customerType.h"

CustomerType::CustomerType() {
    waitTime = arrivalTime = ID = 0;
}

CustomerType::CustomerType(int arrivalTime, int ID) {
    this->arrivalTime = arrivalTime;
    this->ID = ID;
    waitTime = 0;
}

CustomerType::~CustomerType() {
}

CustomerType::CustomerType(const CustomerType& other) {
    waitTime = other.waitTime;
    arrivalTime = other.arrivalTime;
    ID = other.ID;
}

CustomerType& CustomerType::operator=(const CustomerType& other) {
    waitTime = other.waitTime;
    arrivalTime = other.arrivalTime;
    ID = other.ID;
    return *this;
}