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
    
    Str s = "Hello, world";
    cout << s << endl;
    //s += ". I am a Str.";
    s = s + " more words!"; //fails program unless i have cout << endl; in the non-default constructor o_O
    cout << s << endl;

    std::string z = " blobby blob";
    s += Str(z.begin()+7, z.begin()+12);
    cout << s << endl;
    
    Str b("relational op tests");
    cout << (s > b) << " " << (s >= b) << " " << (b < s) << " " << (b <= s) << endl;
    
    cout << b << endl;
    cin >> b;
    cout << b << endl;
    
    cout << (b == s) << " " << (b != s) << endl;

    return 0;
}