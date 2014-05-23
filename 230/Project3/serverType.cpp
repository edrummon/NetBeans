#include "serverType.h"

serverType::serverType() {
    status = "free";
    transactionTime = 0;
}

serverType::~serverType() {
}

serverType::serverType(const serverType& other) {
    status = other.status;
    transactionTime = other.transactionTime;
    currentCustomer = other.currentCustomer;
    
}

void serverType::setCustomer(CustomerType& newCustomer, int& transactionTime) {
    currentCustomer = newCustomer;
    this->transactionTime = transactionTime;
    status = "busy";
}

void serverType::decrementTransactionTime() {
    transactionTime--;
    if (transactionTime == 0)
        status = "free";
}

serverType& serverType::operator=(const serverType& other) {
    status = other.status;
    transactionTime = other.transactionTime;
    currentCustomer = other.currentCustomer;
    return *this;
}