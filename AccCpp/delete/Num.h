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

class NumList {
public:
    
    struct Node {
        Node(): data(1), next(NULL) {}
        Node(const int newData): data(newData), next(NULL) {}
        
        int getData() { return this->data; }
        
        Node*& operator++() { cout << " in ++ " << endl; return this->next; }
        
        int data;
        Node* next;
    };
    
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
    
    Node*& begin() { return head; }
    
private:
    Node* head;
};

#endif	/* NUM_H */