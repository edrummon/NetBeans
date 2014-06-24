#include "core.h"

using std::vector;      using std::istream;
using std::cin;         using std::string;

istream& Core::read(istream& in) {
    read_common(in);
    read_hw(in, hw);
    return in;
}

istream& Core::read_common(istream& in) {
    in >> n >> midterm >> final;
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

string Core::letterGrade() const {
    static const int numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    double g = grade();
    
    for (size_t i = 0; i < ngrades; ++i) {
        if (g >= numbers[i])
            return letters[i];
    }
    return "?/?/?";
}