/* 
 * File:   stringList.h
 * Author: Instinct212
 *
 * Created on May 27, 2014, 12:32 AM
 */

#ifndef STRINGLIST_H
#define	STRINGLIST_H

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

class StringList {
public:
    StringList() {}
    StringList(std::string s) {L.push_back(s);}
    
    void addString(std::string s) {L.push_back(s);}
    std::list<std::string> getList() const {return L;}
    void printList() const;
private:
    std::list<std::string> L;
};

#endif	/* STRINGLIST_H */

