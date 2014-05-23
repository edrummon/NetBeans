/* 
 * File:   LinkedListType.h
 * Author: Instinct
 *
 * Created on February 8, 2014, 9:58 PM
 */

#ifndef LINKEDLISTTYPE_H
#define	LINKEDLISTTYPE_H

#include "NodeType.h"
#include <cstdlib>

template<class ItemType>
class LinkedListType {
public:
    LinkedListType();
    ~LinkedListType();
private:
    NodeType<ItemType> *head;
};

template<class ItemType>
LinkedListType<ItemType>::LinkedListType() {
    head = NULL;
}

template<class ItemType>
LinkedListType<ItemType>::~LinkedListType() {
    delete head;
}

#endif	/* LINKEDLISTTYPE_H */

