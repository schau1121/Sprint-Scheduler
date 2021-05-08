#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "sortstrategy.hpp"

class SortByPriority : public SortStrategy {
public:
    SortByPriority() {};
    virtual vector<Base*> sort(vector<Base*> priorityQueue, int numSubTasks);
};

#endif
