/* 
 * File:   Student_info.h
 * Author: Instinct212
 *
 * Created on May 6, 2014, 9:19 PM
 */

#ifndef STUDENT_INFO_H
#define	STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    Student_info() {std::cout << "constructor" << std::endl;}
    ~Student_info() {std::cout << "destructor " << name << std::endl;}
    Student_info(const Student_info& s) {
        std::cout << "copy constructor " << s.name << std::endl;
        name = s.name;
        midterm = s.midterm;
        final = s.final;
        homework = s.homework;
    }
    Student_info& operator=(const Student_info& rhs) {
        std::cout << "assignment operation" << std::endl;
        if (&rhs != this) {
            name = rhs.name;
            midterm = rhs.midterm;
            final = rhs.final;
            homework = rhs.homework;
        }
        return *this;
    }
    
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif	/* STUDENT_INFO_H */