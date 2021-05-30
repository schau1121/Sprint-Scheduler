#ifndef __EVENT_CPP__
#define __EVENT_CPP__

#include "../header/event.hpp"
#include <string>
//Date format: MM/DD/YY
//Time: HH:MM AM/PM
/*if(date[2] != '/' || date[5] != '/') {
    throw(invalid_argument("Wrong date format")
  }
  if(time[2] != ':' || (time.substr(6,2) != "AM" || time.substr(6,2) != "PM")) {
     throw(invalid_argument("Wrong time format")
  }
  
  in testing:
    EXPECT_THROW( ,invalid_argument)
*/


Event::Event(string name, string date, string time, string details, double duration) {

	if(name == "") {
                throw(invalid_argument("No event name entered."));
        }

	if(date != "" && date[2] != '/' || date[5] != '/') {
                throw(invalid_argument("Wrong date format entered."));
        }	
	
	if(time[2] != ':' || time.substr(6,7) != "AM" && time.substr(6,7) != "PM" && time.substr(6,7) != "am" && time.substr(6,7) != "pm") {

                throw(invalid_argument("Wrong time format entered."));
        }

	if(duration == 0) {
                throw(invalid_argument("No duration entered."));
        }


        this->name = name;
        this->date = date;
        this->time = time;
        this->details = details;
        this->duration = duration;
        this->priority = 6;
        setStrategy("priority");
}

void Event::display(ostream& out) const {
	out << "Name: " << this->name << endl;
    out << "Date: " << this->date << endl;
	out << "Time: " << this->time << endl;
	out << "Duration: " << this->duration << endl;
	out << "Details: " << this->details << endl;
	
    if(priorityQueue.empty() == false) {
        out << "Sub Lists: " << endl;
        for(int i = 0; i < priorityQueue.size(); i++) {
            out << (i + 1) << ". ";
            this->getQueue()[i].display(out);
        }
    }

	return;
}

void Event::del() {

}

void Event::edit(istream& in) {
    string newName;
    string newDetails;
    string newDate;
    string newTime;
    double newDuration;
    cout << "Current Event: "; 
    this->display(cout);
    cout << "\nEnter new event name: ";
    getline(in, newName);
    while(newName == "") {
        cout << "Error: Need event name" << endl;
        cout << "Enter new event name: ";
        getline(in, newName);
    }
    cout << "\nEnter new date: ";
    in >> newDate;
    while(newDate == "" || (newDate[2] != '/' || newDate[5] != '/')) {
        cout << "Error: Wrong date format" << endl;
        cout << "Enter new date (MM/DD/YY): ";
        in >> newDate;
    }
    cout << "\nEnter new time: ";
    in.ignore();
    getline(in, newTime);
    while(newTime.size() < 8 || newTime[2] != ':' || newTime.substr(6,2) != "AM" && newTime.substr(6,2) != "PM" && newTime.substr(6,2) != "am" && newTime.substr(6,2) != "pm") {
        cout << "Error: Wrong time format" << endl;
        cout << "Enter new time (HH:MM AM/PM): ";
        getline(in, newTime); 
    }
    cout << "\nEnter new details: ";
    getline(in, newDetails);
    cout << "\nEnter new duration: ";
    in >> newDuration;
    while(newDuration < 0) {
        cout << "Error: Invalid duration" << endl;
        cout << "Enter new duration: ";
        in >> newDuration;
    }
    this->name = newName;
    this->date = newDate;
    this->details = newDetails;
    this->time = newTime;
    this->duration = newDuration;
    cout << "\nNew Event: ";
    this->display(cout);
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
