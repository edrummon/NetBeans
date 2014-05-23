/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on April 15, 2014, 12:28 AM
 */
#include <iostream>
#include <set>

int main(int argc, char** argv) {
    
    std::set<int> s;
    s.insert(15);
    s.insert(7);
    s.insert(28);
    s.insert(3);
    s.insert(1);
    s.insert(89);
    
    for (std::set<int>::iterator i = s.begin(); i != s.end(); i++)
        std::cout << *i << std::endl;

    return 0;
}