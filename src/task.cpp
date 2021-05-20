#include "../header/task.hpp"

#include <iostream>

void Task::edit() {

}

void Task::display() const {
	cout << "Name: " << this->name << " Date: " << this->date << endl;
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


