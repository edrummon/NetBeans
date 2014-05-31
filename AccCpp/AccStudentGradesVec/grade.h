/* 
 * File:   grade.h
 * Author: Instinct212
 *
 * Created on May 6, 2014, 9:28 PM
 */

#ifndef GRADE_H
#define	GRADE_H

#include <algorithm>
#include "Student_info.h"
#include "median.h"

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double grade_aux(const Student_info&);
double optimistic_median(const Student_info&);

template<class T>
double analysis(const std::vector<Student_info>& students, T gradingFunction) {
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), gradingFunction);
    return median(grades);
}

#endif	/* GRADE_H */