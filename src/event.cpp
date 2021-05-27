#ifndef __EVENT_CPP__
#define __EVENT_CPP__

#include "../header/event.hpp"

Event::Event(string name, string date, string time, string details, double duration) {
    this->name = name;
    this->date = date;
    this->time = time;
    this->details = details;
    this->duration = duration;
    this->priority = 6;
    setStrategy("priority");
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
    string newName;
    string newDetails;
    string newDate;
    string newTime;
    double newDuration;
    cout << "Current Event: "; 
    this->display();
    cout << "\nEnter new event name: ";
    cin >> newName;
    while(newName == "") {
        cout << "Error: Need event name" << endl;
        cout << "Enter new event name: ";
        cin >> newName;
    }
    cout << "\nEnter new date: ";
    cin >> newDate;
    while(newDate == "" || (newDate[2] != '/' || newDate[5] != '/')) {
        cout << "Error: Wrong date format" << endl;
        cout << "Enter new date (MM/DD/YY): ";
        cin >> newDate;
    }
    cout << "\nEnter new time: ";
    getline(cin, newTime);
    while(newTime[2] != ':' || (newTime.substr(6,2) != "AM" || newTime.substr(6,2) != "PM" || newTime.substr(6,2) != "am" || newTime.substr(6,2) != "pm")) {
        cout << "Error: Wrong time format" << endl;
        cout << "Enter new time (HH:MM AM/PM): ";
        getline(cin, newTime); 
    }
    cout << "\nEnter new details: ";
    getline(cin, newDetails);
    cout << "\nEnter new duration: ";
    cin >> newDuration;
    while(newDuration < 0) {
        cout << "Error: Invalid duration" << endl;
        cout << "Enter new duration: ";
        cin >> newDuration;
    }
    this->name = newName;
    this->date = newDate;
    this->details = newDetails;
    this->time = newTime;
    this->duration = newDuration;
}

void Event::addSubTask(TaskList list) {
    priorityQueue.push_back(list);
}

//event will always be set to sortPriority since TaskList has empty date attribute
void Event::setStrategy(string strategy) {
    if(this->strat != nullptr) {
        delete this->strat;
    }
    this->strat = new SortByPriority<TaskList>();
}

#endif
