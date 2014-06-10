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
    data = new char[length+1];
    for (int i = 0; i != length; ++i)
        data[i] = c;
    data[length] = '\0';
}

Str::Str(const char* cp) {
    limit = length = std::strlen(cp);
    data = new char[length+1];
    for (size_type i = 0; i != length; ++i)
        data[i] = cp[i];
    data[length] = '\0';
}

Str::Str(const Str& s) {
    length = s.length;
    limit = s.limit;
    data = new char[limit+1];
    for (size_type i = 0; i < length; ++i)
        data[i] = s[i];
    data[length] = '\0';
}

Str& Str::operator=(const Str& rhs) {
    if (&rhs != this) {
        delete[] data;
        limit = rhs.limit;
        length = rhs.length;
        data = new char[limit+1];
        for (size_type i = 0; i < length; ++i)
            data[i] = rhs[i];
        data[length] = '\0';
    }
    return *this;
}

Str& Str::operator+=(const Str& s) {
    if (length + s.length > limit) {
        int newLength = length + s.length;
        int newLimit = newLength;
        char* newData = new char[newLimit+1];

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
    data[length] = '\0';
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

istream& Str::getline(istream& is, Str& s) {
    while (is) {
        char c;
        is.get(c);
        s.push_back(c);
    }
    return is;
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
        char* newData = new char[limit+1];

        for (size_type i = 0; i != length; ++i)
            newData[i] = data[i];
        
        delete[] data;
        data = newData;
    }
    data[length++] = c;
    data[length] = '\0';
}

Str Str::substr(size_type a, size_type b) {
    Str ret;
    size_type i = 0;
    while (i++ != b)
        ret.push_back(data[a++]);
    return ret;
}

ostream& operator<<(ostream& os, const Str& s) {
    std::copy(s.begin(), s.end(), std::ostream_iterator<char>(os));
    return os;
}

Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

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

Str operator+(const char* cp, const Str s) {
    Str x(cp);
    x += s;
    return x;
}