#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <string>
#include "base.hpp"
#include "tasklist.hpp"

class Event : public Base {
protected:
    string name;
    string date;
    string time;
    string details;
    double duration; //number of hours
    vector<Base*> priorityQueue;
    int numSubTasks;
public:
    Event(string name, string date, string time, string details, double duration);
    virtual void display() const;
    virtual void del();
    virtual void edit();
    void addSubTask(Base* task);
    virtual void setCompletedbool isComplete();
    virtual void setAssigned(bool isAssigned);
    virtual bool isAssigned() const;
    virtual bool isCompleted() const;
    virtual string getDate() const;
    virtual void addSubTask(Base* task);
    virtual vector<Base*> getQueue() const;
    void createEvent();
    ~Event();
};

//this mock is initialized with a task list containing 2 tasks
class EventMock : public Base {
protected:
    string date;
    string time;
    double duration; //number of hours
    vector<Base*> priorityQueue;
    int numSubTasks;
public:
    EventMock() {
        name = "Event 1";
        date = "05/15/20";
        time = "12:00 PM";
        details = "event details";
        duration = 2.5;
        numSubTasks = 1;
        priorityQueue.push_back(new TaskListMock());
    };
    virtual void display() const {};
    virtual void edit() {}
    virtual void del() {}
    virtual void setCompleted(bool isComplete) {}
	virtual void setAssigned(bool isAssigned) {}
	virtual bool isAssigned() const { return true; }
	virtual bool isCompleted() const { return true; }
	virtual string getDate() const { return ""; }
	virtual void addSubTask(Base* task) {}
    virtual vector<Base*> getQueue() const { return priorityQueue; }
};

#endif
