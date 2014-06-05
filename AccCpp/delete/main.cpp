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
    
    for (list_const_iter iter = x.begin(); iter != x.end(); ++iter)
        cout << *iter << " ";

    return 0;
}