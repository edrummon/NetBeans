/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 30, 2014, 10:29 PM
 */

#include "Num.h"

int main(int argc, char** argv) {
    
    NumList x;
    
    for (int a = 0; a < 20; ++a)
        x.push_back(a);
    
    NumList::Node* iter = x.begin();
    
    for (; iter != NULL; iter = iter->next)
        cout << iter->getData() << " ";
    
    iter = x.begin();
    cout << endl;
    int z = 0;
    for (; z != 20; ++iter, ++z)
        cout << iter->getData() << " ";

    return 0;
}