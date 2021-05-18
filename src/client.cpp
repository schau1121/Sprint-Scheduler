#include "../header/base.hpp"
#include "../header/event.hpp"
#include "../header/client.hpp"
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
	allObjects.push_back(&newEvent);
	allEvents.push_back(newEvent);
	cout << "Event created!" << endl;	

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
    allObjects.push_back(&newTask);
    allTasks.push_back(newTask);
    cout << "\nCreated!" << endl;
}
