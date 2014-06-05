/* 
 * File:   Num.h
 * Author: Instinct212
 *
 * Created on May 30, 2014, 10:29 PM
 */

#ifndef NUM_H
#define	NUM_H

#include <iostream>

using std::cout;
using std::endl;

struct Node {
    Node() : data(1), next(NULL) {}

    Node(const int newData) : data(newData), next(NULL) {}

    const int getData() const { return this->data; }
    int getData() { return this->data; }
    
    bool operator !=(const Node& rhs) const {
        return data != rhs.data;
    }
    
    const int data;
    Node* next;
};

struct list_const_iter {
    list_const_iter(): nodeIter() {}
    
    list_const_iter(Node* n): nodeIter(n) {}
    
    list_const_iter& operator++() {
        nodeIter = nodeIter->next;
        return *this;
    }
    
    const int operator*() const {
        return nodeIter->data;
    }
    
    bool operator !=(const list_const_iter& rhs) const {
        return nodeIter != rhs.nodeIter;
    }
    
private:
    const Node* nodeIter;
};

class NumList {
public:
    typedef list_const_iter const_iterator;
    
    NumList(): head(NULL) {}
    
    void push_back(int x) {
        Node* newNum = new Node(x);
        if (head == NULL) {
            head = newNum;
        } else {
            Node* findEnd = head;
            while (findEnd->next != NULL)
                findEnd = findEnd->next;
            findEnd->next = newNum;
        }
    }
    
    const_iterator begin() const { return const_iterator(head); }
    
    const_iterator end() const {
        Node *findEnd = head;
        while (findEnd != NULL)
            findEnd = findEnd->next;
        return const_iterator(findEnd);
    }
    
private:
    Node* head;
};

#endif	/* NUM_H */