#include "gtest/gtest.h"
#include "../src/event.cpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/client.cpp"

/*
TEST(save_test, long_test_1) {
    Event currEvent = Event("Productivity Block", "05/28/21", "09:00 AM", "", 3);
    Event event2 = Event("Birthday party", "05/30/21", "10:00 PM", "Edwin's birthday", 2);
    TaskList list1 = TaskList("Housework", "", 3);
    TaskList list2 = TaskList("Errands", "", 2);
    TaskList list3 = TaskList("Homework", "", 4);
    Task task1 = Task("CS100", "05/28/21", "Final Project Sprint", 5);
    Task task2 = Task("MATH149B", "05/29/21", "Finish presentation", 3);
    Task task3 = Task("MATH146C", "06/02/21", "Chapter homeworks", 4);
    Task task4 = Task("Find summer session class", "05/31/21", "", 3);
    Task task5 = Task("Clean Room", "05/28/21", "", 1);
    list3.addSubTask(task1);
    task1.setAssigned(true);
    list3.addSubTask(task2);
    task2.setAssigned(true);
    list3.addSubTask(task3);
    task3.setAssigned(true);
    list2.addSubTask(task4);
    task4.setAssigned(true);
    list1.addSubTask(task5);
    task5.setAssigned(true);
    currEvent.addSubTask(list1);
    list1.setAssigned(true);
    currEvent.addSubTask(list2);
    list2.setAssigned(true);
    currEvent.addSubTask(list3);
    list3.setAssigned(true);
    driver.allEvents.push_back(currEvent);
    driver.allEvents.push_back(event2);
    driver.allLists.push_back(list1);
    driver.allLists.push_back(list2);
    driver.allLists.push_back(list3);
    driver.allTasks.push_back(task1);
    driver.allTasks.push_back(task2);
    driver.allTasks.push_back(task3);
    driver.allTasks.push_back(task4);
    driver.allTasks.push_back(task5);
}
*/