#include "../header/event.hpp"

void Event::addSubTask(Base* task) {
    if(task != nullptr) {
        priorityQueue.push_back(task);
    }
}

string Event::getDate() const {
    return (date + "\n" + time + "\n");
}