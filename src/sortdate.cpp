#include "../header/sortdate.hpp"

vector<Base*> SortByDate::sort(vector<Base*> priorityQueue, int numSubTasks) {
    std::sort(priorityQueue.begin(), priorityQueue.end(), greaterThanDate());
    return priorityQueue;    
}
