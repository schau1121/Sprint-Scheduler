# Sprint Scheduler [![CI](https://github.com/cs100/final-project-anguy589_spete020_schau014/actions/workflows/main.yml/badge.svg)](https://github.com/cs100/final-project-anguy589_spete020_schau014/actions/workflows/main.yml)
Authors: [Scott Peterson](https://github.com/scottyallenp), [Anh Nguyen](https://github.com/AnhQNguyen), [Simon Chau](https://github.com/schau1121)

## Things Learned
* Designing and Developing an application following Agile & Scrum methodologies
* Utilizing user stories to prioritize and plan sprints
* Implementing Object-Oriented Design principles
* Prioritizing time and space complexity during planning
* Authorizing requests to a Google API
* Utilizing a REST API
* Saving & parsing data to/from a JSON file

## Project Description
### User Experience
 We built a task management application where users can create and view personal tasks and events. This allows them to edit, mark as complete, and schedule these objects. Additionally, our application helps users visualize and prioritize their tasks by either due date or priority. When exiting the application, the user's data is saved so that when opened again, all pertinent information will be available automatically. Finally, this application allows users to "push" their created events to a personal google calendar with ease.
 ### Importance
 We find this project really important because it is a very practical application for us as college students. With classes, clubs, and our careers, it becomes increasingly difficult to manage our time, and we are sure that plenty of people can relate. By grouping tasks together and creating an "event" based productivity block, we believe that users of our service can maximize their productivity to the fullest. Additionally, we are interested in familiarizing ourselves with an API and since the documentation of the Google Calendar API is very thorough, we thought this project would be a perfect opportunity to learn and a great place to start.
 ### Tools and Technology
 * C++ -  An object-oriented programming language 
 * Nlohmann/json - A c++ library for parsing and creating json objects
 * Valgrind - A programming tool used for code profiling and debugging
 * Gtest - A unit and integration testing library for C++
 * CMake3 - A build automation tool
 * pybind11 - A library for embedding python into C++ code
 * Google Calendar API - An API which adds connectivity between this application and Google Calendar
 ### Application Input / Output
 The user will be able to create customized tasks inside an event by including: a string used for a short title, a string for a task description, a string for a classification tag, an integer determining the task’s priority, an integer for estimated task duration in hours, and a datetime string labeling the event time. Depending on the component that the user is creating (event/task) there will be different prompts for the user's input. For example, if a user creates an event, they will be prompted to input a datetime to schedule. Our application will output a list of tasks and events including their details, events will be prioritized based on their deadlines while tasks will be prioritized based on their rank in the priority queue. 
 ### Design Patterns
 * Composite
   * We chose to use the composite design pattern to implement a list of tasks or events composed of smaller tasks inside of them. With this pattern we plan to implement the basic interface which consists of editing, deleting, and creating tasks/events. An issue we anticipate encountering with our project is finding a balance between creating a simple interface for the user to interact with the components, while also maintaining separate functionality. With the composite pattern, objects are treated very similarly, and we plan on using polymorphism to our advantage to solve this problem.
 * Strategy
   * The strategy design pattern will be used to sort the priority queues within our application. Our task manager will consist of at least two different objects: tasks and events and possibly a task list in the future. This design pattern allows us to sort a user's task list by either priority or due date, depending on what the user prefers. An issue we plan on encountering with the composite design pattern is differentiating the functionality of the interface depending on component at runtime, however, with the strategy design pattern, this should be easily solved. As the user defines how he/she would like to sort their task list at runtime, our application will have the capability to sort by the specified strategy without issues. 

## Class Diagram
 ![CS100 Final Project (5)](https://user-images.githubusercontent.com/46959736/120133979-017fe400-c182-11eb-85fa-470e69a4c8c6.png)
 
 In our class diagram, we utilize the composite and strategy design patterns. Our application consists of 8 classes, 2 abstract and 6 concrete. For the composite design pattern, we have a base class which contains the pure virtual functions that make up the user interface. These functions are display, edit, delete, and add. Additionally, we have another function called setStrategy, which sets which sorting algorithm the user wants to utilize when displaying their tasks. From there, we have three objects which inherit from Base: Task, TaskList, and Event. These three objects maintain the same interface of display, edit, delete, and add, but additionally, they also contain specific data members unique to themselves. For example, a Task contains information about priority, completion, and a due date, while an Event contains duration, date, and time. Here we utilize the composite design pattern since TaskList and Event aggregate the base class in order to contain a priority queue of subtasks (which could be tasks, events, or task lists). Next, our application also utilizes the strategy pattern through our SortStrategy classes. We have two strategies which inherit from this base SortStrategy class: SortByPriority and SortByDate. These two classes contain a sort function which will sort the priority queue by either priority or due date.
 
 
 ## Screenshots
 Creating tasks:  
 ![create task 1](https://user-images.githubusercontent.com/46959736/120373464-3ba9cc80-c2cd-11eb-9398-ec0ab2991a4a.png) ![create task 2](https://user-images.githubusercontent.com/46959736/120373465-3ba9cc80-c2cd-11eb-9255-2b07b9920fd2.png) ![create task 3](https://user-images.githubusercontent.com/46959736/120373468-3ba9cc80-c2cd-11eb-83f6-ffda010e5dfb.png)
 
 Creating task list:   
 ![create task list](https://user-images.githubusercontent.com/46959736/120373469-3c426300-c2cd-11eb-94e6-e4d1921baa83.png)
 
 Creating event:   
 ![create event](https://user-images.githubusercontent.com/46959736/120373462-3b113600-c2cd-11eb-824b-6d37ae1731eb.png)
 
 Viewing task list and adding task 2 & 3 to task list:   
 ![view task list](https://user-images.githubusercontent.com/46959736/120373472-3cdaf980-c2cd-11eb-945e-85d56a833187.png) ![Adding task 2 to task list](https://user-images.githubusercontent.com/46959736/120373456-39e00900-c2cd-11eb-851b-fab030acb1fa.png) ![Adding task 3 to task list](https://user-images.githubusercontent.com/46959736/120373458-3b113600-c2cd-11eb-9ed4-ec8ccc84f51e.png)
 
 Adding task list to event:  
 ![Adding task list 1 to event](https://user-images.githubusercontent.com/46959736/120373459-3b113600-c2cd-11eb-9c3d-184cba18c764.png)
 
 Setting sorting method:  
 ![Set sorting method](https://user-images.githubusercontent.com/46959736/120373471-3c426300-c2cd-11eb-917b-3e2d3a8f7930.png)
 
 Final output sorted by due date:  
 ![Final output sorted by due date](https://user-images.githubusercontent.com/46959736/120373470-3c426300-c2cd-11eb-932e-8c6433ec3f27.png)
 
 Pushing an event:    
 ![Push event](https://user-images.githubusercontent.com/46959736/161829130-c8dc81b5-b365-4d36-a64e-9a7344118927.png)       
 ![Event Pushed](https://user-images.githubusercontent.com/46959736/161830582-84913d52-21f3-4dbe-88d7-cc25bf2b0190.png)

 
 Event shown on Google Calendar:    
 ![Calendar event](https://user-images.githubusercontent.com/46959736/161830920-57fa2497-9a2a-4567-bd3a-8525fe251e24.png)
 
 ## Installation/Usage
 * Requirements:
   * Python3
   * pip package management tool
   * C++11 or greater
   * cmake3
 * To install the task scheduler, run the following commands in terminal:
   * pip install --upgrade google-api-python-client google-auth-httplib2 google-auth-oauthlib
   * $git clone --recursive https://github.com/cs100/final-project-anguy589_spete020_schau014.git 
   * $cmake3 .
   * $make 
   * $./taskScheduler
  * Follow the provided instructions and prompts to create, edit, delete, and view tasks, tasklists, and events

 ## Testing
 We utilized a combination of smoke testing, unit and integration testing to test our task scheduler. 
![Screenshot 41](https://user-images.githubusercontent.com/43623351/120132056-823ce100-c17e-11eb-82e7-24f4b9a901bc.png)
![Screenshot (297)](https://user-images.githubusercontent.com/66961614/120131143-9a136580-c17c-11eb-8b04-8c0a7629d195.png)
