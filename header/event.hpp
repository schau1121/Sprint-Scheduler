#ifndef __EVENT_HPP__
#define __EVENT_HPP__

class Event : public Base {
private:
    string date;
    string time;
    double duration; //number of hours
    Base* priorityQueue;
    int numSubTasks;
public:
    virtual void display() const;
    virtual void edit();
    virtual void del();
    virtual void addSubTask(Base* task);
};

#endif
