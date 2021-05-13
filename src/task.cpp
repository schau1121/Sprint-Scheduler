#ifndef __TASK_CPP__
#define __TASK_CPP__

#include "../header/task.hpp"

Task::Task(string name, string dueDate = "", string details = "", int priority = 0) {
    if(name == "") {
        throw invalid_argument("Empty name passed into task constructor");
    }
    if(dueDate[2] != '/' || dueDate[5] != '/') {
        throw invalid_argument("Wrong date format passed into task constructor");
    }
    this->name = name;
    this->dueDate = dueDate;
    this->details = details;
    this->priority = priority;
    this->completed = false;
    this->assigned = false;
}

void Task::setCompleted(bool isComplete) {
    completed = isComplete;
}

void Task::setAssigned(bool isAssigned) {
    assigned = isAssigned;
}

Task::~Task() {
    delete this;
}
#endif