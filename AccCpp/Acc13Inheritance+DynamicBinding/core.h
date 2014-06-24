/* 
 * File:   core.h
 * Author: Instinct212
 *
 * Created on June 21, 2014, 6:49 PM
 */

#ifndef CORE_H
#define	CORE_H

#include <iostream>
#include "grade.h"

class Core {
    friend class Student_info;
public:
    Core(): midterm(0), final(0) {}
    Core(std::istream& is) { read(is); }
    virtual ~Core() {}
    
    std::string name() const { return n; }
    bool valid() const { return !hw.empty(); }
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const { return ::grade(midterm, final, hw); }
    virtual bool metRequirements() const { return std::find(hw.begin(), hw.end(), 0) == hw.end(); }
    virtual std::string letterGrade() const;
    
protected:
    virtual Core* clone() const { return new Core(*this); }
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> hw;
    
private:
    std::string n;
};

std::istream& read_hw(std::istream&, std::vector<double>&);

#endif	/* CORE_H */