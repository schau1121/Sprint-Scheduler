#ifndef SAVE_LOAD_TESTS_CPP
#define SAVE_LOAD_TESTS_CPP

#include "gtest/gtest.h"
#include "../src/event.cpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/client.cpp"

TEST(save_test, simple_test_1) {
    client driver;
    driver.clear();
    Task task = Task("CS100", "06/01/21", "Final Project Sprint", 5);
    driver.allTasks.push_back(task);
    driver.save();
    json j;
    ifstream in;
    in.open("save.json");
    in >> j;
    for(auto currTask: j["Tasks"]) {
        EXPECT_EQ(currTask["Name"], "CS100");
        EXPECT_EQ(currTask["Due Date"], "06/01/21");
        EXPECT_EQ(currTask["Details"], "Final Project Sprint");
        EXPECT_EQ(currTask["Priority"], 5);
        EXPECT_EQ(currTask["Completed"], false);
        EXPECT_EQ(currTask["Assigned"], false);
    }
    driver.allTasks.clear();
}

TEST(save_test, simple_test_2) {
    client driver;
    driver.clear();
    Event event = Event("Productivity Block", "05/30/21", "10:00 AM", "", 3);
    driver.allEvents.push_back(event);
    driver.save();
    json j;
    ifstream in;
    in.open("save.json");
    in >> j;
    for(auto currEvent: j["Events"]) {
        EXPECT_EQ(currEvent["Name"], "Productivity Block");
        EXPECT_EQ(currEvent["Date"], "05/30/21");
        EXPECT_EQ(currEvent["Time"], "10:00 AM");
        EXPECT_EQ(currEvent["Details"], "");
        EXPECT_EQ(currEvent["Duration"], 3);
    }
    driver.allEvents.clear();
}

TEST(save_test, simple_test_3) {
    client driver;
    TaskList list = TaskList("Homework", "", 3);
    driver.allLists.push_back(list);
    driver.save();
    json j;
    ifstream in;
    in.open("save.json");
    in >> j;
    for(auto currList: j["Task Lists"]) {
        EXPECT_EQ(currList["Name"], "Homework");
        EXPECT_EQ(currList["Details"], "");
        EXPECT_EQ(currList["Priority"], 3);
        EXPECT_EQ(currList["Completed"], false);
        EXPECT_EQ(currList["Assigned"], false);
    }
    driver.allLists.clear();
}

/*
TEST(save_test, long_test_1) {
    client driver;
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

#endif
