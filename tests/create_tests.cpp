#ifndef __CREATE_TESTS_CPP__ 
#define __CREATE_TESTS_CPP__ 
#include"../src/client.cpp"
#include "gtest/gtest.h"

//					Event Tests

TEST(Valid_Event_Constructor, Valid_Name) {
    Event test = Event("homework", "04/12/20", "12:30 AM", "finish homework", 5);
    EXPECT_EQ(test.getName(), "homework");
}

TEST(Valid_Event_Constructor, Valid_Due_Date) {
    Event test = Event("homework", "04/12/20", "11:11 PM", "finish homework", 5);
    EXPECT_EQ(test.getDate(), "04/12/20");
}

TEST(Valid_Event_Constructor, Valid_Time_Uppercase) {
    Event test = Event("homework", "04/12/20", "10:30 PM", "finish homework", 5);
    EXPECT_EQ(test.getTime(), "10:30 PM");
}

TEST(Valid_Event_Constructor, Valid_Time_Lowercase) {
    Event test = Event("homework", "04/12/20", "10:30 am", "finish homework", 5);
    EXPECT_EQ(test.getTime(), "10:30 am");
}

TEST(Valid_Event_Constructor, Valid_Details) {
    Event test = Event("homework", "04/12/20", "10:15 AM", "finish homework", 5);
    EXPECT_EQ(test.getDetails(), "finish homework");
}

TEST(Valid_Event_Constructor, Empty_Details) {
    Event test = Event("homework", "04/12/20", "10:15 AM", "", 5);
    EXPECT_EQ(test.getDetails(), "");
}

TEST(Valid_Event_Constructor, Valid_Duration) {
    Event test = Event("homework", "04/12/20", "12:30 PM", "finish homework", 5);
    EXPECT_EQ(test.getDuration(), 5);
}

//					Invalid Events
TEST(Invalid_Event_Constructor, Null_Name) {
    EXPECT_THROW(Event("", "09/22/21", "12:12 am", "new quarter", 4), invalid_argument);
}

TEST(Invalid_Event_Constructor, Invalid_Due_Date) {
    EXPECT_THROW(Event("fall", "9/22/21", "12:12 am", "new quarter", 2), invalid_argument);
}

TEST(Invalid_Event_Constructor, Invalid_Time) {
    EXPECT_THROW(Event("fall", "09/22/21", "8:12 am", "new quarter", 1), invalid_argument);
}
/*
TEST(Invalid_Event_Constructor, Null_Details) {
    EXPECT_THROW(Event("fall", "09/22/21", "12:12 am", "", 5), invalid_argument);
}
*/
TEST(Invalid_Event_Constructor, Invalid_Duration) {
    EXPECT_THROW(Event("fall", "09/22/21", "12:12 am", "new quarter", 0), invalid_argument);
}

//					Task Tests 

TEST(Valid_Task_Constructor, Valid_Name) {
    Task test = Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test.getName(), "project");
} 

TEST(Valid_Task_Constructor, Valid_Due_Date) {
    Task test = Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test.getDate(), "11/11/21");
}

TEST(Valid_Task_Constructor, Valid_Details) {
    Task test = Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test.getDetails(), "finish project");
}

TEST(Valid_Task_Constructor, Empty_Details) {
    Task test = Task("project", "11/11/21", "", 3);
    EXPECT_EQ(test.getDetails(), "");
}

TEST(Valid_Task_Constructor, Valid_Priority) {
    Task test = Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test.getPriority(), 3);
}

//					Invalid Tasks
TEST(Invalid_Task_Constructor, Null_Name) {
    EXPECT_THROW(Task("", "11/21/21", "Birthday coming up", 0), invalid_argument);
}

TEST(Invalid_Task_Constructor, Invalid_Due_Date) {
    EXPECT_THROW(Task("Birthday", "1/21/21", "Birthday coming up", 0), invalid_argument);
}
/*
TEST(Invalid_Task_Constructor, Null_Details) {
    EXPECT_THROW(Task("Birthdat", "11/21/21", "", 0), invalid_argument);
}
*/
TEST(Invalid_Task_Constructor, Invalid_Priority) {
    EXPECT_THROW(Task("Birthday", "11/21/21", "Birthday coming up", 20), invalid_argument);
}

//					Tasklist Tests 

TEST(Valid_Tasklist_Constructor, Valid_Name) {
    TaskList test = TaskList("assignments", "list of homework", 4);
    EXPECT_EQ(test.getName(), "assignments");
}

TEST(Valid_Tasklist_Constructor, Valid_Details) {
    TaskList test = TaskList("assignments", "list of homework", 4);
    EXPECT_EQ(test.getDetails(), "list of homework");
}

TEST(Valid_Tasklist_Constructor, Empty_Details) {
    TaskList test = TaskList("assignments", "", 4);
    EXPECT_EQ(test.getDetails(), "");
}

TEST(Valid_Tasklist_Constructor, Valid_Priority) {
    TaskList test = TaskList("assignments", "list of homework", 4);
    EXPECT_EQ(test.getPriority(), 4);
}

//					Invalid task lists

TEST(Invalid_Tasklist_Constructor, Null_Name) {
    EXPECT_THROW(TaskList("", "chores", 0), invalid_argument);
}
/*
TEST(Invalid_Tasklist_Constructor, Null_Details) {
    EXPECT_THROW(TaskList("Todos", "", 0), invalid_argument);
}
*/
TEST(Invalid_Tasklist_Constructor, Invalid_Priority) {
    EXPECT_THROW(TaskList("Todos", "chores", -5), invalid_argument);
}

 
#endif
