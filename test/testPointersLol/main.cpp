#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *y = new int(0);
    int *z = new int;
    *z = x;
    int *q = new int;
    *q = 78;
    int *b = new int(444444);
    
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << endl;
    y = z;
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << endl;
    *z = 12;
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << endl;
    int *w (z);
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << "w: " << *w << endl << endl;
    *z = 24;
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << "w: " << *w << endl << endl;
    cout << "q: " << q << endl << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << "w: " << w << endl << endl;
    z = b;
    cout << "q: " << *q << endl << "x: " << x << endl << "y: " << *y << endl << "z: " << *z << endl << "w: " << *w << endl << endl;
    cout << "q: " << q << endl << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << "w: " << w << endl << endl;
    
    int pause;
    cin >> pause;
    return 0;
}