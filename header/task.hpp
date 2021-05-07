#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "base.hpp"

class Task : public Base {
public:
    virtual void display() const;
    virtual void edit();
    virtual void del();
private:
    int priority;
    bool completed;
    string dueDate;
};

#endif
