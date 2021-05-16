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
	SortStrategy* strategy;
	string name;
	string details;
public:
	Base() {};
	virtual void edit() = 0;
	virtual void display() const = 0;
	virtual void del() = 0;
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
	virtual string getDate() const = 0;
	//for task do nothing
	//for taskList and event add task to priorityQueue
	virtual void addSubTask(Base* task) = 0;
	//for task return empty list
	//for taskList and event return priorityQueue
	virtual vector<Base*> getQueue() const = 0;
	void setStrategy(SortStrategy* strat) {
		this->strategy = strat;
	}
	string getName() const { return name; }
    string getDetails() const { return details; }

};

#endif
