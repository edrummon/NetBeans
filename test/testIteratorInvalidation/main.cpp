/* 
 * File:   main.cpp
 * Author: Instinct
 *
 * Created on March 26, 2014, 7:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    
    vector<int> v;
    cout << "Capacity: " << v.capacity() << "   Size: " << v.size() << endl;
    v.reserve(10);
    
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    
    cout << "Capacity: " << v.capacity() << "   Size: " << v.size() << endl;
    
    auto x = v.begin();
    
    for (; x != v.end(); x++) {
        cout << *x << endl;
    }
    
    cout << endl << "RESIZE" << endl << endl;
    
    for (int i = 10; i < 20; i++)
        v.push_back(i);
    
    cout << "Capacity: " << v.capacity() << "   Size: " << v.size() << endl;
    
    for (x = v.begin(); x != v.end(); x++) {
        cout << *x << endl;
    }
    
    cout << endl << "RESIZE 2" << endl << endl;
    
    for (int i = 20; i < 200; i++)
        v.push_back(i);
    
    cout << "Capacity: " << v.capacity() << "   Size: " << v.size() << endl;
    
    for (x = v.begin(); x != v.end(); x++) {
        cout << *x << endl;
    }
    
    cout << endl << "REMOVES" << endl << endl;
    
    v.erase(v.begin());
    v.pop_back();
    v.erase(v.begin() + 17);
    
    cout << "Capacity: " << v.capacity() << "   Size: " << v.size() << endl;
    
    for (x = v.begin(); x != v.end(); x++) {
        cout << *x << endl;
    }

    return 0;
}