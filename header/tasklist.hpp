#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include "base.hpp"
#include "task.hpp"

class TaskList : public Base {
protected:
    int priority;
    bool completed;
    Base** priorityQueue;
    int numSubTasks;
    //set to empty string to differentiate between tasks and task lists when sorting by date
    string dueDate = ""; 
public:
    TaskList(string name, string details, int priority);
    virtual void display() const;
    virtual void del();
    virtual void edit();
    void addSubTask(Base* task);
};

//this task list is initialized with two task mocks
class TaskListMock : public TaskList {
public:
    TaskListMock() : TaskList("TaskList 1", "some details", 0) {
        numSubTasks = 2;
        priorityQueue = new Base* [numSubTasks];
        priorityQueue[0] = new TaskMock1();
        priorityQueue[1] = new TaskMock2();
    }
};

#endif
