/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 13, 2014, 6:39 PM
 */

#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::vector;          using std::cout;
using std::string;          using std::endl;

bool not_url_char(char c) {
    static const string url_ch = "~;/?:@=$-_.+!*'(),";
    return !(isalnum(c) || 
            find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        
        if (i != b && i + sep.size() != e) {
            
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
            
            i += sep.size();
        }
    }
    return e;
}

vector<string> find_urls(const string& s) {
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    vector<string> ret;
    
    while (b != e) {
        b = url_beg(b, e);
        
        if (b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}

void print(const vector<string>& s) {
    for (auto iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << endl;
}

int main(int argc, char** argv) {
    
    string s = "type=\"application/rss+xml\" href=\"http://www.teamliquid.net/rss/news.xml\" title=\"Team L...\">";
    print(find_urls(s));

    return 0;
}