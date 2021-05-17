#ifndef __SORTSTRATEGY_HPP__
#define __SORTSTRATEGY_HPP__

#include <algorithm>
#include "base.hpp"

using namespace std;

class SortStrategy {
public:
	SortStrategy() {};
	//This should return a new priority queue that is sorted
	//We need to deallocate the memory from the previous priority queue after sorting
	virtual vector<Base*> sort(vector<Base*> priorityQueue) = 0;
};

#endif
