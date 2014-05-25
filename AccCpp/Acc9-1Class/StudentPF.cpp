#include "StudentPF.h"

using std::istream;

istream& StudentPF::read(istream& in) {
    in >> n >> midterm >> final;
    final_grade = (midterm + final) / 2;
    if (in) {
        double throwAway;
        while (in >> throwAway);
        in.clear();
    }
    return in;
}

bool compare(const StudentPF& x, const StudentPF& y) {
    return x.name() < y.name();
}

bool pass(const StudentPF& s) {
    return s.getFinalGrade() > 60;
}