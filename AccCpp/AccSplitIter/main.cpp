/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 10, 2014, 5:17 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;        using std::endl;
using std::vector;      using std::string;

bool not_space(char c) {
    return !isspace(c);
}

bool space(char c) {
    return isspace(c);
}

vector<string> split(const string& s) {
    typedef string::const_iterator iter;
    
    iter wordBegin = s.begin();
    vector<string> ret;
    
    while (wordBegin != s.end()) {
        wordBegin = find_if(wordBegin, s.end(), not_space);
        iter wordEnd = find_if(wordBegin, s.end(), space);
        
        if (wordBegin != wordEnd)
            ret.push_back(string(wordBegin, wordEnd));
        wordBegin = wordEnd;
    }
    return ret;
}

void print(const vector<string>& words) {
    for (auto i = words.begin(); i != words.end(); ++i)
        cout << *i << endl;
}

int main(int argc, char** argv) {
    
    string stuff = {"Hello there, I am a string which contains"
            " words and spaces! Time to split, LOL!"};
    
    vector<string> toPrint = split(stuff);
    print(toPrint);

    return 0;
}