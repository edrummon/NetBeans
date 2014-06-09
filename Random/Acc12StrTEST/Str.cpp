#include "Str.h"

using std::istream;     using std::ostream;

istream& operator>>(istream& is, Str& s) {
    delete[] s.data;
    s.data = nullptr;
    s.length = s.limit = 0;
    
    char c;
    while (is.get(c) && isspace(c)) ;

    if (is) {
        do s.push_back(c);
        while (is.get(c) && !isspace(c));
        
        if (is)
            is.unget();
    }
    return is;
}

Str::Str(size_type n, char c) {
    limit = length = n;
    data = new char[length];
    for (int i = 0; i != length; ++i)
        data[i] = c;
}

Str::Str(const char* cp) {
    limit = length = std::strlen(cp);
    data = new char[length];
    for (size_type i = 0; i != length; ++i)
        data[i] = cp[i];
}

Str::Str(const Str& s) {
    length = s.length;
    limit = s.limit;
    data = new char[limit];
    for (size_type i = 0; i < length; ++i)
        data[i] = s[i];
}

Str& Str::operator=(const Str& rhs) {
    if (&rhs != this) {
        delete[] data;
        limit = rhs.limit;
        length = rhs.length;
        data = new char[limit];
        for (size_type i = 0; i < length; ++i)
            data[i] = rhs[i];
    }
    return *this;
}

Str& Str::operator+=(const Str& s) {
    if (length + s.length > limit) {
        int newLength = length + s.length;
        int newLimit = newLength;
        char* newData = new char[newLimit];

        for (size_type i = 0; i < length; ++i)
            newData[i] = data[i];
        for (size_type i = 0; i < s.length; ++i)
            newData[i + length] = s[i];

        delete[] data;
        length = newLength;
        limit = newLimit;
        data = newData;
    } else {
        for (size_type i = 0; i < s.length; ++i)
            data[length+i] = s[i];
        length += s.length;
    }
    return *this;
}

bool Str::operator==(const Str& s) {
    return data == s.data && length == s.length && limit == s.limit;
}

bool Str::operator!=(const Str& s) {
    return !(*this == s);
}

Str& Str::operator+(const char* s) {
    int sLength = std::strlen(s);
    for (int i = 0; i < sLength; ++i)
        push_back(s[i]);
    
    return *this;
}

int Str::strcmp(const Str& s, const Str& t) {
    if (s.data < t.data)
        return -1;
    else if (s.data == t.data)
        return 0;
    else
        return 1;
}

void Str::push_back(char c) {
    if (length == limit) {
        limit = std::max(limit*2, 1);
        char* newData = new char[limit];

        for (size_type i = 0; i < length; ++i)
            newData[i] = data[i];
        
        delete[] data;
        data = newData;
    }
    data[length++] = c;
}

ostream& operator<<(ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

//Str operator+(const Str& s, const Str& t) {
//    Str r = s;
//    r += t;
//    return r;
//}

bool operator>(const Str& s, const Str& t) {
    return (Str::strcmp(s, t) == 1) ? true : false;
}

bool operator<(const Str& s, const Str& t) {
    return (Str::strcmp(s, t) == -1) ? true : false;
}

bool operator>=(const Str& s, const Str& t) {
    return (Str::strcmp(s, t) > -1) ? true : false;
}

bool operator<=(const Str& s, const Str& t) {
    return (Str::strcmp(s, t) < 1) ? true : false;
}
