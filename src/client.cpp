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
        return;
    }
    json j;
    in >> j;
    if(j.is_null()) {
        return;
    }
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
    allLists.clear();
    allEvents.clear();
    allTasks.clear();
}

void client::save() {
    ofstream out;
    out.open("save.json", ofstream::out | ofstream::trunc);
    if(out.is_open()) {
        //cout << "Saving..." << endl;
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

void client::displayMenu() {
	char choice = ' ';
	int runTime = 0;
	
	if(runTime == 0) { cout << "Welcome to your task scheduler!" << endl; }

	while((choice != 'q' && choice != 'Q') || runTime < 1000) {
		cout << "----Main Menu----" << endl;
		cout << "Enter v or V to view your tasks, lists, and events." << endl;
        cout << "Enter c or C to create new tasks, lists, or events." << endl;
        cout << "Enter s or S to set sorting method." << endl;
        cout << "Press q or Q to quit." << endl;
		
		cin >> choice;


		if(choice == 's' || choice == 'S') {
			setSortingMethod();
            runTime++;
            continue;
		}

		else if(choice == 'v' || choice == 'V') {  
            view();

            cout << "Enter e or E to edit." << endl;
            cout << "Enter d or D to delete." << endl;
            cout << "Enter m or M to mark as complete." << endl;
            cout << "Enter r or R to return to the main menu." << endl;
            cin >> choice;
            
            if(choice == 'r' || choice == 'R') {
                runTime++;
                continue;
            }

            if(choice == 'e' || choice == 'E') { 
                cout << "Enter t or T to edit a task." << endl;
                cout << "Enter l or L to edit a list." << endl;
                cout << "Enter e or E to edit an event." << endl; 
                cout << "Press q or Q to quit." << endl;

                cin >> choice;
                            
                if(choice == 't' || choice == 'T') {  
                        printTasks();
                        cout << "Input the task to edit: " << endl;
                        int thisTask;
                        cin >> thisTask;
                        while(thisTask > allTasks.size() || thisTask < 1) {
                            cout << "Invalid input" << endl;
                            cout << "Please enter a valid input: " << endl;
                            cin >> thisTask;
                        }
                        editTask(allTasks.at(thisTask - 1));
                        runTime++;
                        continue;				       				       
                }

                if(choice == 'l' || choice == 'L') {  
                    printLists();
                    cout << "Input the list to edit: " << endl;
                    int thisList;
                    cin >> thisList;
                    while(thisList > allLists.size() || thisList < 1) {
                        cout << "Invalid input" << endl;
                        cout << "Please enter a valid input: " << endl;
                        cin >> thisList;
                    }
                    editList(allLists.at(thisList - 1));
                    runTime++;
                    continue;
                }
                if(choice == 'e' || choice == 'E') {  
                    printEvents();
                    cout << "Input the event to edit: " << endl;
                    int thisEvent;
                    cin >> thisEvent;
                    while(thisEvent > allEvents.size() || thisEvent < 1) {
                            cout << "Invalid input" << endl;
                            cout << "Please enter a valid input: " << endl;
                            cin >> thisEvent;
                        }
                    editEvent(allEvents.at(thisEvent - 1));
                    runTime++;
                    continue;
                }
			}
			else if(choice == 'd' || choice == 'D') {
				Delete();
			}
			else if(choice == 'm' || choice == 'M') {
                cout << "Enter t or T to mark a task." << endl;
                cout << "Enter l or L to mark a list." << endl;
                cout << "Enter e or E to mark an event." << endl;
                cout << "Press q or Q to quit." << endl;

                cin >> choice;
                
                if(choice == 'q' || choice == 'Q') { break; }	
					
                if(choice == 't' || choice == 'T') {
                    if(allTasks.size() == 0) {
                        cout << "Nothing to mark." << endl;
                        break;
                    } 
					for(int i = 0; i < allTasks.size(); i++) {
                        if(!allTasks[i].isCompleted()) {
                            cout << (i+1) << ". ";
                            allTasks[i].display(cout);
                            cout << endl;
                        }
                    }
                    cout << "Input the task to mark: " << endl;
                    int thisTaskI;
                    cin >> thisTaskI;
                    markAsCompletedT(allTasks.at(thisTaskI - 1));
                    runTime++;
                    continue;
                }
                if(choice == 'l' || choice == 'L') {
                    if(allLists.size() == 0) {
                        cout << "Nothing to mark." << endl;
                        break;
                    }
					for(int i = 0; i < allLists.size(); i++) {
                        cout << (i+1) << ". ";
                        allLists[i].display(cout);
                        cout << endl;
                    }
                    cout << "Input the list to mark: " << endl;
                    int thisListI;
                    cin >> thisListI;
                    markAsCompletedL(allLists.at(thisListI - 1));
                    runTime++;
                    continue;
                }
                if(choice == 'e' || choice == 'E') {
					if(allEvents.size() == 0) {
                        cout << "Nothing to mark." << endl;
                        break;
                    }                                              
                    printEvents();
                    cout << "Input the event to mark: " << endl;
                    int thisEventI;
                    cin >> thisEventI;
                    markAsCompletedE(allEvents.at(thisEventI - 1));
                    runTime++;
                    continue;
                }
			}                   
		}

        else if(choice == 'c' || choice == 'C') {  
            create();
            runTime++; 
            continue;
        }
        else if(choice == 'q' || choice == 'Q') { 
            break;
        }
		else { 
            cout << "Invalid character or string entered." << endl;
            cout << "Please enter a valid character: " << endl;
        }	
		runTime++;
	}
	cout << "Goodbye!" << endl;
}

void client::markAsCompletedT(Task &obj) {
	int index;
    if(!obj.isAssigned()) {
		obj.setCompleted(true);
		cout << "Success!" << endl;
	}
    else {
        for(int i = 0; i < allLists.size(); i++) {
            vector<Task> &queue = allLists[i].priorityQueue;
            for(int j = 0; j < queue.size(); j++) {
                if(queue[j].getName() == obj.getName()) {
                    queue[j].setCompleted(true);
                    index = i;
                    break;
                }
            }
            break;
        }
        if(allLists[index].isAssigned()) {
            for(int i = 0; i < allEvents.size(); i++) {
                vector<TaskList> &queue = allEvents[i].priorityQueue;
                for(int j = 0; j < queue.size(); j++) {
                    if(queue[j].getName() == allLists[index].getName()) {
                        vector<Task> &subTasks = queue[j].priorityQueue;
                        for(int l = 0; l < subTasks.size(); l++) {
                            if(subTasks[l].getName() == obj.getName()) {
                                subTasks[l].setCompleted(true);
                            }
                        }
                    }
                }
            }
        }
    }

}

void client::markAsCompletedL(TaskList &obj) {
	if(obj.isCompleted()) {
        obj.setCompleted(true);
        if(obj.isAssigned()) {
            for(int i = 0; i < allEvents.size(); i++) {
                vector<TaskList> &queue = allEvents[i].priorityQueue;
                for(int j = 0; j < queue.size(); j++) {
                    if(queue[j].getName() == obj.getName()) {
                        queue[j].setCompleted(true);
                    }
                }
            }
        }
    }
}

void client::markAsCompletedE(Event &obj) {}

void client::view() {
	char choice = ' ';

	cout << "Enter a or A to view all." << endl;
	cout << "Enter t or T to view tasks." << endl;
	cout << "Enter l or L to view tasklists." << endl;
	cout << "Enter e or E to view events." << endl;
    cout << "Enter p or P to push an event." << endl;

	cin >> choice;

	while(choice != 'q' && choice != 'Q') {

		if(choice == 'a' || choice == 'A') {  printAll();    break; }
		if(choice == 't' || choice == 'T') {  printTasks();  break; }
		if(choice == 'l' || choice == 'L') {
            printLists();
            cout << "Would you like to add a task to a list? (y/n)" << endl;
            char newChoice;
            int index;
            cin >> newChoice;
            if(newChoice == 'y') {
                cout << "Input the list to add a sub task to: ";
                cin >> index;
                addTaskToTaskList(allLists[index - 1]);
                return;
            }
            else {
                break;
            }
        }
		if(choice == 'e' || choice == 'E') {  
            printEvents(); 
            cout << "Would you like to add a list to a event? (y/n)" << endl;
            char newChoice;
            int index;
            cin >> newChoice;
            if(newChoice == 'y') {
                cout << "Input the event to add a sub list to: ";
                cin >> index;
                addListToEvent(allEvents[index - 1]);
                return;
            }
            else {
                break;
            }
        }
		if(choice == 'p' || choice == 'P') {
            printEvents();
            cout << "Which event would you like to push?" << endl;
            int eventIndex;
            cin >> eventIndex;
            allEvents[eventIndex - 1].pushEvent();
            return;
        }

		else {
            cout << "Invalid character or string entered." << endl;
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
    cout << "----Tasks----" << endl;
	if(allTasks.size() == 0 || allAssigned(allTasks)) { cout << "There are no tasks to display." << endl; return; }

	for(int i = 0; i < allTasks.size(); i++) {
		if(!(allTasks.at(i).isAssigned())) {
			cout << (i+1) << ". ";
			allTasks.at(i).display(cout);
			cout << endl;
		}
	}
}

void client::printLists() {
    for(int i = 0; i < allLists.size(); i++) {
        allLists[i].setStrategy(sortingMethod);
    }
    cout << "----Task Lists----" << endl;
	if(allLists.size() == 0 || allAssigned(allLists)) { cout << "There are no lists to display." << endl; return; }

 	for(int i = 0; i < allLists.size(); i++) {
        if(!allLists[i].isAssigned()) {
            cout << (i+1) << ". ";
            allLists.at(i).display(cout);
            cout << endl;
        }
	}   
}

void client::printEvents() {
    for(int i = 0; i < allEvents.size(); i++) {
        for(int j = 0; j < allEvents[i].priorityQueue.size(); j++) {
            allEvents[i].priorityQueue[j].setStrategy(sortingMethod);
        }
    }
    cout << "----Events----" << endl;
	if(allEvents.size() == 0) { cout << "There are no events to display." << endl; return; }

	for(int i = 0; i < allEvents.size(); i++) {
		cout << (i+1) << ". ";
		allEvents.at(i).display(cout);
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
	cin.ignore();
	cout << "Enter a name: " << endl;
	getline(cin, name);
	while(name == "") {
	  cout << "No event name entered!" << endl;
	  cout << "Please enter an event name: " << endl;
	  getline(cin, name);
	}
	
	cout << "Enter a date as MM/DD/YY: " << endl;
	cin >> date;
	if(!check_date_format(date)) {
		cout << "Wrong date format entered!" << endl;
		cout << "Enter date format as MM/DD/YY: " << endl;
		cin >> date;
	}
	cin.ignore();
	cout << "Enter an event starting time HH:MM AM/PM: " << endl;
	getline(cin, time);
	if(!check_time_format(time)) {
        cout << "Wrong time format entered!" << endl;
        cout << "Enter time format as HH:MM AM/PM: " << endl;
        getline(cin, time);
    }
	//cin.ignore();
	cout << "Enter event details: " << endl;
	getline(cin, details);
	cout << "Enter event duration in hours: " << endl;
	cin >> duration; 
	while(duration <= 0) {
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

	cout << "Creating task list..." << endl;
	cin.ignore();
	cout << "Enter a task list name: " << endl;
	getline(cin, name);	
	while(name == "") {
        cout << "No task list name entered!" << endl;
        cout << "Please enter a task list name: " << endl;
        getline(cin, name);
    }
//    cin.ignore();
	cout << "Enter task list details: " << endl;
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
    cin.ignore();
    cout << "Enter a name: ";
    getline(cin, name);
	while(name == "") {
        cout << "No task name entered!" << endl;
        cout << "Please enter a task name: " << endl;
        getline(cin, name);
    }      
 
        cout << "Enter a due date as MM/DD/YY: ";
        cin >> date;
	if(!check_date_format(date)) {
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
    int userInput;

    if(allTasks.empty() == true) {
        cout << "ERROR: There are no tasks created" << endl;
        //can add option to create a task
        return;
    }
    cout << "Printing all unassigned tasks..." << endl;
    printTasks();
    if(allAssigned(allTasks)) {
        return;
    }
    cout << "Enter the number of the task you would like to add to this list: ";
    cin >> userInput;
    while(userInput > allTasks.size() || userInput < 0) {
        cout << "ERROR: Invalid input" << endl;
        cout << "Enter the number of the task you would like to add to this list: ";
        cin >> userInput;
    }
    if(!allTasks[userInput - 1].isAssigned()) {
        cout << "Adding " << allTasks[userInput - 1].getName() << "..." << endl;
        currList.addSubTask(allTasks[userInput - 1]);
        allTasks[userInput - 1].setAssigned(true);
        cout << "Successfully added to this list!" << endl;
    }
    else {
        cout << "ERROR: Task is assigned already" << endl;
    }
}

void client::addListToEvent(Event &currEvent) {
    int userInput;
    if(allLists.empty() == true) {
        cout << "ERROR: There are no lists created" << endl;
        return;
    }
    cout << "Printing all unassigned lists..." << endl;
    printLists();
    if(allAssigned(allLists)) {
        return;
    }
    cout << "Enter the number of the list you would like to add to this list: ";
    cin >> userInput;
    while(userInput > allTasks.size() || userInput < 0) {
        cout << "ERROR: Invalid input" << endl;
        cout << "Enter the number of the list you would like to add to this event: ";
        cin >> userInput;
    }
    if(!allLists[userInput - 1].isAssigned()) {
        cout << "Adding " << allLists[userInput - 1].getName() << "..." << endl;
        currEvent.addSubTask(allLists[userInput - 1]);
        allLists[userInput - 1].setAssigned(true);
        cout << "Successfully added to this event!" << endl;
    }
    else {
        cout << "ERROR: List is assigned already" << endl;
    } 
}

/*
    Use format checking functions from above in this as well
    Change edit function to take in parameter for string stream
    when called in gtest, define the string stream;
    in client, pass in cin
*/

void client::editTask(Task &currObject) {
    currObject.edit(cin);
}

void client::editList(TaskList &currObject) {
    currObject.edit(cin);
}

void client::editEvent(Event &currObject) {
    currObject.edit(cin);
}

void client::Delete(){

	char choice = ' ';
	
	cout << "Enter t or T to delete a task." << endl;
	cout << "Enter l or L to delete a list." << endl;
	cout << "Enter e or E to delete an event." << endl;
    cout << "Enter a or A to delete all" << endl;
	cout << "Enter q or Q to quit." << endl;
	
	cin >> choice;

	while(choice != 'q' && choice != 'Q'){

	  if(choice == 'e' || choice == 'E') {
	    deleteEvent();
	    break;
	  }

	  else if(choice == 'l' || choice == 'L') {
	    deleteList();
	    break;
	  }

	  else if(choice == 't' || choice == 'T') {
	    deleteTask();
	    break;	
	  }	

      else if(choice == 'a' || choice == 'A') {
          clear();
          break;
      }
	  else {
    	    cout << "Invalid character or string entered." << endl;
            cout << "Please enter a valid character: " << endl;
    	    cin >> choice;
        }
 }
}


void client::deleteEvent(){
	int choice = -1; 
	int index = 0;
    for(int i = 0; i < allEvents.size(); i++) {
        cout << (i + 1) << ". ";
        allEvents[i].display(cout);
        cout << endl;
    }
	cout << "Please enter the index of which event you would like to delete: " << endl;
	cin >> choice; 

	while(choice < 0 || choice > allEvents.size()) { 
	  cout << "Choice is out of range." << endl;
	  cout << "Please enter a number between 1 and last index available." << endl;
	  cin >> choice;
	}

	allEvents.erase(allEvents.begin() + choice - 1);
}


void client::deleteList(){
    string taskListName;
	int choice = -1;
	int index = 0;
    for(int i = 0; i < allLists.size(); i++) {
        cout << (i + 1) << ". ";
        allLists[i].display(cout);
        cout << endl;
    }
	cout << "Please enter the index of which list you would like to delete: " << endl;
 	cin >> choice;

	while(choice < 1 || choice > allLists.size()) {
	  cout << "Choice is out of range." << endl;
	  cout << "Please enter a number between 1 and last index available." << endl;
	  cin >> choice;
	}

    taskListName = allLists[choice - 1].getName();

	if(allLists.at(choice - 1).isAssigned()){
	  for(int i = 0; i < allEvents.size(); i++) {
          vector<TaskList> &queue = allEvents[i].priorityQueue;
          for(int j = 0; j < queue.size(); j++) {
              if(queue[j].getName() == taskListName) {
                  queue.erase(queue.begin() + j);
                  break;
              }
          }
          break;
      }
	}
                
	allLists.erase(allLists.begin() + choice - 1);
}


void client::deleteTask(){ 
    string taskListName;
    string taskName;
    int taskListIndex = 0;
	int choice = -1;
    for(int i = 0; i < allTasks.size(); i++) {
        cout << (i + 1) << ". ";
        allTasks[i].display(cout);
        cout << endl;
    }
	cout << "Please enter the index of which task you would like to delete: " << endl;
 	cin >> choice;

	while(choice < 1 || choice > allTasks.size()) {
	  cout << "Choice is out of range." << endl;
	  cout << "Please enter a number between 1 and last index available." << endl;
	  cin >> choice;
	}

    taskName = allTasks[choice - 1].getName();

	if(allTasks.at(choice - 1).isAssigned()) {
        for(int i = 0; i < allLists.size(); i++) {
            vector<Task> &queue = allLists[i].priorityQueue;
            for(int j = 0; j < queue.size(); i++) {
                if(queue[j].getName() == taskName) {
                    taskListName = allLists[i].getName();
                    taskListIndex = i;
                    queue.erase(queue.begin() + j);	
                    break;
                }
            }
            break;
	    }
        if(allLists[taskListIndex].isAssigned()) {
            for(int i = 0; i < allEvents.size(); i++) {
                vector<TaskList> &queue = allEvents[i].priorityQueue;
                for(int j = 0; j < queue.size(); j++) {
                    if(queue[j].getName() == taskListName) {
                        vector<Task> &subTasks = queue[j].priorityQueue;
                        for(int l = 0; l < subTasks.size(); l++) {
                            if(subTasks[l].getName() == taskName) {
                                subTasks.erase(subTasks.begin() + l);
                            }
                        }
                    }
                }
            }
        }
	}

	allTasks.erase(allTasks.begin() + choice - 1);
}

void client::restart() {
    save();
    displayMenu();
}

#endif
