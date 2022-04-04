#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

//header files
#include "base.hpp"
#include "task.hpp"
#include "tasklist.hpp"
#include "event.hpp"
#include "sortstrategy.hpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/event.cpp"

using namespace std;

/*
	we might want to move the vectors into public so we can access them for testing
*/

class client {
	//private:
		// vector<Task> allTasks;
		// vector<TaskList> allLists;
		// vector<Event> allEvents;
		string sortingMethod;
	public:
		vector<Task> allTasks;
		vector<TaskList> allLists;
		vector<Event> allEvents;
		
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
		void markAsCompletedT(Task &obj);
		void markAsCompletedL(TaskList &obj);
		void markAsCompletedE(Event &obj);

		
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
		void Delete();
		void deleteTask();
		void deleteList();
		void deleteEvent();

		//need to stop current display menu call, then call restart
		void restart();
};

#endif //MENU_HPP
