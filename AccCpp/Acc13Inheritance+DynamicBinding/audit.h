/* 
 * File:   audit.h
 * Author: Instinct212
 *
 * Created on June 23, 2014, 11:56 PM
 */

#ifndef AUDIT_H
#define	AUDIT_H

class Audit : public Core {
public:
    Audit() {}
    Audit(std::istream& is) { read(is); }
    
    double grade() const { return 0; }
    bool metRequirements() const { return true; }
    std::string letterGrade() const { return "None"; }
    
protected:
    Audit* clone() const { return new Audit(*this); }
};

#endif	/* AUDIT_H */