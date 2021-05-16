#include "../header/client.hpp"

//need to add exception handling
void client::createTask() {
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

void client::printTasks() {
    for(int i = 0; i < allTasks.size(); i++) {
        if(!allTasks[i]->isAssigned()) {
            cout << i+1 << ". ";
            allTasks[i]->display();
        }
    }
}

