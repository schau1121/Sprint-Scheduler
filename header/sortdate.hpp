#ifndef __SORTDATE_HPP__
#define __SORTDATE_HPP__

#include "sortstrategy.hpp"

class SortByDate : public SortStrategy {
public:
    virtual Base* sort(Base* priorityQueue, int numSubTasks);
};

#endif
