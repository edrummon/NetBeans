/* 
 * File:   Student.h
 * Author: Instinct212
 *
 * Created on May 25, 2014, 3:12 PM
 */

#ifndef STUDENT_H
#define	STUDENT_H

#include <iostream>
#include <iomanip>
#include <ios>
#include "grade.h"

class Student {
public:
    Student();
    double getFinalGrade() const {return final_grade;}
    std::string getLetterGrade() const {return letter_grade;}
    std::string name() const {return n;}
protected:
    std::string n;
    double midterm, final, final_grade;
    std::string letter_grade;
};

bool compare(const Student&, const Student&);
bool pass(const Student&);
std::istream& read_hw(std::istream&, std::vector<double>&);

class StudentStd : public Student {
public:
    StudentStd() {}
    StudentStd(std::istream&);
    std::istream& read(std::istream&);
    bool valid() const {return !homework.empty();}
    
    static void arrange(std::vector<StudentStd>&);
    void print();
private:
    std::vector<double> homework;
};

class StudentPF : public Student {
public:
    StudentPF() {}
    StudentPF(std::istream&);
    std::istream& read(std::istream&);
    
    static void arrange(std::vector<StudentPF>&);
    void print();
};

#endif	/* STUDENT_H */