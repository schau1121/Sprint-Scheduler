#ifndef __CREATE_TESTS_CPP__ 
#define __CREATE_TESTS_CPP__ 
#include"../src/client.cpp"
#include "gtest/gtest.h"


TEST(Valid_Event_Constructor, valid_name) {
    Base* test = new Event("homework", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getName(), "homework");
}

TEST(Valid_Event_Constructor, valid_due_date) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDate(), "04/12/20");
}

TEST(Valid_Event_Constructor, valid_time) {
    Base* test = new Event("", "04/12/20", "april/19/12PM", "finish homework", 5);
    EXPECT_EQ(test->getTime(), "april/19/12PM");
}

TEST(Valid_Event_Constructor, valid_details) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDetails(), "finish homework");
}

TEST(Valid_Event_Constructor, valid_duration) {
    Base* test = new Event("", "04/12/20", "april/19/12 PM", "finish homework", 5);
    EXPECT_EQ(test->getDuration(), 5);
}
 


#endif
