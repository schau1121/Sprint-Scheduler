#include "../header/sortpriority.hpp"

template<class T>
vector<T> SortByPriority<T>::sort(vector<T> priorityQueue) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanPriority<T>());
    return priorityQueue;
} 