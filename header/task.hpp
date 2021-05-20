#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "base.hpp"

class Task : public Base {
public:
    Task(string name, string dueDate, string details, int priority);
    ~Task();
    virtual void edit();
	virtual void display() const;
	virtual void del();
	virtual void setCompleted(bool isComplete);
	virtual void setAssigned(bool isAssigned);
	virtual bool isAssigned() const { return assigned; }
	virtual bool isCompleted() const { return completed; }
	virtual string getDate() const { return dueDate; }
        virtual string getName() const { return name; }
	virtual string getDetails() const { return details; }
        virtual int getPriority() const { return priority; }
	virtual double getDuration() const { return 0; }
protected:
    int priority;
    bool completed;
    string dueDate;
    bool assigned;
    string name;
};

/*
class TaskMock1 : public Base {
public:
    TaskMock1() {
        this->name = "Task 1";
        this->dueDate = "some date";
        this->details = "some details";
        this->priority = 2;
        this->completed = false; 
    }
    virtual void display() const {
        cout << name << endl;
        cout << dueDate << endl;
        cout << details << endl;
    }
    virtual void edit() {}
    virtual void del() {}
    virtual void setCompleted(bool isComplete) {}
	virtual void setAssigned(bool isAssigned) {}
	virtual bool isAssigned() const { return true; }
	virtual bool isCompleted() const { return true; }
	virtual string getDate() const { return ""; }
	virtual void addSubTask(Base* task) {}
    virtual vector<Base*> getQueue() const { return {}; }
private:
    string dueDate;
    bool completed;
    int priority;
};

class TaskMock2 : public Base {
public:
    TaskMock2() {
        this->name = "Task 2";
        this->dueDate = "a different date";
        this->details = "more details";
        this->priority = 4;
        this->completed = false; 
    }
    virtual void display() const {
        cout << name << endl;
        cout << dueDate << endl;
        cout << details << endl;
    }
    virtual void edit() {}
    virtual void del() {}
    virtual void setCompleted(bool isComplete) {}
	virtual void setAssigned(bool isAssigned) {}
	virtual bool isAssigned() const { return true; }
	virtual bool isCompleted() const { return true; }
	virtual string getDate() const { return ""; }
	virtual void addSubTask(Base* task) {}
    virtual vector<Base*> getQueue() const { return {}; }
private:
    string dueDate;
    bool completed;
    int priority;
};
*/

#endif
