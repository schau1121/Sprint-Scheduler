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
	virtual void setCompleted(bool isComplete) = 0;
	virtual void setAssigned(bool isAssigned) = 0;
	virtual bool isAssigned() const = 0;
	virtual bool isCompleted() const = 0;
	virtual string getDate() const = 0;
	virtual void addSubTask(Base* task) = 0;
	void setStrategy(SortStrategy* strat) {
		this->strategy = strat;
	}
	string getName() const { return name; }
    string getDetails() const { return details; }

};

#endif
