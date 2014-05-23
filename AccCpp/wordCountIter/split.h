/* 
 * File:   split.h
 * Author: Instinct212
 *
 * Created on May 15, 2014, 8:03 PM
 */

#ifndef SPLIT_H
#define	SPLIT_H

#include <string>
#include <vector>
#include <algorithm>

bool space(char c) {return isspace(c);}
bool not_space(char c) {return !isspace(c);}

template<class Out>
void split(const std::string& s, Out os) {
    typedef std::string::const_iterator iter;
    
    iter wordBegin = s.begin();
    std::vector<std::string> ret;
    
    while (wordBegin != s.end()) {
        wordBegin = std::find_if(wordBegin, s.end(), not_space);
        iter wordEnd = std::find_if(wordBegin, s.end(), space);
        
        if (wordBegin != wordEnd)
            *os++ = std::string(wordBegin, wordEnd);
        wordBegin = wordEnd;
    }
}

#endif	/* SPLIT_H */

