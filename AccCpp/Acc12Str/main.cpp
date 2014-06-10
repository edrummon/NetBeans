/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 5, 2014, 7:23 PM
 */

#include "Str.h"

using std::cout;            using std::endl;
using std::cin;

int main(int argc, char** argv) {

    Str s = "Here is s";
    Str b("this is b");
    
    cout << s << endl << b.c_str() << endl;
    
    cin >> b;
    cout << b.c_str() << endl;
    
    for (Str::const_iterator it = s.begin(); it != s.end(); ++it)
        cout << *it;
    cout << endl;
    
    cin.get();
    Str line;
    Str::getline(cin, line);
    cout << line;

    return 0;
}