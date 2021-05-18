#include "../header/sortpriority.hpp"

vector<Base*> SortByPriority::sort(vector<Base*> priorityQueue) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanPriority());
    return priorityQueue;
} 