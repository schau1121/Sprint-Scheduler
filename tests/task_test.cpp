#ifndef __TASK_TEST_CPP__
#define __TASK_TEST_CPP__

#include "gtest/gtest.h"
#include "../src/task.cpp"

TEST(Task_Constructor_test, null_name) {
    EXPECT_THROW(Task("", "11/21/21", "Birthday coming up", 0), invalid_argument);
}

#endif