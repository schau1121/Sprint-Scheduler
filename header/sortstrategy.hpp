#ifndef __SORTSTRATEGY_HPP__
#define __SORTSTRATEGY_HPP__

#include "base.hpp"

class SortStrategy {
public:
	//This should return a new priority queue that is sorted
	//We need to deallocate the memory from the previous priority queue after sorting
	virtual std::vector<Base*> sort(vector<Base*> priorityQueue, int numSubTasks) = 0;
};

#endif
