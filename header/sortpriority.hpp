#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "sortstrategy.hpp"

class SortByPriority : public SortStrategy {
public:
    virtual std::vector<Base*> sort(vector<Base*> priorityQueue, int numSubTasks);
};

#endif
