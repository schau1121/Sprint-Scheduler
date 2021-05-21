#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "base.hpp"
#include "../src/sortdate.cpp"
#include "../src/sortpriority.cpp"
#include "../src/tasklist.cpp"

class Event : public Base {
protected:
    string date;
    string time;
    double duration; //number of hours
    vector<TaskList> priorityQueue;
    int numSubTasks;
    SortStrategy<TaskList>* strat = nullptr;
public:
    Event(string name, string date, string time, string details, double duration);
    ~Event() {}
    virtual void display() const;
    virtual void del();
    virtual void edit();
    void addSubTask(TaskList list);
    virtual void setCompleted(bool isComplete) {};
	virtual void setAssigned (bool isAssigned) {};
	virtual bool isAssigned() const { return false; }
	virtual bool isCompleted() const { return false; }
	virtual string getDate() const { return (date + "\n" + time + "\n"); }
    vector<TaskList> getQueue() const { return strat->sort(priorityQueue); }
    void setStrategy(string strategy);
    
    
};

/*
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
	virtual bool isAssigned() const { return false; }
	virtual bool isCompleted() const { return false; }
	virtual string getDate() const { return ""; }
	virtual void addSubTask(Base* task) {}
    virtual vector<Base*> getQueue() const { return priorityQueue; }
    virtual int getPriority() const { return 6; }
};
*/

#endif
