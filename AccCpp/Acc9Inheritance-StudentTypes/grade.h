/* 
 * File:   grade.h
 * Author: Instinct212
 *
 * Created on May 6, 2014, 9:28 PM
 */

#ifndef GRADE_H
#define	GRADE_H

#include <string>
#include "median.h"

double grade(double, double, const Vec<double>&);
double grade(double, double, double);
std::string calculateLetterGrade(double);

#endif	/* GRADE_H */