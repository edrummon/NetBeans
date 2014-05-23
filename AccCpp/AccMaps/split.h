/* 
 * File:   split.h
 * Author: Instinct212
 *
 * Created on May 14, 2014, 10:13 PM
 */

#ifndef SPLIT_H
#define	SPLIT_H

#include <vector>
#include <string>
#include <algorithm>

bool space(char);
bool not_space(char);
std::vector<std::string> split(const std::string&);

#endif	/* SPLIT_H */