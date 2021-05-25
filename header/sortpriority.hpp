#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "sortstrategy.hpp"


template<class T>
struct greaterThanPriority {
    inline bool operator() (const T l, const T r) {
        return (l.getPriority() > r.getPriority());
    }
};


template<class T>
class SortByPriority : public SortStrategy<T> {
public:
    SortByPriority() {};
    ~SortByPriority() {};
    virtual vector<T> sort(vector<T> priorityQueue);
};

#endif
