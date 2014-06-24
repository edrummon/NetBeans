/* 
 * File:   passFail.h
 * Author: Instinct212
 *
 * Created on June 22, 2014, 10:54 PM
 */

#ifndef PASSFAIL_H
#define	PASSFAIL_H

class PassFail : public Core {
public:
    PassFail() {}
    PassFail(std::istream& is) { read(is); }
    
    double grade() const {
        if (!hw.empty())
            return ::grade(midterm, final, hw);
        else
            return (midterm + final) / 2;
    }
    
    bool metRequirements() const { return midterm != 0 && final != 0; }
    
    std::string letterGrade() const {
        if (grade() >= 60)
            return "P";
        else
            return "F";
    }
    
protected:
    PassFail* clone() const { return new PassFail(*this); }
};

#endif	/* PASSFAIL_H */