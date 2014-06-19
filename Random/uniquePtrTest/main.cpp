/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 19, 2014, 2:48 AM
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    vector<unique_ptr<int> > v;
    
    for (int i = 0; i != 10; ++i) {
        v.push_back(unique_ptr<int>(new int(i)));
    }
    
    for (auto &i : v) {
        cout << *i << " ";
    }
    cout << endl;
    
    v[5].reset();
    
    for (int i = 0; i < 5; ++i)
        cout << *v[i] << " ";

    return 0;
}