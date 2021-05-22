#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

#include "../header/tasklist.hpp"

TaskList::TaskList(string name, string details, int priority) {
    this->name = name;
    this->details = details;
    this->priority = priority;
    this->completed = false;
    setStrategy("priority");
}

void TaskList::display() const {
	cout << "Name: " << this->name << endl;
	cout << "Priority: " << this->priority << endl;
	cout << "Details: " << this->details << endl;
	
	return;
}

void TaskList::del() {

}

void TaskList::edit() {

}

void TaskList::addSubTask(Task task) {
    priorityQueue.push_back(task);
}

void TaskList::setCompleted(bool isComplete) {
    completed = isComplete;
}
void TaskList::setAssigned(bool isAssigned) {
    assigned = isAssigned;
}

void TaskList::setStrategy(string strategy) {
    if(this->strat != nullptr) {
        delete this->strat;
    }
    if(strategy == "date") {
        this->strat = new SortByDate<Task>();
    }
    if(strategy == "priority") {
        this->strat = new SortByPriority<Task>();
    }
}

#endif

