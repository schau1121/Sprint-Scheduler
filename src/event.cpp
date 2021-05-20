#include "../header/event.hpp"

Event::Event(string name, string date, string time, string details, double duration) {
    this->name = name;
    this->date = date;
    this->time = time;
    this->details = details;
    this->duration = duration;
    this->priority = 6;
    setStrategy(new SortByPriority());
}

void Event::display() const {
	cout << "Name: " << this->name << " Date: " << this->date << endl;
	cout << "Time: " << this->time << endl;
	cout << "Duration: " << this->duration << endl;
	cout << "Details: " << this->details << endl;
	
	return;
}

void Event::del() {

}

void Event::edit() {

}

void Event::addSubTask(TaskList list) {
    priorityQueue.push_back(list);
}
