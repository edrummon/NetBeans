/* 
 * File:   StudentPF.h
 * Author: Instinct212
 *
 * Created on May 24, 2014, 9:14 PM
 */

#ifndef STUDENTPF_H
#define	STUDENTPF_H

#include <iostream>
#include <string>

class StudentPF {
public:
    std::istream& read(std::istream&);
    
    std::string name() const {return n;}
    double getFinalGrade() const {return final_grade;}
private:
    double midterm, final, final_grade;
    std::string n;
};
bool compare(const StudentPF&, const StudentPF&);
bool pass(const StudentPF&);

#endif	/* STUDENTPF_H */

