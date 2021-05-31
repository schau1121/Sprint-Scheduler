#ifndef __TASK_CPP__
#define __TASK_CPP__

#include <iostream>
#include "../header/task.hpp"

using namespace std;

Task::Task(string name, string dueDate, string details, int priority) {

    if(name == "") {
        throw invalid_argument("No task name entered.");
    }

    if(!check_date_format(date)) {
        throw invalid_argument("Wrong date format entered.");
    }

    if(priority < 0 || priority > 5) {
        throw(invalid_argument("Priority entered must be 0-5."));
    }

    this->name = name;
    this->dueDate = dueDate;
    this->details = details;
    this->priority = priority;
    this->completed = false;
    this->assigned = false;
}

void Task::edit() {
    string newName;
    string newDetails;
    string newDueDate;
    int newPriority;
    cout << "Current Task: "; 
    this->display();
    cout << "\nEnter new task name: ";
    getline(cin, newName);
    while(newName == "") {
        cout << "Error: Need task name" << endl;
        cout << "Enter new task name: ";
        getline(cin, newName);
    }
    cout << "\nEnter new due date: ";
    cin >> newDueDate;
    while(newDueDate == "" || (newDueDate[2] != '/' || newDueDate[5] != '/')) {
        cout << "Error: Wrong date format" << endl;
        cout << "Enter new due date (MM/DD/YY): ";
        cin >> newDueDate;
    }
    cout << "\nEnter new details: ";
    cin.ignore();
    getline(cin, newDetails);
    cout << "\nEnter new priority: ";
    cin >> newPriority;
    while(newPriority > 5 || newPriority < 0) {
        cout << "Error: Invalid priority" << endl;
        cout << "Enter new priority (0-5): ";
        cin >> newPriority;
    }
    this->name = newName;
    this->dueDate = newDueDate;
    this->details = newDetails;
    this->priority = newPriority;
    cout << "\nNew Task: ";
    this->display();
}

void Task::display() const {
	cout << "Name: " << this->name << endl;
    cout << "Due date: " << this->dueDate << endl;
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
