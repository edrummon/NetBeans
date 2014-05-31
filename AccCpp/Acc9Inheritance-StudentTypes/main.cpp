/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 24, 2014, 7:50 PM
 */

#include "Student.h"
#include "Vec.h"

using std::string;          using std::cout;
using std::endl;            using std::setprecision;
using std::cin;

int main(int argc, char** argv) {
    //typedef StudentStd StudentType;
    typedef StudentPF StudentType;
    
    Vec<StudentType> students;
    StudentType record;
    string::size_type maxlen = 0;
    
    cout << "\nRead:" << endl;
    while (record.read(cin)) {
        students.push_back(record);
        maxlen = std::max(maxlen, record.name().size());
    }
    
    cout << "\nArrange:" << endl;
    StudentType::arrange(students);
    cout << "\nPrint:" << endl;
    for (Vec<StudentType>::iterator iter = students.begin(); 
                                    iter != students.end(); ++iter) {
        cout << iter->name() << string(maxlen + 1 - iter->name().size(), ' ');
        iter->print();
        cout << endl;
    }
    return 0;
}