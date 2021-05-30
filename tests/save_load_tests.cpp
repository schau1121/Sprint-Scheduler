#ifndef SAVE_LOAD_TESTS_CPP
#define SAVE_LOAD_TESTS_CPP

#include "gtest/gtest.h"
#include "../src/event.cpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/client.cpp"

TEST(save_test, null_test) {
    client driver;
    driver.clear();
    driver.save();
    ifstream in;
    in.open("save.json");
    json j;
    in >> j;
    EXPECT_EQ(j.is_null(), true);
}

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
    driver.clear();
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
    driver.clear();
}

TEST(save_test, simple_test_3) {
    client driver;
    driver.clear();
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
    driver.clear();
}

TEST(save_test, nested_test_1) {
    client driver;
    driver.clear();
    Event event = Event("Productivity Block", "05/30/21", "10:00 AM", "", 3);
    TaskList list = TaskList("Homework", "", 3);
    Task task = Task("CS100", "06/01/21", "Final Project Sprint", 5);
    list.addSubTask(task);
    task.setAssigned(true);
    event.addSubTask(list);
    list.setAssigned(true);
    driver.allTasks.push_back(task);
    driver.allLists.push_back(list);
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
        for(auto currList: currEvent["Sub Lists"]) {
            EXPECT_EQ(currList["Name"], "Homework");
            EXPECT_EQ(currList["Details"], "");
            EXPECT_EQ(currList["Priority"], 3);
            EXPECT_EQ(currList["Completed"], false);
            for(auto currTask: currList["Sub Tasks"]) {
                EXPECT_EQ(currTask["Name"], "CS100");
                EXPECT_EQ(currTask["Due Date"], "06/01/21");
                EXPECT_EQ(currTask["Details"], "Final Project Sprint");
                EXPECT_EQ(currTask["Priority"], 5);
                EXPECT_EQ(currTask["Completed"], false);
            }
        }
    }
    for(auto currList: j["Task Lists"]) {
        EXPECT_EQ(currList["Name"], "Homework");
        EXPECT_EQ(currList["Details"], "");
        EXPECT_EQ(currList["Priority"], 3);
        EXPECT_EQ(currList["Completed"], false);
        EXPECT_EQ(currList["Assigned"], true);
        for(auto currTask: currList["Sub Tasks"]) {
            EXPECT_EQ(currTask["Name"], "CS100");
            EXPECT_EQ(currTask["Due Date"], "06/01/21");
            EXPECT_EQ(currTask["Details"], "Final Project Sprint");
            EXPECT_EQ(currTask["Priority"], 5);
            EXPECT_EQ(currTask["Completed"], false);
        }
    }
    for(auto currTask: j["Tasks"]) {
        EXPECT_EQ(currTask["Name"], "CS100");
        EXPECT_EQ(currTask["Due Date"], "06/01/21");
        EXPECT_EQ(currTask["Details"], "Final Project Sprint");
        EXPECT_EQ(currTask["Priority"], 5);
        EXPECT_EQ(currTask["Completed"], false);
        EXPECT_EQ(currTask["Assigned"], true);
    }
    driver.clear();
}

#endif
