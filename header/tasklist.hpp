#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include "base.hpp"
#include "task.hpp"

class TaskList : public Base {
protected:
    int priority;
    bool completed;
    vector<Base*> priorityQueue;
    int numSubTasks;
    //set to empty string to differentiate between tasks and task lists when sorting by date
    string dueDate = ""; 
    bool assigned;
public:
    TaskList(string name, string details, int priority);
    virtual void display() const {};
    virtual void del() {};
    virtual void edit() {};
    virtual void addSubTask(Base* task);
    virtual void setCompleted(bool isComplete) {}
    virtual void setAssigned(bool isAssigned) {}
    virtual bool isCompleted() { return completed; }
    virtual bool isAssigned() const { return assigned; }
    virtual string getDate() const { return dueDate; }
    vector<Base*> getQueue() const { return priorityQueue; }
    int getNumTasks() const { return numSubTasks; }
};

//this task list is initialized with two task mocks
class TaskListMock : public Base {
protected:
    int priority;
    bool completed;
    vector<Base*> priorityQueue;
    int numSubTasks;
    //set to empty string to differentiate between tasks and task lists when sorting by date
    string dueDate = ""; 
public:
    TaskListMock() {
        name = "Homework";
        details = "";
        completed = false;
        priority = 4;
        numSubTasks = 2;
        priorityQueue.push_back(new TaskMock1());
        priorityQueue.push_back(new TaskMock2());
    }
    virtual void display() const {}
    virtual void del() {}
    virtual void edit() {}
    virtual void setCompleted(bool isComplete) {}
	virtual void setAssigned(bool isAssigned) {}
	virtual bool isAssigned() const { return true; }
	virtual bool isCompleted() const { return true; }
	virtual string getDate() const { return dueDate; }
};

#endif
