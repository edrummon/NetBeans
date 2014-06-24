/* 
 * File:   grad.h
 * Author: Instinct212
 *
 * Created on June 21, 2014, 6:49 PM
 */

#ifndef GRAD_H
#define	GRAD_H

class Grad : public Core {
public:
    Grad(): thesis(0) {}
    Grad(std::istream& is) { read(is); }

    std::istream& read(std::istream& in) {
        read_common(in);
        in >> thesis;
        read_hw(in, hw);
        return in;
    }
    
    double grade() const { return std::min(Core::grade(), thesis); }
    bool metRequirements() const { return thesis > 0; }
    
protected:
    Grad* clone() const { return new Grad(*this); }
        
private:
    double thesis;
};

#endif	/* GRAD_H */