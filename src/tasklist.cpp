#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

#include "../header/tasklist.hpp"

TaskList::TaskList(string name, string details, int priority) {
    this->name = name;
    this->details = details;
    this->priority = priority;
    this->completed = false;
}

void TaskList::addSubTask(Base* task) {
    if(task != nullptr) {
        priorityQueue.push_back(task);
    }
}



#endif