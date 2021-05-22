#include "../header/base.hpp"
#include "../header/event.hpp"
#include "../header/client.hpp"
#include "../header/task.hpp"

void client::createEvent() {

	string name = "";
	string date = "";
	string time = "";
	string details = "";
	double duration = 0;
		
	cout << "Creating an event..." << endl;
	
	cout << "Enter a name: " << endl;
	cin >> name;
	if(name == "") {
		cout << "ERROR: NEED AN EVENT NAME." << endl;
		return;
	}
	
	cout << "Enter a due date as MM/DD/YY: " << endl;
	cin >> date;

	cout << "Enter an event starting time as MONTH/DAY/HOUR: " << endl;
	cin >> time;
	
	cout << "Enter event details: " << endl;
	getline(cin, details);

	cout << "Enter event duration in hours: " << endl;
	cin >> duration; 

	Event newEvent = Event(name, date, time, details, duration);
	allEvents.push_back(newEvent);
	cout << "Event created!" << endl;	

}

void client::createList(){

	string name = "";
	string details = "";
	int priority = 0;

	cout << "Creating a task list..." << endl;
	
	cout << "Enter a task list name: " << endl;
	cin >> name;
	
	if(name == "") {
	cout << "ERROR: NEED TASK LIST NAME" << endl;
	return;
	}

	cout << "Enter task list details: " << endl;
	getline(cin, details);

	cout << "Enter task list priority 0-5: " << endl;
	cin >> priority;

	TaskList newList = TaskList(name, details, priority);
	allLists.push_back(newList);

	cout << "Task list created!" << endl;
} 


void client::createTask() {
    string name;
    string date = "";
    string details = "";
    int priority = 0;
    cout << "Creating a task..." << endl;
    cout << "Enter a name: ";
    cin >> name;
    while(name == "") {
        cout << "ERROR: NEED TASK NAME" << endl;
        cout << "Enter a name: ";
        cin >> name;
    }
    cout << "\nEnter a due date as MM/DD/YY: ";
    cin >> date;
    cout << "\nEnter details: ";
    getline(cin, details);
    cout << "\nEnter priority as 0-5: ";
    cin >> priority;
    Task newTask = Task(name, date, details, priority);
    allTasks.push_back(newTask);
    cout << "\nCreated!" << endl;
}

void client::setSortingMethod() {
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
        sortingMethod = "date";
    }
    if(userInput == 2) {
        sortingMethod = "priority";
    }
    cout << "\nSorting strategy selected!" << endl;
}
