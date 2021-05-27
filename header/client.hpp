#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <vector>
#include <string>

//header files
#include "base.hpp"
#include "sortstrategy.hpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/event.cpp"


using namespace std;

class client {
	private:
		vector<Task> allTasks;
		vector<TaskList> allLists;
		vector<Event> allEvents;
		string sortingMethod;
	public:
		//constructor
		client();
		~client();

		void displayMenu();
		
		void load();
		void save();
		void clear();


		//print functions
		void view();
		void printAll();
		//print all unassigned tasks 
		void printTasks();
		//print all unassigned taskLists and their queues
		void printLists();
		//print all events
		void printEvents(); 

		//sort function
		void setSortingMethod();
		
		//completed functions
		//might want to pass in the object by reference to call .setCompleted on it
		//if task is assigned, find it in the correct taskList, then set as completed
		//if task is not assigned, mark as completed from allTasks vector
		void markAsCompleted();

		
		//create functions
		void create();
		void createTask();
		void createList();
		void createEvent();	

		
		//edit functions
		void addTaskToTaskList(TaskList &currList);	
		void addListToEvent(Event &currEvent);



		//edit functions
		void editList(TaskList &currObject);
		void editEvent(Event &currObject);
		void editTask(Task &currObject);


		//delete functions
		//these need to find and erase the objects from the vectors & the priorityQueues
		void delTask();
		void delList();
		void delEvent();


};

#endif //MENU_HPP
