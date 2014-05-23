/* 
 * File:   serverType.h
 * Author: Instinct
 *
 * Created on February 11, 2014, 8:25 PM
 */

#ifndef SERVERTYPE_H
#define	SERVERTYPE_H

#include "customerType.h"
#include <cstdlib>
#include <string>

class serverType {
public:
    serverType();
    ~serverType();
    serverType(const serverType& other);
    bool isFree() const {return (status == "free");}
    void setCustomer(CustomerType& newCustomer, int& transactionTime);
    CustomerType& getCustomer() {return currentCustomer;}
    void decrementTransactionTime();
    
    serverType& operator=(const serverType& other);
private:
    std::string status;
    int transactionTime;
    CustomerType currentCustomer;
};

#endif	/* SERVERTYPE_H */

