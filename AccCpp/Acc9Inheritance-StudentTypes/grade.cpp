#include "grade.h"

using std::domain_error;        using std::string;

double grade(double midterm, double final, const Vec<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) {
    return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

string calculateLetterGrade(double grade) {
    static const int numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }
    return "?/?/?";
}