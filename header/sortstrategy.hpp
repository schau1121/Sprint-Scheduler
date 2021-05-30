#ifndef __SORTSTRATEGY_HPP__
#define __SORTSTRATEGY_HPP__

#include <algorithm>
#include <vector>

using namespace std;

template<class T>
class SortStrategy {
public:
	SortStrategy() {};
	~SortStrategy() {};
	//This should return a new priority queue that is sorted
	virtual vector<T> sort(vector<T> priorityQueue) = 0;
};

#endif
