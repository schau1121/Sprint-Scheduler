#ifndef __EVENT_CPP__
#define __EVENT_CPP__

#include "../header/event.hpp"
#include <string>
//Date format: MM/DD/YY
//Time: HH:MM AM/PM

using json = nlohmann::json;

Event::Event(string name, string date, string time, string details, double duration) {

	if(name == "") {
                throw(invalid_argument("No event name entered."));
        }

	if(!check_date_format(date)) {
                throw(invalid_argument("Wrong date format entered."));
        }	
	
	if(!check_time_format(time)) {
                throw(invalid_argument("Wrong time format entered."));
        }

	if(duration <= 0) {
        throw(invalid_argument("Invalid duration."));
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

void Event::edit(istream& in) {
    string newName;
    string newDetails;
    string newDate;
    string newTime;
    double newDuration;
    cout << "Current Event: "; 
    this->display(cout);
    cout << "\nEnter new event name: ";
    in.ignore();
    getline(in, newName);
    while(newName == "") {
        cout << "Error: Need event name" << endl;
        cout << "Enter new event name: ";
        getline(in, newName);
    }
    cout << "\nEnter new date: ";
    in >> newDate;
    while(!check_date_format(newDate)) {
        cout << "Error: Wrong date format" << endl;
        cout << "Enter new date (MM/DD/YY): ";
        in >> newDate;
    }
    cout << "\nEnter new time: ";
    in.ignore();
    getline(in, newTime);
    while(!check_time_format(newTime)) {
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

//create json and set to event.json file
//call python executable push-event.py
//try: turning python script into executable to avoid users needed python/dependencies
void Event::pushEvent() {
    ofstream out;
    out.open("event.json", ofstream::out | ofstream::trunc);
    if(out.is_open()) {
        json j;
        json start;
        json end;
        string description = this->details;
        string startDateTime;
        //only supports pacific time
        string timeZone = "America/Los_Angeles";
        bool AM = true;

        j["summary"] = this->name;
        
        //load description 
        if(this->priorityQueue.size() == 0) {
            j["description"] = description;
        }
        else {
            description += "\nTask List:";
            for(int i = 0; i < priorityQueue.size(); i++) {
                for(int j = 0; i < priorityQueue[i].priorityQueue.size(); j++) {
                    description += "\n";
                    description += priorityQueue[i].priorityQueue[j].getName();
                }
            }
            j["description"] = description;
        }
        
        //load start time
        if(this->time[6] == 'P') {
            AM = false;
        } 
        startDateTime = "20" + this->date.substr(6,2);
        startDateTime += "-" + this->date.substr(0,2);
        startDateTime += "-" + this->date.substr(3,2);
        startDateTime += "T";
        if(!AM) {
            int hour = 12;
            hour += stoi(this->time.substr(0,2));
            startDateTime += std::to_string(hour);
        }
        else {
            startDateTime += this->time.substr(0,2);
        }
        startDateTime += this->time.substr(2,3);
        startDateTime += ":00";
        start["dateTime"] = startDateTime;
        start["timeZone"] = timeZone;
        j["start"] = start;

        //load end time
        string endTime = startDateTime.substr(11);
        //cout << "End Time: " << endTime << endl;
        int hour = stoi(endTime.substr(0,2));
        //cout << "Hour: " << hour << endl;
        int min = stoi(endTime.substr(3,2));
        float whole, fractional;
        fractional = std::modf(this->duration, &whole);
        int plus_min = 60 * fractional;
        hour += whole;
        min += plus_min;
        if(min >= 60) {
           hour++;
           min -= 60; 
        }
        //cout << "New hour: " << hour << endl;
        endTime.replace(0,2,to_string(hour));
        endTime.replace(3,2,to_string(min));
        startDateTime.replace(11,8,endTime);
        end["dateTime"] = startDateTime;
        end["timeZone"] = timeZone;
        j["end"] = end;

        out << setw(4) << j;
    }
    else {
        std::cout << "cant open event.json\n";
    }

    //run python script/executable
}

#endif
