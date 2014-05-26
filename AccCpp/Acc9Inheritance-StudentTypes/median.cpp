#include "median.h"

using std::vector;      using std::sort;
using std::domain_error;

double median(vector<double> vec) {
    size_t size = vec.size();
    
    if (size == 0)
        throw domain_error("Median of an empty vector");
    
    sort(vec.begin(), vec.end());
    
    size_t mid = size / 2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}