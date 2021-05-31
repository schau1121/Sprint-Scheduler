#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

#include "../header/tasklist.hpp"

TaskList::TaskList(string name, string details, int priority) {

	if(name == "") {
                throw(invalid_argument("No task list name entered."));
        }

	if(priority < 0 || priority > 5) {
                throw(invalid_argument("Priority entered must be 0-5."));
        }


        this->name = name;
        this->details = details;
        this->priority = priority;
        this->completed = false;
        this->assigned = false;
        setStrategy("priority");
}

void TaskList::display(ostream& out) const {
	out << "Name: " << this->name << endl;
	out << "Details: " << this->details << endl;
    out << "Priority: " << this->priority << endl;
    
    if(priorityQueue.empty() == false) {
        out << "Sub Tasks: " << endl;
        for(int i = 0; i < priorityQueue.size(); i++) {
            out << (i + 1) << ". ";
            this->getQueue()[i].display(out);
        }
    }

    if(this->isCompleted()) {
        out << "Completed" << endl;
    }

	return;
}

void TaskList::edit(istream& in) {
    string newName;
    string newDetails;
    int newPriority;
    cout << "Current Task List: "; 
    this->display(cout);
    cout << "\nEnter new list name: ";
    in.ignore();
    getline(in, newName);
    while(newName == "") {
        cout << "Error: Need list name" << endl;
        cout << "Enter new list name: ";
        getline(in, newName);
    }
    cout << "\nEnter new details: ";
    getline(in, newDetails);
    cout << "\nEnter new priority: ";
    in >> newPriority;
    while(newPriority > 5 || newPriority < 0) {
        cout << "Error: Invalid priority" << endl;
        cout << "Enter new priority (0-5): ";
        in >> newPriority;
    }
    this->name = newName;
    this->details = newDetails;
    this->priority = newPriority;
    cout << "\nNew Task List: ";
    this->display(cout);
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

bool TaskList::isCompleted() const {
    if(priorityQueue.empty() == true) {
        return false;
    }
    for(int i = 0; i < priorityQueue.size(); i++) {
        if(priorityQueue[i].isCompleted() == false) {
            return false;
        }
    }
    return true;
}

#endif

