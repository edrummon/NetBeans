#include "stringList.h"

using std::string;          using std::list;

void StringList::printList() const {
    for (list<string>::const_iterator iter = L.begin(); iter != L.end(); ++iter)
        std::cout << *iter << " ";
}