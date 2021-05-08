#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "base.hpp"

class Task : public Base {
public:
    Task(string name, string dueDate, string details, int priority);
    ~Task();
    virtual void display() const;
    virtual void edit();
    virtual void del();
    void setCompleted(bool isComplete);
protected:
    int priority;
    bool completed;
    string dueDate;
};

class TaskMock1 : public Task {
public:
    TaskMock1() : Task("Task 1", "some date", "some details", 0) {};
    virtual void display() const {
        cout << name << endl;
        cout << dueDate << endl;
        cout << details << endl;
    }
};

class TaskMock2 : public Task {
public:
    TaskMock2() : Task("Task 2", "another date", "different details", 3) {};
};

#endif
