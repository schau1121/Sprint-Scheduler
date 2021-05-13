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
vector<Base*> allTasks;
vector<Base*> allLists;
vector<Base*> allEvents;

void printAllTasks() {
    for(int i = 0; i < allTasks.size(); i++) {
        //if(!allTasks[i]->isAssigned()) { isAssigned neets to be created
            cout << i+1 << ". ";
            allTasks[i]->display();
        //}
    }
}

void addTaskToTaskList(TaskList* currList) {
    int userInput;
    printAllTasks();
    cout << "Select a task to add to this list by entering its number: ";
    cin >> userInput;
    Base* currTask = allTasks[userInput - 1];
    currList->addSubTask(currTask);
    cout << "Added task #" << userInput << " to the list." << endl;
    //currTask->setAssigned(true); setAssigned needs to be created
    return;
}

//User can only store one line of details as of right now
void createTask() {
    string name;
    string date = "";
    string details = "";
    int priority = 0;
    cout << "Creating a task..." << endl;
    cout << "Enter a name: ";
    cin >> name;
    if(name == "") {
        cout << "ERROR: NEED TASK NAME" << endl;
        return;
    }
    cout << "\nEnter a due date as MM/DD/YY: ";
    cin >> date;
    cout << "\nEnter details: ";
    getline(cin, details);
    cout << "\nEnter priority as 0-5: ";
    cin >> priority;
    Base* newTask = new Task(name, date, details, priority);
    allObjects.push_back(newTask);
    allTasks.push_back(newTask);
    cout << "\nCreated!" << endl;
}

int main() {

    cout << "Hello World" << endl;

    return 0;
}