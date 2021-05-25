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
	getline(cin, name);
	while(name == "") {
		cout << "No event name entered!" << endl;
		cout << "Please enter an event name: " << endl;
		getline(cin, name);
	}
	
	cout << "Enter a due date as MM/DD/YY: " << endl;
	cin >> date;
	while(date[2] != '/' || date[5] != '/') {
		cout << "Wrong date format entered!" << endl;
		cout << "Enter date format as MM/DD/YY: " << endl;
		cin >> date;
	}

	cout << "Enter an event starting time HH:MM AM/PM: " << endl;
	cin >> time;
	while(time[2] != ':' || time.substr(6,7) != "AM" && time.substr(6,7) != "PM" && time.substr(6,7) != "am" && time.substr(6,7) != "pm") {
                cout << "Wrong time format entered!" << endl;
                cout << "Enter time format as HH:MM AM/PM: " << endl;
                cin >> time;
        }
	
	cout << "Enter event details: " << endl;
	getline(cin, details);
	while(details == "") {
                cout << "No event details entered!" << endl;
                cout << "Please enter event details: " << endl;
                getline(cin, details);
        }

	cout << "Enter event duration in hours: " << endl;
	cin >> duration; 
	while(duration == 0) {
                cout << "No event duration entered!" << endl;
                cout << "Please enter event duration: " << endl;
                cin >> duration;
        }

	Event newEvent = Event(name, date, time, details, duration);
	allEvents.push_back(newEvent);
	cout << "Event created!" << endl;	

}

void client::createList(){

	string name = "";
	string details = "";
	int priority = -1;

	cout << "Creating a task list..." << endl;
	
	cout << "Enter a task list name: " << endl;
	getline(cin, name);	
	while(name == "") {
                cout << "No task list name entered!" << endl;
                cout << "Please enter a task list name: " << endl;
                getline(cin, name);
        }

	cout << "Enter task list details: " << endl;
	getline(cin, details);
	while(details == "") {
                cout << "No task list details entered!" << endl;
                cout << "Please enter task list details: " << endl;
                getline(cin, details);
        }

	cout << "Enter task list priority 0-5: " << endl;
	cin >> priority;
	while(priority < 0 || priority > 5) {
		cout << "Invalid priority entered!" << endl;
		cout << "Please enter a priority from 0-5: " << endl;
		cin >> priority;
	}	

	TaskList newList = TaskList(name, details, priority);
	allLists.push_back(newList);

	cout << "Task list created!" << endl;
} 


void client::createTask() {
        
	string name = "";
        string date = "";
        string details = "";
        int priority = -1;
        
	cout << "Creating a task..." << endl;
 
        cout << "Enter a name: ";
        getline(cin, name);
	while(name == "") {
                cout << "No task name entered!" << endl;
                cout << "Please enter a task name: " << endl;
                getline(cin, name);
        }      
 
        cout << "Enter a due date as MM/DD/YY: ";
        cin >> date;
	while(date[2] != '/' || date[5] != '/') {
                cout << "Wrong date format entered!" << endl;
                cout << "Enter date format as MM/DD/YY: " << endl;
                cin >> date;
        }

        cout << "Enter task details: ";
        getline(cin, details);
 	while(details == "") {
                cout << "No task list details entered!" << endl;
                cout << "Please enter task list details: " << endl;
                getline(cin, details);
        }
      

	cout << "Enter task priority as 0-5: ";
        cin >> priority;
  	while(priority < 0 || priority > 5) {
                cout << "Invalid priority entered!" << endl;
                cout << "Please enter a priority from 0-5: " << endl;
                cin >> priority;
        }
 
        Task newTask = Task(name, date, details, priority);
        allTasks.push_back(newTask);
        cout << "Task created!" << endl;
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

void client::addTaskToTaskList(TaskList &currList) {
    char userInput = ' ';
    while(userInput != 'q' || userInput != 'Q') {
        if(allTasks.empty() == true) {
            cout << "ERROR: There are no tasks created" << endl;
            //can add option to create a task
            return;
        }
        cout << "Printing all unassigned tasks..." << endl;
        printTasks();
        cout << "Enter the number of the task you would like to add to this list: ";
        cin >> userInput;
        while((int)userInput > allTasks.size() || (int)userInput < 0) {
            cout << "ERROR: Invalid input" << endl;
            cout << "Enter the number of the task you would like to add to this list: ";
            cin >> userInput;
        }
        if(!allTasks[userInput - 1].isAssigned()) {
            cout << "Adding " << '\"' << allTasks[(int)userInput - 1].getName() << '\"...' << endl;
            currList.addSubTask(allTasks[(int)userInput - 1]);
            allTasks[(int)userInput - 1].setAssigned(true);
            cout << "Successfully added to this list!" << endl;
            cout << "Enter 'q' to quit or 'c' to continue adding tasks to this list: ";
            cin >> userInput;
        }
        else {
            cout << "ERROR: Task is assigned already" << endl;
            userInput = 'q';
        }
    }
}

void client::addListToEvent(Event &currEvent) {
    char userInput = ' ';
    while(userInput != 'q' || userInput != 'Q') {
        if(allLists.empty() == true) {
            cout << "ERROR: There are no lists created" << endl;
            return;
        }
        cout << "Printing all unassigned lists..." << endl;
        printLists();
        cout << "Enter the number of the list you would like to add to this list (or enter 'q' to quit): ";
        cin >> userInput;
        while((int)userInput > allTasks.size() || (int)userInput < 0) {
            cout << "ERROR: Invalid input" << endl;
            cout << "Enter the number of the list you would like to add to this event: ";
            cin >> userInput;
        }
        if(!allLists[userInput - 1].isAssigned()) {
            cout << "Adding " << '\"' << allLists[(int)userInput - 1].getName() << '\"...' << endl;
            currEvent.addSubTask(allLists[(int)userInput - 1]);
            allLists[(int)userInput - 1].setAssigned(true);
            cout << "Successfully added to this event!" << endl;
            cout << "Enter 'q' to quit or 'c' to continue adding lists to this event: ";
            cin >> userInput;
        }
        else {
            cout << "ERROR: List is assigned already" << endl;
            userInput = 'q';
        } 
    }
}


