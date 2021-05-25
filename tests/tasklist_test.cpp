#ifndef TASKLIST_TEST_CPP
#define TASKLIST_TEST_CPP

#include "gtest/gtest.h"
#include "../header/tasklist.hpp"
#include "../src/tasklist.cpp"

TEST(TaskList_test, addSubTask_test1) {
    TaskList list = TaskList("Homework", "", 4);
    Task subTask1 = Task("CS100", "05/25/21", "Final Project Sprint", 5);
    Task subTask2 = Task("MATH146C", "05/30/21", "Ch 1-6 HW", 3);
    Task subTask3 = Task("MATH149B", "06/02/21", "Final Project Powerpoint", 4);
    list.addSubTask(subTask1);
    list.addSubTask(subTask2);
    list.addSubTask(subTask3);
    list.setStrategy("date");
    vector<string> expected = {"CS100", "MATH146C", "MATH149B"};
    vector<Task> subTasks = list.getQueue();
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(expected[i], subTasks[i].getName());
    }
}

TEST(TaskList_test, addSubTask_test2) {
    TaskList list = TaskList("Chores", "", 1);
    Task subTask1 = Task("Dishes", "05/25/21", "", 3);
    Task subTask2 = Task("Mop", "05/30/21", "", 5);
    Task subTask3 = Task("Sweep", "06/02/21", "", 1);
    list.addSubTask(subTask1);
    list.addSubTask(subTask2);
    list.addSubTask(subTask3);
    vector<string> expected = {"Mop", "Dishes", "Sweep"};
    vector<Task> subTasks = list.getQueue();
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(expected[i], subTasks[i].getName());
    }
}

TEST(TaskList_test, addSubTask_test3) {
    TaskList list = TaskList("Workout", "", 1);
    Task subTask1 = Task("Push", "05/25/21", "", 4);
    Task subTask2 = Task("Legs", "05/25/21", "", 5);
    Task subTask3 = Task("Pull", "06/25/21", "", 5);
    list.addSubTask(subTask1);
    list.addSubTask(subTask2);
    list.addSubTask(subTask3);
    vector<string> expected = {"Legs", "Pull", "Push"};
    vector<Task> subTasks = list.getQueue();
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(expected[i], subTasks[i].getName());
    }
}

TEST(TaskList_test, addSubTask_test4) {
    TaskList list = TaskList("Errands", "", 1);
    Task subTask1 = Task("Schedule Academic Advisor Meeting", "05/25/21", "Summer enrollment issues", 4);
    Task subTask2 = Task("Buy birthday gifts", "05/27/21", "", 2);
    list.addSubTask(subTask1);
    list.addSubTask(subTask2);
    vector<string> expected = {"Schedule Academic Advisor Meeting", "Buy birthday gifts"};
    vector<Task> subTasks = list.getQueue();
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(expected[i], subTasks[i].getName());
    }
}

#endif