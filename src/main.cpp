#include <iostream>
#include <vector>
#include "../header/base.hpp"
#include "../header/sortstrategy.hpp"
#include "../header/sortdate.hpp"
#include "../header/sortpriority.hpp"
#include "../header/event.hpp"
#include "tasklist.cpp"
#include "task.cpp"


using namespace std;


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

void setSortingMethod(Base* currObject) {
    int userInput;
    cout << "1. Sort by due date" << endl;
    cout << "2. Sort by priority" << endl;
    cout << "How would you like to sort your task list?" << endl;
    cout << "Enter the number corresponding to which sort you'd like to use: ";
    cin >> userInput;
    while(userInput != 1 || userInput != 2) {
        cout << "\nERROR: Enter either 1 or 2: ";
        cin >> userInput;
    }
    if(userInput == 1) {
        currObject->setStrategy(new SortByDate());
    }
    if(userInput == 2) {
        currObject->setStrategy(new SortByPriority());
    }
    cout << "\nSorting strategy selected!" << endl;
}

void addTaskToTaskList(Base* currList) {
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

	return 0;
}
