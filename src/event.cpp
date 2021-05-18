#ifndef __EVENT_CPP__
#define __EVENT_CPP__

#include "../header/event.hpp"

Event::Event(string name, string date, string time, string details, double duration) {
	this->name = name;
	this->date = date;
	this->time = time;
	this->details = details;
	this->duration = duration;
}




#endif
