/* 
 * File:   median.h
 * Author: Instinct212
 *
 * Created on May 26, 2014, 11:29 PM
 */

#ifndef MEDIAN_H
#define	MEDIAN_H

#include <algorithm>
#include <stdexcept>
#include <vector>

template<class T, class For>
T median(For begin, For end) {
    if (begin == end)
        throw std::domain_error("median of an empty container");
    
    std::vector<T> ret;
    std::copy(begin, end, std::back_inserter(ret));
    
    std::sort(ret.begin(), ret.end());
    size_t mid = ret.size() / 2;
    
    T medianFound = ret.size() % 2 == 0 ? (ret[mid] + ret[mid+1]) / 2 : ret[mid];
    return medianFound;
}

#endif	/* MEDIAN_H */

