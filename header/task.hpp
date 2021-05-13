#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "base.hpp"

class Task : public Base {
public:
    Task(string name, string dueDate, string details, int priority);
    ~Task();
    virtual void display() const {};
    virtual void edit() {};
    virtual void del() {};
    void setCompleted(bool isComplete);
    bool isCompleted() const { return completed; }
    bool isAssigned() const { return assigned; }
    void setAssigned(bool isAssigned);
protected:
    int priority;
    bool completed;
    string dueDate;
    bool assigned;
};

class TaskMock1 : public Base {
public:
    TaskMock1() {
        this->name = "Task 1";
        this->dueDate = "some date";
        this->details = "some details";
        this->priority = 2;
        this->completed = false; 
    };
    virtual void display() const {
        cout << name << endl;
        cout << dueDate << endl;
        cout << details << endl;
    };
    virtual void edit() {};
    virtual void del() {};
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
    };
    virtual void display() const {
        cout << name << endl;
        cout << dueDate << endl;
        cout << details << endl;
    };
    virtual void edit() {};
    virtual void del() {};
private:
    string dueDate;
    bool completed;
    int priority;
};

#endif
