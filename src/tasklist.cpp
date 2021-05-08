#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

#include "../header/tasklist.hpp"

TaskList::TaskList(string name, string details, int priority) {
    this->name = name;
    this->details = details;
    this->priority = priority;
    this->completed = false;
    this->numSubTasks = 0;
}

void TaskList::addSubTask(Base* task) {
    priorityQueue.push_back(task);
    numSubTasks++;
}

#endif