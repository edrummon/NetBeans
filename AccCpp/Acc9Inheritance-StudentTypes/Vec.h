/* 
 * File:   Vec.h
 * Author: Instinct212
 *
 * Created on May 28, 2014, 11:22 PM
 */

#ifndef VEC_H
#define	VEC_H

#include <memory>

using std::allocator;           using std::uninitialized_fill;
using std::max;                 using std::uninitialized_copy;

template<class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    
    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }
    
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    
    void push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }
    void clear();
    iterator erase(const_iterator);
    iterator erase(const_iterator, const_iterator);
    
    size_type size() const { return avail - data; }
    bool empty() const { return data == avail; }
    
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
private:
    iterator data;
    iterator avail;
    iterator limit;
    
    allocator<T> alloc;
    
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    
    void uncreate();
    
    void grow();
    void unchecked_append(const T&);
};

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<class T>
void Vec<T>::clear() {
    if (data) {
        iterator it = avail;
        while (avail != data)
            alloc.destroy(--avail);
    }
    data = avail = 0;
}

template<class T>
typename Vec<T>::iterator Vec<T>::erase(const_iterator eraserIt) {
    iterator ret = eraserIt;
    iterator nextIt = eraserIt + 1;
    alloc.destroy(eraserIt);
    while (nextIt != avail) {
        alloc.construct(eraserIt++, *nextIt);
        alloc.destroy(nextIt++);
    }
    --avail;
    return ret;
}

template<class T>
typename Vec<T>::iterator Vec<T>::erase(const_iterator beg, const_iterator end) {
    iterator ret = beg;
    iterator nextIt = beg;
    while (beg != end)
        alloc.destroy(beg++);
    while (end != avail) {
        alloc.construct(nextIt++, *end);
        alloc.destroy(end++);
    }
    avail -= (end - beg);
    return ret;
}

template<class T>
void Vec<T>::create() { data = avail = limit = 0; }

template<class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator begin, const_iterator end) {
    data = alloc.allocate(end - begin);
    limit = avail = uninitialized_copy(begin, end, data);
}

template<class T>
void Vec<T>::uncreate() {
    if (data) {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::grow() {
    size_type new_size = max(2*(limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

#endif	/* VEC_H */