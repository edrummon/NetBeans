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
    ~Student() {std::cout << "destructor Student " << n << std::endl;}
    Student(const Student& s) {
        std::cout << "copy constructor Student " << s.n << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
    }
    Student& operator=(const Student& s) {
        std::cout << "assignment Student" << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
        return *this;
    }
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
std::istream& read_hw(std::istream&, Vec<double>&);

class StudentStd : public Student {
public:
    StudentStd() {std::cout << "constructorStd" << std::endl;}
    ~StudentStd() {std::cout << "destructorStd" << std::endl;}
    StudentStd(const StudentStd& s) {
        std::cout << "copy constructor StudentStd" << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
    }
    StudentStd& operator=(const StudentStd& s) {
        std::cout << "assignment StudentStd" << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
        return *this;
    }
    StudentStd(std::istream&);
    std::istream& read(std::istream&);
    bool valid() const {return !homework.empty();}
    
    static void arrange(Vec<StudentStd>&);
    void print();
private:
    Vec<double> homework;
};

class StudentPF : public Student {
public:
    StudentPF() {std::cout << "constructorPF" << std::endl;}
    ~StudentPF() {std::cout << "destructorPF " << n << std::endl;}
    StudentPF(const StudentPF& s) {
        std::cout << "copy constructor StudentPF " << s.n << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
    }
    StudentPF& operator=(const StudentPF& s) {
        std::cout << "assignment StudentPF" << std::endl;
        n = s.n;
        midterm = s.midterm;
        final = s.final;
        final_grade = s.final_grade;
        letter_grade = s.letter_grade;
        return *this;
    }
    StudentPF(std::istream&);
    std::istream& read(std::istream&);
    
    static void arrange(Vec<StudentPF>&);
    void print();
};

#endif	/* STUDENT_H */