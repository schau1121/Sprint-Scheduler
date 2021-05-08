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

#endif
