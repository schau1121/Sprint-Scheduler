#include <iostream>
#include <vector>
#include "../header/base.hpp"
#include "../header/sortstrategy.hpp"
#include "../header/task.hpp"
#include "../header/event.hpp"
#include "tasklist.cpp"

using namespace std;

/*
    So as of right now, I'm thinking that we are going to need to store our objects
    in a vector or some kind of list, and then we iterate over that list to
    save our data into a JSON file

    this would be so much easier in python but i found a framework that should help

    So when our app initializes we should parse through the json and collect all the objects
    so that we can edit & display them
    */

vector<Base*> allObjects;
vector<Task*> allTasks;
vector<TaskList*> allLists;
vector<Event*> allEvents;

void printAllTasks() {
    for(int i = 0; i < allTasks.size(); i++) {
        cout << i+1 << ". ";
        allTasks[i]->display();
    }
}

void addTaskToTaskList(TaskList* currList) {
    int userInput;
    printAllTasks();
    cout << "Select a task to add to this list by entering its number: ";
    cin >> userInput;
    Task* currTask = allTasks[userInput - 1];
    currList->addSubTask(currTask);
    cout << "Added task #" << userInput << " to the list." << endl;
    //currTask->setAssigned(true); setAssigned needs to be created
    return;
}

int main() {

    cout << "Hello World" << endl;

    return 0;
}