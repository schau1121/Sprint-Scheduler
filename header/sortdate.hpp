#ifndef __SORTDATE_HPP__
#define __SORTDATE_HPP__

#include "sortstrategy.hpp"

struct greaterThanDate {
    inline bool operator() (const Base* l, const Base* r) {
        int leftYear = stoi(l->getDate().substr(6, 2));
        int rightYear = stoi(r->getDate().substr(6, 2));
        int leftMonth = stoi(l->getDate().substr(0,2));
        int rightMonth = stoi(r->getDate().substr(0,2));
        int leftDay = stoi(l->getDate().substr(3,2));
        int rightDay = stoi(r->getDate().substr(3,2));
        if(leftYear < rightYear) {
            return true;
        }
        if(leftYear == rightYear && leftMonth < rightMonth) {
            return true;
        }
        if(leftYear == rightYear && leftMonth == rightMonth && leftDay < rightDay) {
            return true;
        }
        return false;
    }
};

class SortByDate : public SortStrategy {
public:
    SortByDate() {};
    virtual vector<Base*> sort(vector<Base*> priorityQueue);
};

#endif
