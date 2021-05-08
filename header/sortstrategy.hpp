#ifndef __SORTSTRATEGY_HPP__
#define __SORTSTRATEGY_HPP__

#include "base.hpp"

using namespace std;

class Base;

class SortStrategy {
public:
	SortStrategy() {};
	//This should return a new priority queue that is sorted
	virtual vector<Base*> sort(vector<Base*> priorityQueue, int numSubTasks) = 0;
};

#endif
