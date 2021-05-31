#ifndef __TASK_CPP__
#define __TASK_CPP__

#include <iostream>
#include "../header/task.hpp"

using namespace std;

Task::Task(string name, string dueDate, string details, int priority) {

    if(name == "") {
        throw invalid_argument("No task name entered.");
    }

    if(!check_date_format(dueDate)) {
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

void Task::edit(istream& in) {
    string newName;
    string newDetails;
    string newDueDate;
    int newPriority;
    cout << "Current Task: "; 
    this->display(cout);
    cout << "\nEnter new task name: ";
    in.ignore();
    getline(in, newName);
    while(newName == "") {
        cout << "Error: Need task name" << endl;
        cout << "Enter new task name: ";
        getline(in, newName);
    }
    cout << "\nEnter new due date: ";
    in >> newDueDate;
    while(!check_date_format(newDueDate)) {
        cout << "Error: Wrong date format" << endl;
        cout << "Enter new due date (MM/DD/YY): ";
        in >> newDueDate;
    }
    cout << "\nEnter new details: ";
    in.ignore();
    getline(in, newDetails);
    cout << "\nEnter new priority: ";
    in >> newPriority;
    while(newPriority > 5 || newPriority < 0) {
        cout << "Error: Invalid priority" << endl;
        cout << "Enter new priority (0-5): ";
        in >> newPriority;
    }
    this->name = newName;
    this->dueDate = newDueDate;
    this->details = newDetails;
    this->priority = newPriority;
    cout << "\nNew Task: ";
    this->display(cout);
}

void Task::display(ostream& out) const {
	out << "Name: " << this->name << endl;
    out << "Due date: " << this->dueDate << endl;
	out << "Priority: " << this->priority << endl;
	out << "Details: " << this->details << endl;
	

	if(this->isCompleted()) {
		out << "Completed" << endl;
	}

	return;
}

void Task::setCompleted(bool isComplete) {
    completed = isComplete;
}

void Task::setAssigned(bool isAssigned) {
    assigned = isAssigned;
}

#endif
