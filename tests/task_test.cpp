#ifndef __TASK_TEST_CPP__
#define __TASK_TEST_CPP__
#include "gtest/gtest.h"
#include "../src/client.cpp"
#include <iosfwd>

TEST(Task_Constructor_test, null_name) {
    EXPECT_THROW(Task("", "11/21/21", "Birthday coming up", 0), invalid_argument);
}

TEST(Task_Constructor_test, invalid_format_date) {
    EXPECT_THROW(Task("CS100 Project Sprint", "May 13, 2021", "Finish weekly sprint", 5), invalid_argument);
}

TEST(Task_Constructor_test, multi_line_details) {
    Base* test = new Task("Fix issue #1", "05/13/21", "Ask groupmates about issue. \nFix issue", 2);
    ostringstream out;
    out << test->getDetails();
    EXPECT_EQ(out.str(), "Ask groupmates about issue. \nFix issue");
}

/*
TEST(Task_test, edit_task_test1) {
    Task currTask = Task("Math Homework", "05/27/21", "finish 149B homework", 5);
    currTask.edit();
    EXPECT_NE("Math Homework", currTask.getName());
    EXPECT_NE("05/27/21", currTask.getDate());
    EXPECT_NE("finish 149B homework", currTask.getDetails());
    EXPECT_NE(5, currTask.getPriority());
}
*/

#endif
