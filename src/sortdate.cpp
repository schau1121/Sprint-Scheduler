#ifndef __SORTDATE_CPP__
#define __SORTDATE_CPP__

#include "../header/sortdate.hpp"

template<class T>
vector<T> SortByDate<T>::sort(vector<T> priorityQueue) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanDate<T>());
    return priorityQueue;
}

#endif