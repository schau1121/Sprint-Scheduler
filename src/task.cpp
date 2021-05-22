#ifndef __TASK_CPP__
#define __TASK_CPP__

#include <iostream>
#include "../header/task.hpp"

Task::Task(string name, string dueDate, string details, int priority) {
    if(name == "") {
        throw invalid_argument("Empty name passed into task constructor");
    }
    if(dueDate != "" && (dueDate[2] != '/' || dueDate[5] != '/')) {
        throw invalid_argument("Wrong date format passed into task constructor");
    }
    this->name = name;
    this->dueDate = dueDate;
    this->details = details;
    this->priority = priority;
    this->completed = false;
    this->assigned = false;
}

void Task::edit() {

}

void Task::display() const {
	cout << "Name: " << this->name << " Date: " << this->dueDate << endl;
	cout << "Priority: " << this->priority << endl;
	cout << "Details: " << this->details << endl;
	

	if(this->isCompleted()) {
		cout << "Completed" << endl;
	}

	return;
}

void Task::del() {

}

void Task::setCompleted(bool isComplete) {
    completed = isComplete;
}

void Task::setAssigned(bool isAssigned) {
    assigned = isAssigned;
}

#endif
