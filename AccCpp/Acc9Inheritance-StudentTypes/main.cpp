/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 24, 2014, 7:50 PM
 */

#include "Student.h"

using std::string;          using std::cout;
using std::vector;          using std::endl;
using std::cin;             using std::setprecision;

int main(int argc, char** argv) {
    //typedef StudentStd StudentType;
    typedef StudentPF StudentType;
    
    vector<StudentType> students;
    StudentType record;
    string::size_type maxlen = 0;
    
    while (record.read(cin)) {
        students.push_back(record);
        maxlen = std::max(maxlen, record.name().size());
    }
    cout << endl;
    
    StudentType::arrange(students);
    for (vector<StudentType>::iterator iter = students.begin(); 
                                    iter != students.end(); ++iter) {
        cout << iter->name() << string(maxlen + 1 - iter->name().size(), ' ');
        iter->print();
        cout << endl;
    }
    return 0;
}