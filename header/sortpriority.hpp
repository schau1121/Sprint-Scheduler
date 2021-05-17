#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "sortstrategy.hpp"

struct greaterThanPriority {
    inline bool operator() (const Base* l, const Base* r) {
        return (l->getPriority() > r->getPriority());
    }
};

class SortByPriority : public SortStrategy {
public:
    SortByPriority() {};
    virtual vector<Base*> sort(vector<Base*> priorityQueue, int numSubTasks);
};

#endif
