#ifndef __TASK_TEST_CPP__
#define __TASK_TEST_CPP__
#include "gtest/gtest.h"
#include "../src/task.cpp"
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
TEST(Task_Constructor_test, default_values) {
    Base* test = new Task("Task 1");
    ostringstream out;
    out << test->getDetails();
    EXPECT_EQ(out.str(), "");
    out.clear();
    out<< test->getDate();
    EXPECT_EQ(out.str(), "");
}
*/

#endif