#include "Student.h"

using std::string;          using std::cout;
using std::istream;         using std::streamsize;
using std::setprecision;

Student::Student(): midterm(0), final(0), final_grade(0) {cout << "constructor Student" << std::endl;}

StudentStd::StudentStd(istream& is) {read(is);}

istream& StudentStd::read(istream& in) {
    in >> n >> midterm >> final;
    ::read_hw(in, homework);
    
    if (valid())
        final_grade = ::grade(midterm, final, homework);
    else
        final_grade = ::grade(midterm, final, 0);
    
    letter_grade = ::calculateLetterGrade(final_grade);
    
    return in;
}

void StudentStd::arrange(Vec<StudentStd>& students) {
    std::sort(students.begin(), students.end(), compare);
}

void StudentStd::print() {
    streamsize prec = cout.precision();
    cout << setprecision(3) << final_grade << setprecision(prec) << "\t" << letter_grade;
}

StudentPF::StudentPF(istream& is) {read(is);}

istream& StudentPF::read(istream& in) {
    in >> n >> midterm >> final;
    final_grade = (midterm + final) / 2;
    if (in) {
        double throwAway;
        while (in >> throwAway);
        in.clear();
    }
    letter_grade = ::calculateLetterGrade(final_grade);
    return in;
}

void StudentPF::arrange(Vec<StudentPF>& students) {
    std::sort(students.begin(), students.end(), compare);
    std::stable_partition(students.begin(), students.end(), pass);
}

void StudentPF::print() {
    ::pass(*this) ? cout << "P" : cout << "F";
    cout << "\t" << letter_grade;
}

bool compare(const Student& x, const Student& y) {
    return x.name() < y.name();
}

bool pass(const Student& s) {
    return s.getFinalGrade() > 60;
}

istream& read_hw(istream& in, Vec<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}