/* 
 * File:   NodeType.h
 * Author: Instinct
 *
 * Created on February 7, 2014, 5:31 PM
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
    NodeType(ItemType item);
    ~NodeType();
    NodeType(const NodeType& other);
    
    void operator=(const NodeType& other);
private:
    ItemType data;
    NodeType *next;
};

template<class ItemType>
NodeType<ItemType>::NodeType() {
    next = NULL;
}

template<class ItemType>
NodeType<ItemType>::NodeType(ItemType item) {
    data = item;
    next = NULL;
}

template<class ItemType>
NodeType<ItemType>::~NodeType() {
}

template<class ItemType>
NodeType<ItemType>::NodeType(const NodeType& other) {
    std::cout << "Node copy constructor" << std::endl;
    data = other.data;
    next = new ItemType;
    *next = *(other.next);
}

template<class ItemType>
void NodeType<ItemType>::operator=(const NodeType& other) {
    std::cout << "Node = " << std::endl;
    data = other.data;
    delete next;
    NodeType<ItemType> *next = new NodeType<ItemType>;
    *next = *(other.next);
}

#endif	/* NODETYPE_H */