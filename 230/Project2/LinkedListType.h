/* 
 * File:   LinkedListType.h
 * Author: Instinct
 *
 * Created on February 7, 2014, 5:31 PM
 */

#ifndef LINKEDLISTTYPE_H
#define	LINKEDLISTTYPE_H

#include "NodeType.h"
#include <cstdlib>
#include <iostream>

template<class ItemType>
class LinkedListType {
public:
    LinkedListType();
    ~LinkedListType();
    LinkedListType(const LinkedListType& other);
    bool isEmpty() const;
    void addNode(ItemType newItem);
    void remove(ItemType *item);
    void findPosition(NodeType<ItemType> *&itemPoint, ItemType *&itemToFind, bool startedYet);
    void iterate(NodeType<ItemType> *&item, ItemType *&itemToPrint, bool startedYet);

    void operator=(const LinkedListType& other);
private:
    NodeType<ItemType> *head;
};

template<class ItemType>
LinkedListType<ItemType>::LinkedListType() {
    head = NULL;
}

template<class ItemType>
LinkedListType<ItemType>::~LinkedListType() {
    NodeType<ItemType> *current = head;
    while (current != NULL) {
        head = current->next;
        delete current;
        current = head;
    }
}

template<class ItemType>
LinkedListType<ItemType>::LinkedListType(const LinkedListType& other) {
    head = new ItemType;
    *head = *(other.head);
}

template<class ItemType>
bool LinkedListType<ItemType>::isEmpty() const {
    return (head == NULL);
}

template<class ItemType>
void LinkedListType<ItemType>::addNode(ItemType newItem) {
    NodeType<ItemType> *newNode = new NodeType<ItemType>(newItem);
    if (head == NULL) {
        head = newNode;
    } else if ((newNode->data) > (head->data)) {
        newNode->next = head;
        head = newNode;
    } else {
        NodeType<ItemType> *findEnd;
        NodeType<ItemType> *trail;
        findEnd = head->next;
        trail = head;
        bool placed = false;
        while ((findEnd != NULL) && !placed) {
            if ((newNode->data) > (findEnd->data)) {
                trail->next = newNode;
                newNode->next = findEnd;
                placed = true;
            }
            trail = findEnd;
            findEnd = findEnd->next;
        }
        if (!placed) {
            trail->next = newNode;
        }
    }
}

template<class ItemType>
void LinkedListType<ItemType>::remove(ItemType *item) {
    *item = head->data;
    NodeType<ItemType> *temp = head->next;
    delete head;
    head = temp;
}

template<class ItemType>
void LinkedListType<ItemType>::findPosition(NodeType<ItemType> *&itemPoint, ItemType *&itemToFind, bool startedYet) {
    if (!startedYet) {
        itemPoint = head;
        *itemToFind = head->data;
    } else {
        if (itemPoint->next != NULL) {
            itemPoint = itemPoint->next;
            *itemToFind = itemPoint->data;
        } else {
            itemPoint = NULL;
        }
    }
}

template<class ItemType>
void LinkedListType<ItemType>::iterate(NodeType<ItemType> *&item, ItemType *&itemToPrint, bool startedYet) {
    if (!startedYet) {
        item = head;
        *itemToPrint = head->data;
    } else {
        if (item->next != NULL) {
            item = item->next;
            *itemToPrint = item->data;
        } else {
            item = NULL;
        }
    }
}

template<class ItemType>
void LinkedListType<ItemType>::operator=(const LinkedListType& other) {
    delete head;
    head = new NodeType<ItemType>;
    *head = *(other.head);
}

#endif	/* LINKEDLISTTYPE_H */