#ifndef __SORTPRIORITY_CPP__
#define __SORTPRIORITY_CPP__

#include "../header/sortpriority.hpp"


template<class T>
vector<T> SortByPriority<T>::sort(vector<T> priorityQueue) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanPriority<T>());
    return priorityQueue;
} 

/*
template<class T>
vector<T> SortByPriority<T>::sort(vector<T> priorityQueue) {
    int maxIndex;
    for(int i = 0; i < priorityQueue.size(); i++) {
        //find max
        int max = 0;
        for(int j = i; j < priorityQueue.size(); j++) {
            T currObj = priorityQueue.at(j);
            if(currObj.getPriority() > max) {
                maxIndex = j;
                max = currObj.getPriority();
            }
        }
        //swap priorityQueue[maxIndex] with priorityQueue[i]
        if(maxIndex != i) {
            T temp = priorityQueue[i];
            priorityQueue[i] = priorityQueue[maxIndex];
            priorityQueue[maxIndex] = temp;
        }
    }
    return priorityQueue;
}
*/

#endif