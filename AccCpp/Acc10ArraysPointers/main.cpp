/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 26, 2014, 7:52 PM
 */

#include <fstream>
#include <cstring>
#include "median.h"
#include "stringList.h"

using std::string;          using std::ifstream;
using std::cout;            using std::endl;
using std::cin;             using std::cerr;
using std::copy;            using std::vector;
using std::find_if;

int* pointer_to_static() {
    static int x;
    return &x;
}

int* pointer_to_dynamic() {
    return new int(42);
}

char* duplicateChars(const char* p) {
    size_t size = strlen(p) + 1;
    char* result = new char[size];
    
    copy(p, p+size, result);
    return result;
}

string letter_grade(double grade) {
    static const int numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }
    return "?/?/?";
}

bool space(char c) {return isspace(c);}
bool not_space(char c) {return !isspace(c);}

void split(const string& str, StringList& strList) {
    typedef string::const_iterator iter;
    iter i = str.begin();
    
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        
        if (i != j)
            strList.addString(string(i, j));
        i = j;
    }
}

int main(int argc, char** argv) {
    double checkGrade;
    cin >> checkGrade;
    cout << letter_grade(checkGrade) << "\n\n";
    
    string fileString = "fileToRead.txt";
    
    ifstream file(fileString.c_str());
    string s;
    
    while (getline(file, s))
        cout << s << endl;

    //if main was given args which are file paths
    int failCount = 0;
    if (argc > 1) {
        for (int i = 0; i < argc; ++i) {
            ifstream in(argv[i]);
            if (in) {
                string str;
                while (getline(in, str))
                    cout << str << endl;
            } else {
                cerr << "Cannot open file " << argv[i] << endl;
                ++failCount;
            }
        }
    }
    
    //testing template median for array/vector
    int p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "\narray median: " << median<int>(p, p + 10) << endl;
    
    vector<int> vec = {24, 645, 876, 5342, 123, 543, 765, 978, 564, 243, 654, 867, 543, 234, 642, 784, 52};
    cout << "vector median: " << median<int>(vec.begin(), vec.end()) << endl;
    
    //testing StringList class
    string anotherString;
    StringList newStrList;
    while (getline(cin, anotherString))
        split(anotherString, newStrList);
    
    newStrList.printList();
    
    return failCount;
}