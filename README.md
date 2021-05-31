# Task Scheduler 
Authors: [Scott Peterson](https://github.com/scottyallenp), [Anh Nguyen](https://github.com/AnhQNguyen), [Simon Chau](https://github.com/schau1121)
 
## Project Description
### User Experience
 We plan on building a task management application where a user can create and view personal tasks and events. Users will be able to transfer their event and task lists made in our application into their personal Google Calendar.
 ### Importance
 We find this project really important because it is a very practical application for us as college students. With classes, clubs, and our careers, it becomes increasingly difficult to manage our time, and we are sure that plenty of people can relate. By grouping tasks together and creating an "event" based productivity block, we believe that users of our service can maximize their productivity to the fullest. Additionally, we are interested in familiarizing ourselves with an API and since the documentation is very thorough, we thought this project would be a perfect opportunity to learn and a great place to start.
 ### Tools and Technology
 * C++ -  An object-oriented programming language 
 * Google’s Calendar API - An API that allows for application integration into Google Calendar
 * Valgrind - A programming tool used for code profiling and debugging
 * Gtest - A unit and integration testing library for C++
 ### Application Input / Output
 The user will be able to create customized tasks inside an event by including: a string used for a short title, a string for a task description, a string for a classification tag, an integer determining the task’s priority, an integer for estimated task duration in hours, and a datetime string labeling the event time. Depending on the component that the user is creating (event/task) there will be different prompts for the user's input. For example, if a user creates an event, they will be prompted to input a datetime to schedule. Our application will output a list of tasks and events including their details, events will be prioritized based on their deadlines while tasks will be prioritized based on their rank in the priority queue. Additionally, our application will output a call to the Google Calendar API where the user should be able to see their scheduled event.
 ### Design Patterns
 * Composite
   * We chose to use the composite design pattern to implement a list of tasks or events composed of smaller tasks inside of them. With this pattern we plan to implement the basic interface which consists of editing, deleting, and creating tasks/events. An issue we anticipate encountering  with our project is finding a balance between creating a simple interface for the user to interact with the components, while also maintaining separate functionality. With the composite pattern, objects are treated very similarly, and we plan on using polymorphism and recursion to our advantage to solve this problem.
 * Strategy
   * The strategy design pattern will be used to sort the priority queues within our application. Our task manager will consist of at least two different objects: tasks and events and possibly a task list in the future. This design pattern allows us to sort a user's task list by either priority or due date, depending on what the user prefers. An issue we plan on encountering with the composite design pattern is differentiating the functionality of the interface depending on component at runtime, however, with the strategy design pattern, this should be easily solved. As the user defines how he/she would like to sort their task list at runtime, our application will have the capability to sort by the specified strategy without issues. 

## Class Diagram
 ![CS100 Final Project (4)](https://user-images.githubusercontent.com/46959736/119219377-26959800-ba9a-11eb-9f65-032940d83b1d.png)
 
 In our class diagram, we utilize the composite and strategy design patterns. Our application consists of 8 classes, 2 abstract and 6 concrete. For the composite design pattern, we have a base class which contains the pure virtual functions that make up the user interface. These functions are display, edit, delete, and add. Additionally, we have another function called setStrategy, which sets which sorting algorithm the user wants to utilize when displaying their tasks. From there, we have three objects which inherit from Base: Task, TaskList, and Event. These three objects maintain the same interface of display, edit, delete, and add, but additionally, they also contain specific data members unique to themselves. For example, a Task contains information about priority, completion, and a due date, while an Event contains duration, date, and time. Here we utilize the composite design pattern since TaskList and Event aggregate the base class in order to contain a priority queue of subtasks (which could be tasks, events, or task lists). Next, our application also utilizes the strategy pattern through our SortStrategy classes. We have two strategies which inherit from this base SortStrategy class: SortByPriority and SortByDate. These two classes contain a sort function which will sort the priority queue by either priority or due date.
 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 ![Screenshot (297)](https://user-images.githubusercontent.com/66961614/120131143-9a136580-c17c-11eb-8b04-8c0a7629d195.png)
 

 ## Installation/Usage
 * To install the task scheduler, run the following commands in terminal:
   * $git clone --recursive https://github.com/cs100/final-project-anguy589_spete020_schau014.git 
   * $cmake3 .
   * $make 
   * $./taskScheduler
  * Follow the provided instructions and prompts to create, edit, delete, and view tasks, tasklists, and events

 ## Testing
 We utilized a combination of smoke testing, unit and integration testing to test our task scheduler. 
 [![CI](https://github.com/cs100/final-project-anguy589_spete020_schau014/actions/workflows/main.yml/badge.svg)](https://github.com/cs100/final-project-anguy589_spete020_schau014/actions/workflows/main.yml)
