/* 
 * File:   NodeType.h
 * Author: Instinct
 *
 * Created on February 8, 2014, 9:58 PM
 */

#ifndef NODETYPE_H
#define	NODETYPE_H

#include <cstdlib>

template<class ItemType> class LinkedListType;

template<class ItemType>
class NodeType {

friend class LinkedListType<ItemType>;

public:
    NodeType();
    ~NodeType();
private:
    ItemType data;
    NodeType *next;
};

template<class ItemType>
NodeType<ItemType>::NodeType() {
    next = NULL;
}

template<class ItemType>
NodeType<ItemType>::~NodeType() {
    delete next;
}

#endif	/* NODETYPE_H */

