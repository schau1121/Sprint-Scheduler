#ifndef CLIENT_CPP
#define CLIENT_CPP

#include "../header/client.hpp"

using json = nlohmann::json;
using namespace std;

void client::load() {
    ifstream in;
    in.open("save.json");
    if(!in.is_open()) {
        cout << "Error opening save.json" << endl;
    }
    json j;
    in >> j;

    for(auto currTask: j["Tasks"]) {
        string name = currTask["Name"];
        string dueDate = currTask["Due Date"];
        string details = currTask["Details"];
        int priority = currTask["Priority"];
        bool completed = currTask["Completed"];
        bool assigned = currTask["Assigned"];
        Task task = Task(name, dueDate, details, priority);
        task.setAssigned(assigned);
        task.setCompleted(completed);
        allTasks.push_back(task);
    }

    for(auto currList: j["Task Lists"]) {
        string name = currList["Name"];
        string details = currList["Details"];
        int priority = currList["Priority"];
        bool completed = currList["Completed"];
        bool assigned = currList["Assigned"];
        TaskList list = TaskList(name, details, priority);
        list.setAssigned(assigned);
        list.setCompleted(completed);
        for(auto currSubTask: currList["Sub Tasks"]) {
            string name = currSubTask["Name"];
            string dueDate = currSubTask["Due Date"];
            string details = currSubTask["Details"];
            int priority = currSubTask["Priority"];
            bool completed = currSubTask["Completed"];
            Task task = Task(name, dueDate, details, priority);
            task.setCompleted(completed);
            list.addSubTask(task);
        }
        allLists.push_back(list);
    }

    for(auto currEvent: j["Events"]) {
        string name = currEvent["Name"];
        string date = currEvent["Date"];
        string time = currEvent["Time"];
        string details = currEvent["Details"];
        double duration = currEvent["Duration"];
        Event event = Event(name, date, time, details, duration);
        for(auto currSubList: currEvent["Sub Lists"]) {
            string name = currSubList["Name"];
            string details = currSubList["Details"];
            int priority = currSubList["Priority"];
            bool completed = currSubList["Completed"];
            TaskList list = TaskList(name, details, priority);
            list.setCompleted(completed);
            for(auto currSubTask: currSubList["Sub Tasks"]) {
                string name = currSubTask["Name"];
                string date = currSubTask["Due Date"];
                string details = currSubTask["Details"];
                int priority = currSubTask["Priority"];
                bool completed = currSubTask["Completed"];
                Task task = Task(name, date, details, priority);
                task.setCompleted(completed);
                list.addSubTask(task);
            }
            event.addSubTask(list);
        }
        allEvents.push_back(event);
    }

    in.close();
}

void client::clear() {
    ofstream out;
    out.open("save.json", ofstream::out | ofstream::trunc);
    out.close();
}

void client::save() {
    clear();
    ofstream out;
    out.open("save.json");
    if(out.is_open()) {
        cout << "Saving..." << endl;
        json j;
        for(int i = 0; i < allTasks.size(); i++) {
            json currTask;
            currTask["Name"] = allTasks[i].getName();
            currTask["Due Date"] = allTasks[i].getDate();
            currTask["Details"] = allTasks[i].getDetails();
            currTask["Priority"] = allTasks[i].getPriority();
            currTask["Completed"] = allTasks[i].isCompleted();
            currTask["Assigned"] = allTasks[i].isAssigned();
            j["Tasks"].push_back(currTask);
        }
        for(int i = 0; i < allLists.size(); i++) {
            json currList;
            currList["Name"] = allLists[i].getName();
            currList["Details"] = allLists[i].getDetails();
            currList["Priority"] = allLists[i].getPriority();
            currList["Completed"] = allLists[i].isCompleted();
            currList["Assigned"] = allLists[i].isAssigned();
            for(int j = 0; j < allLists[i].getQueue().size(); j++) {
                json subTask;
                vector<Task> queue = allLists[i].getQueue();
                subTask["Name"] = queue[j].getName();
                subTask["Due Date"] = queue[j].getDate();
                subTask["Details"] = queue[j].getDetails();
                subTask["Priority"] = queue[j].getPriority();
                subTask["Completed"] = queue[j].isCompleted();
                currList["Sub Tasks"].push_back(subTask);
            }
            j["Task Lists"].push_back(currList);
        }
        for(int i = 0; i < allEvents.size(); i++) {
            json currEvent;
            currEvent["Name"] = allEvents[i].getName();
            currEvent["Date"] = allEvents[i].getDate();
            currEvent["Time"] = allEvents[i].getTime();
            currEvent["Details"] = allEvents[i].getDetails();
            currEvent["Duration"] = allEvents[i].getDuration();
            for(int j = 0; j < allEvents[i].getQueue().size(); j++) {
                vector<TaskList> subLists = allEvents[i].getQueue();
                json currList;
                currList["Name"] = subLists[j].getName();
                currList["Details"] = subLists[j].getDetails();
                currList["Priority"] = subLists[j].getPriority();
                currList["Completed"] = subLists[j].isCompleted();
                for(int l = 0; l < subLists[j].getQueue().size(); l++) {
                    json subTask;
                    vector<Task> queue = subLists[j].getQueue();
                    subTask["Name"] = queue[l].getName();
                    subTask["Due Date"] = queue[l].getDate();
                    subTask["Details"] = queue[l].getDetails();
                    subTask["Priority"] = queue[l].getPriority();
                    subTask["Completed"] = queue[l].isCompleted();
                    currList["Sub Tasks"].push_back(subTask);
                }
                currEvent["Sub Lists"].push_back(currList);
            }
            j["Events"].push_back(currEvent);
        }
        out << setw(4) << j;
    }
    else {
        cout << "Error opening save.json" << endl;
    }
    out.close();
}


client::client() {
	//call load function to populate the vector data members
	load();
	this->sortingMethod = "priority"; //default sorting method
}

client::~client() {
    save();
}


void client::view() {
	char choice = ' ';

	cout << "Enter a or A to view all." << endl;
	cout << "Enter t or T to view tasks." << endl;
	cout << "Enter l or L to view tasklists." << endl;
	cout << "Enter e or E to view events." << endl;

	cin >> choice;

	while(choice != 'q' && choice != 'Q') {

		if(choice == 'a' || choice == 'A') {  printAll();    break; }
		if(choice == 't' || choice == 'T') {  printTasks();  break; }
		if(choice == 'l' || choice == 'L') {  printLists();  break; }
		if(choice == 'e' || choice == 'E') {  printEvents(); break; }
		
		else { cout << "Invalid character or string entered." << endl;
		       cout << "Please enter a valid character: " << endl;
		       cin >> choice;
		}

	
	}
}

void client::create() {
	char choice = ' ';
	
	cout << "Enter t or T to create a task." << endl;
	cout << "Enter l or L to create a list." << endl;
	cout << "Enter e or E to create an event." << endl;
	cout << "Enter q or Q to quit." << endl;
	
	cin >> choice;

	while(choice != 'q' && choice != 'Q') {

	  if(choice == 'e' || choice == 'E') {
		  createEvent();
		  break;
	  }

	  if(choice == 'l' || choice == 'L') {
		  createList();
		  break;
	  }

	  if(choice == 't' || choice == 'T') {
		  createTask();
		  break;
	  }
	
	  else{
      cout << "Invalid character or string entered." << endl;
      cout << "Please enter a valid character: " << endl;
      cin >> choice;
	  }
	}
}

/*
    Add in parameter for string stream into display function to test that
    shouldn't need to test print functions since they should just loop over the vector and call display(cout)
*/

void client::printAll() {

	if(allTasks.size() == 0 && allLists.size() == 0 && allEvents.size() == 0) {
		cout << "There is nothing to display." << endl; 
		return;
	}

	this->printEvents();
	this->printLists();
	this->printTasks();	
}

void client::printTasks() {

	if(allTasks.size() == 0) { cout << "There are no tasks to display." << endl; return; }

	for(int i = 0; i < allTasks.size(); i++) {
		if(!(allTasks.at(i).isAssigned())) {
			cout << (i+1) << ". ";
			allTasks.at(i).display();
			cout << endl;
		}
	}
}

void client::printLists() {

	if(allLists.size() == 0) { cout << "There are no lists to display." << endl; return; }

 	for(int i = 0; i < allLists.size(); i++) {
		cout << (i+1) << ". ";
		allLists.at(i).display();
		cout << endl;

	}   
}

void client::printEvents() {

	if(allEvents.size() == 0) { cout << "There are no events to display." << endl; return; }

	for(int i = 0; i < allEvents.size(); i++) {
		cout << (i+1) << ". ";
		allEvents.at(i).display();
		cout << endl;

	}
}

/*
    Change date and time format check into bool functions and unit test those
*/
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
	
	cout << "Enter a date as MM/DD/YY: " << endl;
	cin >> date;
	while(date[2] != '/' || date[5] != '/') {
		cout << "Wrong date format entered!" << endl;
		cout << "Enter date format as MM/DD/YY: " << endl;
		cin >> date;
	}
    cin.ignore();
	cout << "Enter an event starting time HH:MM AM/PM: " << endl;
	getline(cin, time);
	while(time[2] != ':' || time.substr(6,7) != "AM" && time.substr(6,7) != "PM" && time.substr(6,7) != "am" && time.substr(6,7) != "pm") {
        cout << "Wrong time format entered!" << endl;
        cout << "Enter time format as HH:MM AM/PM: " << endl;
        cin.ignore();
        getline(cin, time);
    }
	
	cout << "Enter event details: " << endl;
    cin.ignore();
	getline(cin, details);
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
    cin.ignore();

}

/*
    Change priority checking int function and unit test that
*/
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
    cin.ignore();
	getline(cin, details);
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

/*
    use date and priority checking functions from comments above in here 
*/

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
    cin.ignore();
    cout << "Enter task details: ";
    getline(cin, details);
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
    cin.ignore();
}

void client::setSortingMethod() {
    int userInput;
    cout << "1. Sort by due date" << endl;
    cout << "2. Sort by priority" << endl;
    cout << "How would you like to sort your task list?" << endl;
    cout << "Enter the number corresponding to which sort you'd like to use: ";
    cin >> userInput;
    while(userInput > 2 || userInput < 0) {
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

/*
    Use format checking functions from above in this as well
    Change edit function to take in parameter for string stream
    when called in gtest, define the string stream;
    in client, pass in cin
*/

void client::editTask(Task &currObject) {
    currObject.edit();
}

void client::editList(TaskList &currObject) {
    currObject.edit();
}

void client::editEvent(Event &currObject) {
    currObject.edit();
}

#endif
