#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include "base.hpp"

class TaskList : public Base {
private:
    int priority;
    bool completed;
    Base* priorityQueue;
    int numSubTasks;
public:
    virtual void display() const;
    virtual void edit();
    virtual void del();
    virtual void addSubTask(Base* task);
};

#endif
