/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 6, 2014, 8:31 PM
 */

#include <vector>
//#include <list>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::string;
using std::cout;            using std::vector;
using std::endl;            using std::find;
using std::partition;

//typedef vector<Student_info> containerType;
//typedef list<Student_info> containerType;

bool fgrade(const Student_info& s) {return grade(s) < 60;}
bool pgrade(const Student_info& s) {return !fgrade(s);}

bool did_all_hw(const Student_info& s) {
    return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

void write_analysis(std::ostream& out, const string& name,
                    double gradingType(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt) {
    out << name << " (did) = " << analysis(did, gradingType) <<
            ", (didnt) = " << analysis(didnt, gradingType) << endl;
}

vector<Student_info> extractDidntDoAllHw(vector<Student_info>& students) {
    vector<Student_info>::iterator iter = 
            partition(students.begin(), students.end(), did_all_hw);
    vector<Student_info> missedHw (iter, students.end());
    students.erase(iter, students.end());
    return missedHw;
}

int main(int argc, char** argv) {

    Student_info student;
    vector<Student_info> did, didnt;
    
    while (read(cin, student)) {
        did.push_back(student);
    }
    
    cout << "Extraction:" << endl;
    didnt = extractDidntDoAllHw(did);
    
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }
    
    cout << "Analysis:" << endl;
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", 
                    optimistic_median, did, didnt);
    
    return 0;
}