/* 
 * File:   Str.h
 * Author: Instinct212
 *
 * Created on June 5, 2014, 7:24 PM
 */

#ifndef STR_H
#define	STR_H

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

class Str {
    friend std::istream& operator>> (std::istream&, Str&);
public:
    typedef size_t size_type;
    typedef char* iterator;
    typedef const char* const_iterator;
    
    Str(): length(0), limit(0), data(nullptr) {}
    Str(size_type, char);
    Str(const char*);

    template<class In> Str(In b, In e) {
        length = limit = e - b;
        data = new char[length];
        int i = 0;
        while (b != e)
            data[i++] = *b++;
    }
    
    ~Str() { delete[] data; }
    Str(const Str&);
    
    Str& operator=(const Str&);
    Str& operator+=(const Str&);
    bool operator==(const Str&);
    bool operator!=(const Str&);
    
    Str& operator+(const char*);
    
    static std::istream& getline(std::istream&, Str&);
    
    bool isEmpty() const { return length == 0; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    
    iterator end() { return data + length; }
    const_iterator end() const { return data + length; }
    
    static int strcmp(const Str&, const Str&);
    
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    
    size_type size() const { return length; }
    
    const char* c_str() const { return data; }
    const char* dataFunc() const { return data; }
    
    void push_back(char);
    void insert(const_iterator, const_iterator);
    
private:
    char* data;
    int limit, length;
};

std::ostream& operator<<(std::ostream&, const Str&);
//Str operator+(const Str&, const Str&);

bool operator>(const Str&, const Str&);
bool operator<(const Str&, const Str&);
bool operator>=(const Str&, const Str&);
bool operator<=(const Str&, const Str&);

#endif	/* STR_H */