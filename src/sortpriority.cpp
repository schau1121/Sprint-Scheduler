#include "../header/sortpriority.hpp"

vector<Base*> SortByPriority::sort(vector<Base*> priorityQueue, int numSubTasks) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanPriority());
    return priorityQueue;
} 