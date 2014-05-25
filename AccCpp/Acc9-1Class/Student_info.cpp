#include "Student_info.h"

using std::vector;          using std::string;
using std::istream;

Student_info::Student_info(): midterm(0), final(0), final_grade(0) {}

Student_info::Student_info(istream& is) {read(is);}

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    
    if (valid())
        final_grade = ::grade(midterm, final, homework);
    else
        final_grade = ::grade(midterm, final, 0);
    
    return in;
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}