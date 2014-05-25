/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 24, 2014, 7:50 PM
 */

#include <iomanip>
#include <ios>
//#include "Student_info.h"
#include "StudentPF.h"
#include "grade.h"

using std::string;          using std::cout;
using std::vector;          using std::endl;
using std::cin;             using std::setprecision;

int main(int argc, char** argv) {
    //typedef Student_info StudentType;
    typedef StudentPF StudentType;
    
    vector<StudentType> students;
    StudentType record;
    string::size_type maxlen = 0;
    
    while (record.read(cin)) {
        students.push_back(record);
        maxlen = std::max(maxlen, record.name().size());
    }
    std::sort(students.begin(), students.end(), compare);
    std::stable_partition(students.begin(), students.end(), pass);
    
    cout << endl;
    for (vector<StudentType>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        if (pass(students[i]))
            cout << "P" << endl;
        else
            cout << "F" << endl;
//        double finalGrade = students[i].getFinalGrade();
//        std::streamsize prec = cout.precision();
//        cout << setprecision(3) << finalGrade
//                << setprecision(prec) << endl;
    }
    return 0;
}