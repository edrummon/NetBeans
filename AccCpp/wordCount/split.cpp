#include "split.h"

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