/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 9, 2014, 4:49 PM
 */

#include <vector>
#include "Str.h"

using std::vector;          
using std::max;             using std::cout;
using std::endl;

size_t width(const vector<Str>& v) {
    size_t maxLen = 0;
    for (size_t i = 0; i < v.size(); i++)
        maxLen = max(maxLen, v[i].size());
    return maxLen;
}

vector<Str> frame(const vector<Str>& v) {
    vector<Str> ret;
    size_t maxLen = width(v);
    Str border(maxLen + 4, '*');
    ret.push_back(border);
    
    for (size_t i = 0; i < v.size(); i++) {
        ret.push_back("* " + v[i] + Str(maxLen - v[i].size(), ' ') + " *");
    }
    ret.push_back(border);
    return ret;
}

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bot) {
    vector<Str> ret = top;
    ret.insert(ret.end(), bot.begin(), bot.end());
    return ret;
}

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right) {
    vector<Str> ret;
    size_t widthPad = width(left) + 1;
    size_t i = 0, j = 0;
    
    while (i != left.size() || j != right.size()) {
        Str s;
        if (i != left.size())
            s += left[i++];
        else
            s += Str(widthPad + 4, ' ');
        
        if (j != right.size())
            s += right[j++];
        ret.push_back(s);
    }
    return ret;
}

vector<Str> center(const vector<Str>& s) {
    vector<Str> ret;
    Str border(80, '*');
    ret.push_back(border);
    
    for (size_t i = 1; i < s.size()-1; i++) {
        Str next = s[i];
        size_t index1 = 1, index2 = 1;
        while (isspace(next[index1]))
            index1++, index2++;
        while (next[index2] != '*')
            index2++;
        index2--;
        while (isspace(next[index2]))
            index2--;
        Str toPush = next.substr(index1, index2-index1+1);
        int pad = (80 - toPush.size() - 2) / 2;
        ret.push_back("*" + Str(pad, ' ') + toPush + Str(pad, ' ') + Str(toPush.size() % 2, ' ') + "*");
    }
    ret.push_back(border);
    return ret;
}

void printFrame(const vector<Str>& v) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}

int main(int argc, char** argv) {

    vector<Str> s = {"time to", "test this", "frame thing"};
    vector<Str> t = {"in a couple", "different ways", "methinks"};
    vector<Str> print = frame(s);
    vector<Str> print2 = frame(t);
    vector<Str> vertical = vcat(print, print2);
    vector<Str> horizontal = hcat(print, print2);
    vector<Str> centered = center(print);
    
    printFrame(centered);
    printFrame(vertical);
    printFrame(horizontal);
    
    return 0;
}