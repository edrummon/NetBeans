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
    /*
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    */
    if (n < 0)
        n *= -1;
    if (n > RAND_MAX)
        n %= RAND_MAX;
    
    const int bucket_size = RAND_MAX / n;
    int ret;
    
    do ret = rand() / bucket_size;
    while (ret >= n);
    
    return ret;
}

Rule findRule(const Grammar& g, const string& word) {
    Grammar::const_iterator it = g.find(word);
    if (it == g.end())
        throw logic_error("empty rule");

    const Rule_Collection& rc = it->second;
    return rc[nrand(rc.size())];
}

void gen_aux(const Grammar& g, const string& word, vector<string>& sentence) {
    Rule_Collection rules;

    const Rule r = findRule(g, word);
    rules.push_back(r);
    
    while (!rules.empty()) {
        const Rule newRule = rules.back();
        rules.pop_back();
        
        for (Rule::const_reverse_iterator iter = newRule.rbegin(); iter != newRule.rend(); ++iter) {
            if (!bracketed(*iter)) {
                for (Rule::const_iterator i = newRule.begin(); i != newRule.end(); ++i) {
                    if (!bracketed(*i))
                        sentence.push_back(*i);
                }
                iter = newRule.rend() - 1;
            } else {
                const Rule r = findRule(g, *iter);
                rules.push_back(r);
            }
        }
    }
}

vector<string> gen_sentence(const Grammar& g) {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
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
        vector<string> rand_sent = gen_sentence(g);
        print(rand_sent);
    }

    return 0;
}