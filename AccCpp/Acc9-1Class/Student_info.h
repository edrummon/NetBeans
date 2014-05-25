/* 
 * File:   Student_info.h
 * Author: Instinct212
 *
 * Created on May 24, 2014, 7:52 PM
 */

#ifndef STUDENT_INFO_H
#define	STUDENT_INFO_H

#include <string>
#include <iostream>
#include "grade.h"

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    
    std::istream& read(std::istream&);
    double getFinalGrade() const {return final_grade;}
    bool valid() const {return !homework.empty();}
    std::string name() const {return n;}
    
private:
    std::string n;
    double midterm, final, final_grade;
    std::vector<double> homework;
};
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Student_info&, const Student_info&);

#endif	/* STUDENT_INFO_H */