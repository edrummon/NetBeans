/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 14, 2014, 8:20 PM
 */

#include <iostream>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <time.h>
#include <algorithm>
#include "split.h"

using std::cout;            using std::string;
using std::endl;            using std::map;
using std::vector;          using std::cin;
using std::getline;         using std::istream;
using std::logic_error;     using std::domain_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, Rule_Collection> Grammar;

Grammar read_grammar(istream& in) {
    Grammar ret;
    string line;
    
    while (getline(in, line)) {
        vector<string> entry = split(line);
        if (!entry.empty()) {
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}

bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int ret;
    
    do ret = rand() / bucket_size;
    while (ret >= n);
    
    return ret;
}

template<class Out>
void gen_aux(const Grammar& g, const string& word, Out sentence) {
    if (!bracketed(word)) {
        *sentence++ = word;
    } else {
        Grammar::const_iterator iter = g.find(word);
        if (iter == g.end())
            throw logic_error("empty rule");
        
        const Rule_Collection& rc = iter->second;
        const Rule& r = rc[nrand(rc.size())];
        
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, sentence);
    }
}

template<class Out>
void gen_sentence(const Grammar& g, Out os) {
    gen_aux(g, "<sentence>", os);
}

void print(vector<string>& sent) {
    vector<string>::const_iterator i = sent.begin();
    if (!sent.empty())
        cout << *i++;
    while (i != sent.end())
        cout << " " << *i++;
    cout << endl;
}

int main(int argc, char** argv) {
    
    Grammar g = read_grammar(cin);
    
    cout << endl;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        vector<string> rand_sent;
        gen_sentence(g, std::back_inserter(rand_sent));
        print(rand_sent);
    }

    return 0;
}