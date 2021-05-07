#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "sortstrategy.hpp"

class SortByPriority : public SortStrategy {
public:
    virtual Base* sort(Base* priorityQueue, int numSubTasks);
};

#endif
