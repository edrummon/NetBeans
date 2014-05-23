/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 9, 2014, 4:49 PM
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;          using std::string;
using std::max;             using std::cout;
using std::endl;

size_t width(const vector<string>& v) {
    size_t maxLen = 0;
    for (size_t i = 0; i < v.size(); i++)
        maxLen = max(maxLen, v[i].size());
    return maxLen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    size_t maxLen = width(v);
    string border(maxLen + 4, '*');
    ret.push_back(border);
    
    for (size_t i = 0; i < v.size(); i++) {
        ret.push_back("* " + v[i] + string(maxLen - v[i].size(), ' ') + " *");
    }
    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bot) {
    vector<string> ret = top;
    ret.insert(ret.end(), bot.begin(), bot.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;
    size_t widthPad = width(left) + 1;
    size_t i = 0, j = 0;
    
    while (i != left.size() || j != right.size()) {
        string s;
        if (i != left.size())
            s += left[i++];
        else
            s += string(widthPad + 4, ' ');
        
        if (j != right.size())
            s += right[j++];
        ret.push_back(s);
    }
    return ret;
}

vector<string> center(const vector<string>& s) {
    vector<string> ret;
    string border(80, '*');
    ret.push_back(border);
    
    for (size_t i = 1; i < s.size()-1; i++) {
        string next = s[i];
        size_t index1 = 1, index2 = 1;
        while (isspace(next[index1]))
            index1++, index2++;
        while (next[index2] != '*')
            index2++;
        index2--;
        while (isspace(next[index2]))
            index2--;
        string toPush = next.substr(index1, index2-index1+1);
        int pad = (80 - toPush.size() - 2) / 2;
        ret.push_back("*" + string(pad, ' ') + toPush + string(pad, ' ') + string(toPush.size() % 2, ' ') + "*");
    }
    ret.push_back(border);
    return ret;
}

void printFrame(const vector<string>& v) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}

int main(int argc, char** argv) {

    vector<string> s = {"time to", "test this", "frame thing"};
    vector<string> t = {"in a couple", "different ways", "methinks"};
    vector<string> print = frame(s);
    vector<string> print2 = frame(t);
    vector<string> vertical = vcat(print, print2);
    vector<string> horizontal = hcat(print, print2);
    vector<string> centered = center(print);
    
    printFrame(centered);
    
    return 0;
}