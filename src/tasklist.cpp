#include "../header/tasklist.hpp"

TaskList::TaskList(string name, string details, int priority) {
    this->name = name;
    this->details = details;
    this->priority = priority;
    setStrategy(new SortByPriority());
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

}

void TaskList::setCompleted(bool isComplete) {
    completed = isComplete;
}
void TaskList::setAssigned(bool isAssigned) {
    assigned = isAssigned;
}
