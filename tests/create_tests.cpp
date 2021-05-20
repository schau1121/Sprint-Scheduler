#ifndef __CREATE_TESTS_CPP__ 
#define __CREATE_TESTS_CPP__ 
#include"../src/client.cpp"
#include "gtest/gtest.h"

//					Event Tests

TEST(Valid_Event_Constructor, Valid_Name) {
    Base* test = new Event("homework", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getName(), "homework");
}

TEST(Valid_Event_Constructor, Valid_Due_Date) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDate(), "04/12/20");
}

TEST(Valid_Event_Constructor, Valid_Time) {
    Base* test = new Event("", "04/12/20", "april/19/12PM", "finish homework", 5);
    EXPECT_EQ(test->getTime(), "april/19/12PM");
}

TEST(Valid_Event_Constructor, Valid_Details) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDetails(), "finish homework");
}

TEST(Valid_Event_Constructor, Valid_Duration) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDuration(), 5);
}


//					Task Tests 

TEST(Valid_Task_Constructor, Valid_Name) {
    Base* test = new Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test->getName(), "project");
} 

TEST(Valid_Task_Constructor, Valid_Date) {
    Base* test = new Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test->getDate(), "11/11/21");
}

TEST(Valid_Task_Constructor, Valid_Details) {
    Base* test = new Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test->getDetails(), "finish project");
}

TEST(Valid_Task_Constructor, Valid_Priority) {
    Base* test = new Task("project", "11/11/21", "finish project", 3);
    EXPECT_EQ(test->getPriority(), 3);
}


TEST(Task_Constructor_test, null_name) {
    EXPECT_THROW(Task("", "11/21/21", "Birthday coming up", 0), invalid_argument);
}


#endif
