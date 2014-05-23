/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 21, 2014, 5:34 PM
 */

#include <iostream>
#include <ostream>
#include <iterator>
#include <map>
#include "split.h"

using std::cout;        using std::cin;
using std::map;         using std::endl;
using std::string;      using std::vector;
using std::getline;     using std::istream;

//very broken, confusing AccCpp question
template<class Out>
void xref(istream& in, Out os) {
    
    string line;
    int line_number = 0;
    
    while (getline(in, line)) {
        ++line_number;
        vector<string> words;
        split(line, std::back_inserter(words));
        
        for (auto iter = words.begin(); iter != words.end(); ++iter)
            *os++ = *iter;
    }
}

bool compareValue(const std::pair<string, int>& a, const std::pair<string, int>& b) {
    return a.second > b.second;
}

int main(int argc, char** argv) {
    
    xref(cin, std::ostream_iterator<string>(cout, " "));
//    vector<string> words;
//    string str = "here are some words to split up";
//    split(str, std::back_inserter(words));
//    
//    for (auto &i : words)
//        cout << i << "\n";
    
    return 0;
}