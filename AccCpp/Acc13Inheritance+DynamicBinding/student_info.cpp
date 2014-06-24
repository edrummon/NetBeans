#include "student_info.h"

using std::istream;

istream& Student_info::read(istream& in) {
    delete cp;
    
    char ch;
    in >> ch;

    if (ch == 'U')
        cp = new Core(in);
    else if (ch == 'G')
        cp = new Grad(in);
    else if (ch == 'P')
        cp = new PassFail(in);
    else if (ch == 'A')
        cp = new Audit(in);
    
    return in;
}

Student_info& Student_info::operator=(const Student_info& rhs) {
    if (&rhs != this) {
        delete cp;
        if (rhs.cp)
            cp = rhs.cp->clone();
        else
            cp = 0;
    }
    return *this;
}