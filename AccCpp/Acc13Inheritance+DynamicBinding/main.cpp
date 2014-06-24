/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 21, 2014, 6:47 PM
 */

#include <iomanip>
#include "student_info.h"

using std::cin;         using std::cout;
using std::endl;        using std::setprecision;
using std::vector;      using std::max;
using std::streamsize;  using std::domain_error;
using std::string;

int main(int argc, char** argv) {
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    sort(students.begin(), students.end(), Student_info::compare);
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(1) << std::fixed << final_grade
                    << "\t" << students[i].letterGrade()
                    << "\t" << students[i].metRequirements()
                    << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    /*
    cout << "ok: " << endl;
    
    Core* p1 = new Core;
    Core* p2 = new Grad;
    Core s1;
    Grad s2;
    
    p1->name();
    p1->grade();
    
    p2->name();
    p2->grade();
    
    s1.grade();
    s1.name();
    
    s2.grade();
    s2.name();
    */
    return 0;
}