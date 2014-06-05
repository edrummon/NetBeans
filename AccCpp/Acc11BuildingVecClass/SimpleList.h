/* 
 * File:   SimpleList.h
 * Author: Instinct212
 *
 * Created on May 29, 2014, 8:37 PM
 */

#ifndef SIMPLELIST_H
#define	SIMPLELIST_H

template<class T>
struct Node {

    Node() : next(NULL) { }
    Node(const T& newData) : data(newData), next(NULL) {}
    Node(const Node&);
    ~Node();
    
    Node& operator=(const Node&);

    T& getData() { return data; }

    const T& getData() const { return data; }

    bool operator!=(const Node& rhs) const {
        return data != rhs.data;
    }

    const T data;
    Node* next;
};

template<class T>
struct list_iterator {
    list_iterator(): itNode() {}
    list_iterator(Node<T>* n): itNode(n) {}
    
    list_iterator& operator++() {
        itNode = itNode->next;
        return *this;
    }
    T operator*() { return itNode->data; }
    bool operator!=(const list_iterator& rhs) { return itNode != rhs.itNode; }
private:
    Node<T>* itNode;
};

template<class T>
struct list_const_iterator {
    list_const_iterator(): itNode() {}
    list_const_iterator(Node<T>* n): itNode(n) {}
    
    list_const_iterator& operator++() {
        itNode = itNode->next;
        return *this;
    }
    const T operator*() const { return itNode->data; }
    bool operator !=(const list_const_iterator& rhs) const { return itNode != rhs.itNode; }
private:
    const Node<T>* itNode;
};

template<class T>
class SimpleList {
public:
    
    typedef size_t size_type;
    typedef T value_type;
    
    SimpleList();
    SimpleList(const SimpleList&);
    ~SimpleList();
    SimpleList& operator=(const SimpleList&);
    
    void push_back(const T&);
    void insert(list_iterator<T>, const T&);
    //iterator erase(iterator);
    
    bool empty() const { return head == NULL; }
    
    //list_iterator<T> begin() { return list_iterator<T>(head); }
    list_const_iterator<T> begin() const { return list_const_iterator<T>(head); }
    
//    list_iterator<T> end() {
//        Node<T>* findEnd = head;
//        while (findEnd != NULL)
//            findEnd = findEnd->next;
//        return list_iterator<T>(findEnd);
//    }
    list_const_iterator<T> end() const {
        Node<T>* findEnd = head;
        while (findEnd != NULL)
            findEnd = findEnd->next;
        return list_const_iterator<T>(findEnd);
    }
private:
    Node<T>* head;
};

template<class T>
SimpleList<T>::SimpleList() {
    head = NULL;
}

template<class T>
SimpleList<T>::SimpleList(const SimpleList& s) {
    head = new Node<T>;
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
        head = new Node<T>;
        *head = rhs->head;
    }
    return *this;
}

template<class T>
void SimpleList<T>::push_back(const T& val) {
    Node<T>* newNode = new Node<T>(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node<T>* findEnd = head;
        while (findEnd->next != NULL)
            findEnd = findEnd->next;
        findEnd->next = newNode;
    }
}

template<class T>
void SimpleList<T>::insert(list_iterator<T> it, const T& val) {
//    Node* newNext = it->next;
//    Node* newNode = new Node(val);
//    it->next = newNode;
//    newNode->next = newNext;
}

template<class T>
Node<T>::Node(const Node& n) {
    next = new Node;
    *next = *(n.next);
    data = n.data;
}

template<class T>
Node<T>::~Node() {
    delete next;
}

template<class T>
Node<T>& Node<T>::operator=(const Node& rhs) {
    if (&rhs != this) {
        delete next;
        Node* next = new Node;
        *next = *(rhs.next);
        data = rhs.data;
    }
    return *this;
}

#endif	/* SIMPLELIST_H */