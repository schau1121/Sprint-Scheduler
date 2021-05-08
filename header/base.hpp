#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include <string>
#include <stdexcept> //contains std::invalid_argument exception
#include <iosfwd> //contains std::ostream

#include "sortstrategy.hpp"

using namespace std;

class Base {
protected:
	SortStrategy* strategy;
	string name;
	string details;
public:
	virtual void edit() = 0;
	virtual void display() const = 0;
	virtual void del() = 0; //calling this del since delete is a keyword
	void setStrategy(SortStrategy* strat) {
		this->strategy = strat;
	}
};

#endif
