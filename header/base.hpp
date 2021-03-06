#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include <string>
#include <stdexcept> //contains std::invalid_argument exception
#include <iosfwd> //contains std::ostream
#include <vector>

#include "sortstrategy.hpp"

using namespace std;

class Base {
protected:
	string name;
	string details;
	int priority;
public:
	Base() {};
	virtual void edit(istream& in) = 0;
	virtual void display(ostream& out) const = 0;
	//for task and taskList just set completed = isComplete
	//for event do nothing
	virtual void setCompleted(bool isComplete) = 0;
	//for task and taskList set assigned = isAssigned if the current object belongs to a priority queue
	//for event do nothing
	virtual void setAssigned(bool isAssigned) = 0;
	//for task and taskList return assigned
	//for event return false
	virtual bool isAssigned() const = 0;
	//for task and taskList return completed		
	//for event return false
	virtual bool isCompleted() const = 0;
	//helper function for display() & sortByDate()
	//for task and taskList return dueDate
	//for event return date & time separated by a new line
	
	// Get Functions
	virtual string getDate() const = 0;
	string getName() const { return name; }
	string getDetails() const { return details; }
	int getPriority() const { return priority; }
};



bool check_date_format(string date){

	if(date[2] != '/' || date[5] != '/') {
		return false;
	}
	else {
		return true;
	}
}

bool check_time_format(string time) {

	if(time.size() < 7 || time[2] != ':' || time.substr(6,7) != "AM" && time.substr(6,7) != "PM" && time.substr(6,7) != "am" && time.substr(6,7) != "pm"){
		return false;
	}
	else {
		return true;
	}
}

template<class T>
bool allAssigned(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		if(!vec[i].isAssigned()) {
			return false;
		}
	}
	return true;
}

#endif
