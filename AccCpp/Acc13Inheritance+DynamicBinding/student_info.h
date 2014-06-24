/* 
 * File:   student_info.h
 * Author: Instinct212
 *
 * Created on June 21, 2014, 6:56 PM
 */

#ifndef STUDENT_INFO_H
#define	STUDENT_INFO_H

#include "core.h"
#include "grad.h"
#include "passFail.h"
#include "audit.h"

class Student_info {
public:
    Student_info(): cp(0) {}
    Student_info(std::istream& is): cp(0) { read(is); }
    Student_info(const Student_info& s): cp(0) { if (s.cp) cp = s.cp->clone(); }
    ~Student_info() { delete cp; }
    
    Student_info& operator=(const Student_info&);
    
    std::istream& read(std::istream&);
    
    bool valid() const {
        if (cp) return cp->valid();
        else throw std::runtime_error("uninitialized Student");
    }
    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }
    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }
    std::string letterGrade() const {
        if (cp) return cp->letterGrade();
        else throw std::runtime_error("uninitialized Student");
    }
    bool metRequirements() const {
        if (cp) return cp->metRequirements();
        else throw std::runtime_error("uninitialized Student");
    }
    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }
    
private:
    Core* cp;
};

#endif	/* STUDENT_INFO_H */