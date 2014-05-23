#include <stdexcept>
#include <numeric>
#include "grade.h"

using std::domain_error;        using std::vector;
using std::accumulate;          using std::transform;
using std::back_inserter;       using std::remove_copy;

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) {
    return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

double average(const vector<double>& hw) {
    return accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}

double average_grade(const Student_info& s) {
    return grade(s.midterm, s.final, average(s.homework));
}

double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    } catch(domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    return grade(s.midterm, s.final, median(nonzero));
}