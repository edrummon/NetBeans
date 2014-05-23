/* 
 * File:   queueType.h
 * Author: Instinct
 *
 * Created on February 11, 2014, 8:00 PM
 */

#ifndef QUEUETYPE_H
#define	QUEUETYPE_H
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

template<typename T> class QueueType;

template<typename T>
class Iter {
public:

    Iter(QueueType<T> *new_p_Queue, int nextPos)
    : pos(nextPos),
    p_Queue(new_p_Queue) {
    }

    bool operator !=(Iter& other) {
        return pos != other.pos;
    }
    T& operator*();
    Iter& operator++() {
        ++pos;
        return *this;
    }
private:
    int pos;
    QueueType<T> *p_Queue;
};

template<typename T>
class QueueType {
public:
    QueueType();
    ~QueueType();
    QueueType(const QueueType& other);

    T& get(int index) {return v[index];}
    Iter<T> begin() {return Iter<T>(this, 0);}
    Iter<T> end() {return Iter<T>(this, numElements);}

    int getNumElements() const {return numElements;}
    T& getFront() {return v.at(0);}
    void addElement(T);
    void removeElement();

    bool isEmpty() const {return numElements == 0;}
    bool isFull() const {return SIZE == numElements;}

    QueueType<T>& operator=(const QueueType other);

    friend void swap(QueueType& first, QueueType& second) {
        using std::swap;
        swap(first.numElements, second.numElements);
        swap(first.v, second.v);
    }
private:
    static const int SIZE = 25;
    int numElements;
    vector<T> v;
};

template<typename T>
T& Iter<T>::operator *() {
    return p_Queue->get(pos);
}

template<typename T>
QueueType<T>::QueueType() {
    v.reserve(SIZE);
    numElements = 0;
}

template<typename T>
QueueType<T>::~QueueType() {
}

template<typename T>
QueueType<T>::QueueType(const QueueType& other) :
v(vector<T> (SIZE)),
numElements(other.numElements) {
    std::copy(other.v, other.v + SIZE, v);
}

template<typename T>
void QueueType<T>::addElement(T newElement) {
    v.push_back(newElement);
    numElements++;
}

template<typename T>
void QueueType<T>::removeElement() {
    v.erase(v.begin());
    numElements--;
}

template<typename T>
QueueType<T>& QueueType<T>::operator=(const QueueType other) {
    swap(*this, other);
    return *this;
}
#endif	/* QUEUETYPE_H */