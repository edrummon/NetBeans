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
    Str b("And here is b");
    
    cout << s << endl << b << endl;
    
    Str x = "Finally we have x";
    cout << x << endl;
    cin >> x;
    cout << x << endl << endl;
    
    cin >> b;
    cout << b << endl;

    return 0;
}