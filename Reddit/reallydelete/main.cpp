/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 4, 2014, 3:28 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    int** p = new int*[5];
    for (int i = 0; i < 5; ++i)
        p[i] = new int[10];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            p[i][j] = j;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    if (p[0][0] != 6 && p[0][0] != 7 && p[0][0] != 8)
        cout << "here" << endl;

    return 0;
}