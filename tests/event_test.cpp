#ifndef EVENT_TEST_CPP
#define EVENT_TEST_CPP

#include "gtest/gtest.h"
#include "../src/event.cpp"

TEST(Event_test, addSubTask_test1) {
    Event currEvent = Event("Productiviy Sprint", "05/25/21", "01:30 PM", "Finish homework", 2.5);
    TaskList list1 = TaskList("Homework", "", 5);
    currEvent.addSubTask(list1);
    vector<TaskList> queue = currEvent.getQueue();
    vector<string> expected = {"Homework"};
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getName(), expected[i]);
    }
}

TEST(Event_test, addSubTask_test2) {
    Event currEvent = Event("Productivity Block", "05/26/21", "09:00 AM", "", 3);
    TaskList list1 = TaskList("Housework", "", 3);
    TaskList list2 = TaskList("Errands", "", 2);
    TaskList list3 = TaskList("Homework", "", 4);
    currEvent.addSubTask(list1);
    currEvent.addSubTask(list2);
    currEvent.addSubTask(list3);
    vector<TaskList> queue = currEvent.getQueue();
    vector<string> expected = {"Homework", "Housework", "Errands"};
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getName(), expected[i]);
    }
}

TEST(Event_test, addSubTask_test3) {
    Event currEvent = Event("Workout", "05/27/21", "08:30 AM", "", 1.5);
    TaskList list1 = TaskList("Cardio", "", 5);
    TaskList list2 = TaskList("Abs", "", 2);
    TaskList list3 = TaskList("Lift", "", 3);
    currEvent.addSubTask(list1);
    currEvent.addSubTask(list2);
    currEvent.addSubTask(list3);
    vector<TaskList> queue = currEvent.getQueue();
    vector<string> expected = {"Cardio", "Lift", "Abs"};
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getName(), expected[i]);
    }
}

/*
TEST(Event_test, edit_event_test1) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    currEvent.edit();
    EXPECT_NE("Productivity Block", currEvent.getName());
    EXPECT_NE("05/27/21", currEvent.getDate());
    EXPECT_NE("09:00 AM", currEvent.getTime());
    EXPECT_NE("Some details", currEvent.getDetails());
    EXPECT_NE(3, currEvent.getDuration());
}
*/

#endif