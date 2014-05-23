#include <iostream>
#include <iomanip>

using std::cout;        using std::endl;
using std::setw;        using std::cin;

int main(int argc, char** argv) {
    int max, digits = 1, base = 10;
    cout << "max: ";
    cin >> max;
    cout << "\n";
    while (true) {
        if (max / base >= 1) {
            digits++;
            base *= 10;
        } else {
            break;
        }
    }
    
    for (long long i = 1; i < max+1; i++) {
        cout << setw(digits+1) << i << setw(digits*2) << i * i << endl;
    }

    return 0;
}