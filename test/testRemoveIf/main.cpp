/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 12, 2014, 9:39 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

bool isOdd(int i) {return i%2==1;}
bool isEven(int i) {return i%2==0;}

int main(int argc, char** argv) {
    
    vector<int> v = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9};
    vector<int> odds;
    
    //remove_copy_if(v.begin(), v.end(), back_inserter(odds), isEven);
    //remove_if(v.begin(), v.end(), isOdd);
    auto x = remove(v.begin(), v.end(), 4);
    //partition(v.begin(), v.end(), isOdd);
    //stable_partition(v.begin(), v.end(), isOdd);
    
    for (auto iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << *x << " " << *(x+1);

    return 0;
}