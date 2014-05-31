/* 
 * File:   SimpleList.h
 * Author: Instinct212
 *
 * Created on May 29, 2014, 8:37 PM
 */

#ifndef SIMPLELIST_H
#define	SIMPLELIST_H

#include <iostream>

template<class T>
class SimpleList {
public:
    
    struct Node {
        Node(): next(NULL) {}
        Node(const T& newData): data(newData), next(NULL) {}
        Node(const Node&);
        ~Node();
        Node& operator=(const Node&);
        
        T& getData() { return data; }
        const T& getData() const { return data; }
        
        Node& operator++() { std::cout << "in ++ "; this = this->next; return *this; }
        const Node& operator++() const { std::cout << "in ++ "; this = this->next; return *this; }
        
        T operator*() { return data; }
        const T operator*() const { return data; }
        
        T data;
        Node* next;
    };
    
    typedef typename SimpleList::Node* iterator;
    typedef const typename SimpleList::Node* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    
    SimpleList();
    SimpleList(const SimpleList&);
    ~SimpleList();
    SimpleList& operator=(const SimpleList&);
    
    void push_back(const T&);
    void insert(iterator, const T&);
    //iterator erase(iterator);
    
    bool empty() const { return head == NULL; }
    
    iterator begin() { return head; }
    const_iterator begin() const { return head; }
private:
    Node* head;
};

template<class T>
SimpleList<T>::SimpleList() {
    head = NULL;
}

template<class T>
SimpleList<T>::SimpleList(const SimpleList& s) {
    head = new Node;
    *head = *(s.head);
}

template<class T>
SimpleList<T>::~SimpleList() {
    delete head; //maybe delete nodes in reverse instead?
}

template<class T>
SimpleList<T>& SimpleList<T>::operator=(const SimpleList& rhs) {
    if (&rhs != this) {
        delete head;
        head = new Node;
        *head = rhs->head;
    }
    return *this;
}

template<class T>
void SimpleList<T>::push_back(const T& val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* findEnd = head;
        while (findEnd->next != NULL)
            findEnd = findEnd->next;
        findEnd->next = newNode;
    }
}

template<class T>
void SimpleList<T>::insert(iterator it, const T& val) {
    Node* newNext = it->next;
    Node* newNode = new Node(val);
    it->next = newNode;
    newNode->next = newNext;
}

template<class T>
SimpleList<T>::Node::Node(const Node& n) {
    next = new Node;
    *next = *(n.next);
    data = n.data;
}

template<class T>
SimpleList<T>::Node::~Node() {
    delete next;
}

template<class T>
typename SimpleList<T>::Node& SimpleList<T>::Node::operator=(const Node& rhs) {
    if (&rhs != this) {
        delete next;
        Node* next = new Node;
        *next = *(rhs.next);
        data = rhs.data;
    }
    return *this;
}

#endif	/* SIMPLELIST_H */