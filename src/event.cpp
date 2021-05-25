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

//event will always be set to sortPriority since TaskList has empty date attribute
void Event::setStrategy(string strategy) {
    if(this->strat != nullptr) {
        delete this->strat;
    }
    this->strat = new SortByPriority<TaskList>();
}

#endif
