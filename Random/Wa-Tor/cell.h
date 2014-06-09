/* 
 * File:   cell.h
 * Author: Instinct212
 *
 * Created on June 6, 2014, 2:45 AM
 */

#ifndef CELL_H
#define	CELL_H

class cell {
public:
    cell() { occupied = false; }
    
    occupy() { occupied = true; }
    unoccupy() { occupied = false; }
private:
    bool occupied;
    bool hasFish, hasShark;
};

#endif	/* CELL_H */