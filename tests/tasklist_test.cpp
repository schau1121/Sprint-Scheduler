#ifndef __TASKLIST_TEST_CPP__
#define __TASKLIST_TEST_CPP__
#include "gtest/gtest.h"
#include "../src/tasklist.cpp"

TEST(TaskList_addSubTask_test, single_task) {
    TaskList* currList =  new TaskList("Homework", "", 4);
    Base* mock = new TaskMock1();
    currList->addSubTask(mock);
    EXPECT_EQ(currList->getQueue().at(0), mock);
}

TEST(TaskList_addSubTask_test, multi_task) {
    TaskList* currList = new TaskList("Work", "Final Project Sprint", 3);
    Base* mock1 = new TaskMock1();
    Base* mock2 = new TaskMock2();
    currList->addSubTask(mock1);
    currList->addSubTask(mock2);
    vector<Base*> expected = {mock1, mock2};
    for(int i = 0; i < currList->getQueue().size(), i++) {
        EXPECT_EQ(expected.at(i), currList->getQueue().at(i));
    }
}

TEST(TaskList_addSubTask_test, null_task) {
    TaskList* currList = new TaskList("A To-Do list", "", 5);
    Base* test = nullptr;
    currList->addSubTask(test);
    EXPECT_EQ(currList->getQueue().empty(), true) << "Current task list is not empty";
    EXPECT_EQ(currList->getNumTasks(), 0) << "Current list has > 0 sub tasks"; 
}

#endif
