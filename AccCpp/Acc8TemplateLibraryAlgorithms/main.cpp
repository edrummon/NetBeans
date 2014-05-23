/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 20, 2014, 5:35 PM
 */

#include <algorithm>
#include <numeric>

template<class In>
bool equal(In begin, In end, In otherBegin) {
    while (begin != end) {
        if (!(*begin++ == *otherBegin++))
            return false;
    }
    return true;
}

template<class In, class X>
In find(In begin, In end, const X& target) {
    while (begin != end && !(*begin == target))
        ++begin;
    return begin;
}

template<class In>
In find_if(In begin, In end, bool p(*In)) {
    while (begin != end) {
        if (p(*begin))
            return begin;
        else
            ++begin;
    }
    return begin;
}

template<class In, class Out>
Out copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template<class For, class X>
void remove(For begin, For end, const X& x) {
    while (begin != end) {
        if (*begin == x) {
            For iter = find(begin, end, !x);
            *begin++ = *iter++;
        } else {
            ++begin;
        }
    }
}

template<class In, class Out, class X>
void remove_copy(In begin, In end, Out dest, const X& x) {
    while (begin != end) {
        if (*begin != x)
            *dest++ = *begin++;
        else
            ++begin;
    }
}

template<class In, class Out>
void remove_copy_if(In begin, In end, Out dest, bool p(*In)) {
    while (begin != end) {
        if (!p(*begin))
            *dest++ = *begin;
        ++begin;
    }
}

template<class In, class Out, class T>
Out transform(In begin, In end, Out dest, T t) {
    while (begin != end) {
        *dest++ = t(*begin);
        ++begin;
    }
    return dest;
}

template<class In, class X>
X accumulate(In begin, In end, X& total) {
    while (begin != end)
        total += *begin++;
    return total;
}

template<class For>
For search(For begin, For end, For begin2, For end2) {
    while (begin + (end2-begin2) != end) {
        if (*begin != *begin2) {
            ++begin;
        } else {
            int i = 1;
            while (begin2 + i != end2) {
                if (*begin++ == *(begin2 + i))
                    ++i;
                else
                    break;
            }
            if (begin2 + i == end2) {
                return begin - i + 1;
            }
        }
    }
    return end;
}

template<class Bi>
Bi partition(Bi begin, Bi end, bool p(*Bi)) {
    while (begin != end) {
        if (!p(*begin)) {
            Bi iter = find_if(begin, end, p);
            if (iter == end)
                return begin;
            std::swap(*begin, *iter);
        }
        ++begin;
    }
    return begin;
}

int main(int argc, char** argv) {

    return 0;
}