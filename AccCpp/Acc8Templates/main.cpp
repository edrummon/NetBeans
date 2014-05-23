/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 19, 2014, 5:43 PM
 */

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;              using std::cout;
using std::domain_error;        using std::sort;
using std::swap;                using std::endl;
using std::cin;                 using std::istream_iterator;
using std::ostream_iterator;    using std::string;

template<class T>
T median(vector<T>& v) {
    typedef typename vector<T>::size_type vec_size;
    
    vec_size size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(v.begin(), v.end());
    vec_size mid = v.size() / 2;
    
    return v.size() % 2 == 0 ? (v[mid] + v[mid+1]) / 2 : v[mid];
}

bool space(char c) {return isspace(c);}
bool not_space(char c) {return !isspace(c);}

template<class Out>
void split(const string& s, Out os) {
    typedef string::const_iterator iter;
    iter i = s.begin();
    
    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);
        
        if (i != s.end())
            *os++ = string(i, j);
        i = j;
    }
}

//using 2 so it doesn't confuse these with their built-in counterparts
template<class In, class X>
In find2(In begin, In end, const X& x) {
    while (begin != end && *begin != x) {
        ++begin;
    }
    return begin;
}

template<class In, class Out>
Out copy2(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template<class For, class X>
void replace2(For begin, For end, const X& x, const X& y) {
    while (begin != end) {
        if (*begin == x)
            *begin = y;
        ++begin;
    }
}

template<class Bi>
void reverse2(Bi begin, Bi end) {
    --end;
    if (begin != end) {
        swap(*begin++, *end);
        reverse2(begin, end);
    }
}

template<class Ran, class X>
bool binary_search2(Ran begin, Ran end, const X& x) {
    if (begin != end) {
        Ran mid = begin + (end - begin) / 2;
        
        if (x < *mid)
            return binary_search2(begin, mid, x);
        else if (*mid < x)
            return binary_search2(mid+1, end, x);
        else
            return true;
    }
    return false;
}

int main(int argc, char** argv) {
    
    //vector<double> dVec = {23.543, 6234.53, 123.3, 564.7653, 234.7654};
    //cout << median(dVec);
    
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin();
    while (it != v.end())
        cout << *it++ << " ";

    cout << endl << binary_search2(v.begin(), v.end(), 4) << endl;
    
    reverse2(v.begin(), v.end());
    
    it = v.begin();
    while (it != v.end())
        cout << *it++ << " ";
    cout << endl;
    
    vector<int> iVec;
    std::copy(istream_iterator<int>(cin), istream_iterator<int>(), std::back_inserter(iVec));
    std::copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " "));

    return 0;
}