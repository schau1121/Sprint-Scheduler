#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "base.hpp"
#include "tasklist.hpp"

class Event : public Base {
protected:
    string date;
    string time;
    double duration; //number of hours
    Base** priorityQueue;
    int numSubTasks;
public:
    Event(string name, string date, string time, string details, double duration);
    virtual void display() const;
    virtual void del();
    virtual void edit();
    void addSubTask(Base* task);
};


//this mock is initialized with a task list containing 2 tasks
class EventMock : public Event {
public:
    EventMock() : Event("Event 1", "05/15/20", "12:00 PM", "event details", 2.5) {
        numSubTasks = 1;
        priorityQueue = new Base* [numSubTasks];
        priorityQueue[0] = new TaskListMock();
    };
};

#endif
