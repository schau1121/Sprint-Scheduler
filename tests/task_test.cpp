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

TEST(Task_Display_test, simple_display_test) {
    Task task = Task("CS100", "05/30/21", "Some details", 4);
    ostringstream out;
    task.display(out);
    EXPECT_EQ(out.str(), "Name: CS100\nDue date: 05/30/21\nPriority: 4\nDetails: Some details\n");
}

TEST(Task_Display_test, simple_display_completed_test) {
    Task task = Task("CS100", "05/30/21", "Some details", 4);
    task.setCompleted(true);
    ostringstream out;
    task.display(out);
    EXPECT_EQ(out.str(), "Name: CS100\nDue date: 05/30/21\nPriority: 4\nDetails: Some details\nCompleted\n");
}

TEST(Task_test, edit_task_test) {
    Task currTask = Task("Math Homework", "05/27/21", "finish 149B homework", 5);
    string input = "CS100\n05/30/21\nFinal project sprint\n4\n";
    istringstream in(input);
    currTask.edit(in);
    EXPECT_EQ("CS100", currTask.getName());
    EXPECT_EQ("05/30/21", currTask.getDate());
    EXPECT_EQ("Final project sprint", currTask.getDetails());
    EXPECT_EQ(4, currTask.getPriority());
}

TEST(Task_test, edit_task_test_invalid_date) {
    Task currTask = Task("Math Homework", "05/27/21", "finish 149B homework", 5);
    string input = "CS100\n05.30.21\n05/30/21\nFinal project sprint\n4\n";
    istringstream in(input);
    currTask.edit(in);
    EXPECT_EQ("CS100", currTask.getName());
    EXPECT_EQ("05/30/21", currTask.getDate());
    EXPECT_EQ("Final project sprint", currTask.getDetails());
    EXPECT_EQ(4, currTask.getPriority());
}

TEST(Task_test, edit_task_test_invalid_name) {
    Task currTask = Task("Math Homework", "05/27/21", "finish 149B homework", 5);
    string input = "\nCS100\n05/30/21\nFinal project sprint\n4\n";
    istringstream in(input);
    currTask.edit(in);
    EXPECT_EQ("CS100", currTask.getName());
    EXPECT_EQ("05/30/21", currTask.getDate());
    EXPECT_EQ("Final project sprint", currTask.getDetails());
    EXPECT_EQ(4, currTask.getPriority());
}

TEST(Task_test, edit_task_test_invalid_priority) {
    Task currTask = Task("Math Homework", "05/27/21", "finish 149B homework", 5);
    string input = "CS100\n05/30/21\nFinal project sprint\n-1\n4\n";
    istringstream in(input);
    currTask.edit(in);
    EXPECT_EQ("CS100", currTask.getName());
    EXPECT_EQ("05/30/21", currTask.getDate());
    EXPECT_EQ("Final project sprint", currTask.getDetails());
    EXPECT_EQ(4, currTask.getPriority());
}

#endif
