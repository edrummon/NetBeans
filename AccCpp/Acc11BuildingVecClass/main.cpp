/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 28, 2014, 11:22 PM
 */

//#include <iostream>
#include "Vec.h"
#include "SimpleList.h"

using std::cout;            using std::endl;

int main(int argc, char** argv) {
    
    Vec<int> v;
    
    //testing the very basics
    cout << "Vec:" << endl;
    for (int i = 0; i < 20; ++i)
        v.push_back(i);
    
    for (Vec<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    
    cout << "\nSimpleList:" << endl;
    SimpleList<int> l;
    
    for (int i = 0; i < 20; ++i)
        l.push_back(i);

    SimpleList<int>::iterator iter = l.begin();
    
    for (; iter->next != NULL; ++iter)
        cout << iter->getData() << " ";
    cout << iter->getData();
    /*
    cout << iter->getData() << " " << iter->next->getData() << " " << 
            iter->next->next->getData() << " " << iter->next->next->next->getData();
    */
    return 0;
}