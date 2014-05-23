/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 21, 2014, 4:56 PM
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;        using std::endl;
using std::vector;      using std::sort;

template<class T>
void swap2(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class Ran>
double median(Ran begin, Ran end) {
    size_t size = end - begin;
    sort(begin, end);
    Ran mid = begin + size / 2;
    
    return size % 2 == 0 ? (*mid + *(mid+1)) / 2 : *mid;
}

int main(int argc, char** argv) {
    
    //vector<double> v = {2, 7, 54, 12, 87, 45, 23, 876, 23, 4, 7};
    //cout << median(v.begin(), v.end());
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    swap2(*(v.begin()), *(v.end()-1));
    
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    return 0;
}