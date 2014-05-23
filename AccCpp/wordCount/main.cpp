/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 14, 2014, 9:45 PM
 */

#include <iostream>
#include <map>
#include "split.h"

using std::cout;        using std::cin;
using std::map;         using std::endl;
using std::string;      using std::vector;
using std::getline;     using std::istream;

map<string, vector<int> > 
xref(istream& in, vector<string> find_words(const string& s) = split) {
    
    map<string, vector<int> > ret;
    string line;
    int line_number = 0;
    
    while (getline(in, line)) {
        ++line_number;
        vector<string> words = find_words(line);
        
        for (auto iter = words.begin(); iter != words.end(); ++iter) {
            if (ret[*iter].empty() || ret[*iter].back() != line_number)
                ret[*iter].push_back(line_number);
        }
    }
    return ret;
}

bool compareValue(const std::pair<string, int>& a, const std::pair<string, int>& b) {
    return a.second > b.second;
}

int main(int argc, char** argv) {
    
    map<string, vector<int> > counter = xref(cin);
    
    for (auto it = counter.begin(); it != counter.end(); ++it) {
        cout << it->first << " occurs on line";
        it->second.size() == 1 ? cout << ": " : cout << "s: ";
        
        auto it2 = it->second.begin();
        cout << *it2++;
        
        int lineCounter = 0;
        while (it2 != it->second.end()) {
            cout << ", " << *it2++;
            lineCounter++;
            if (lineCounter >= 10 && it2 != it->second.end()) {
                cout << endl << *it2++;
                lineCounter = 1;
            }
        }   
        cout << endl;
    }
    /*
    string s;
    map<string, int> counter;
    
    while (cin >> s)
        ++counter[s];
    
    for (auto it = counter.begin(); it != counter.end(); ++it)
        cout << it->first << ": " << it->second << endl;
    
    cout << "\nsorted: \n";
    vector<std::pair<string,  int> > counterSorted;
    
    for (auto it = counter.begin(); it != counter.end(); ++it)
        counterSorted.push_back(*it);
    std::sort(counterSorted.begin(), counterSorted.end(), compareValue);
    
    for (auto it = counterSorted.begin(); it != counterSorted.end(); ++it)
        cout << it->first << ": " << it->second << endl;
    */
    return 0;
}