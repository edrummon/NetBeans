/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 26, 2014, 12:16 AM
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <time.h>

using std::cout;            using std::endl;
using std::vector;

void simulateRolls(int numRolls) {
    vector<double> occurrences (6, 0.0);
    printf("%-11d", numRolls);
    
    for (int i = 0; i != numRolls; ++i) {
        occurrences[rand() % 6]++;
    }
    for (int i = 0; i != occurrences.size(); ++i) {
        printf("%5.2f", (occurrences[i] / numRolls) * 100);
        cout << "% ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    
    cout << "# of Rolls 1s     2s     3s     4s     5s     6s    \n";
    cout << "====================================================\n";
    
    srand(time(NULL));
    for (int rolls = 10; rolls <= 1000000; rolls*=10)
        simulateRolls(rolls);
    
    return 0;
}