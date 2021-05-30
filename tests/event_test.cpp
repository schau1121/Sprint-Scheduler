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

TEST(Event_Display_test, simple_display_test1) {
    Event test = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    ostringstream out;
    test.display(out);
    EXPECT_EQ(out.str(), "Name: Productivity Block\nDate: 05/27/21\nTime: 09:00 AM\nDuration: 3\nDetails: Some details\n");
}

TEST(Event_Display_test, simple_display_test2) {
    Event test = Event("Errands", "05/30/21", "12:00 PM", "", 1.5);
    ostringstream out;
    test.display(out);
    EXPECT_EQ(out.str(), "Name: Errands\nDate: 05/30/21\nTime: 12:00 PM\nDuration: 1.5\nDetails: \n");
}


TEST(Event_test, edit_event_test) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    string input = "Errands\n05/30/21\n10:30 AM\nGet stuff done\n2\n";
    istringstream in(input);
    currEvent.edit(in);
    EXPECT_EQ("Errands", currEvent.getName());
    EXPECT_EQ("05/30/21", currEvent.getDate());
    EXPECT_EQ("10:30 AM", currEvent.getTime());
    EXPECT_EQ("Get stuff done", currEvent.getDetails());
    EXPECT_EQ(2, currEvent.getDuration());
}

TEST(Event_test, edit_event_test_invalid_date) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    string input = "Errands\n05.30.21\n05/30/21\n10:30 AM\nGet stuff done\n2\n";
    istringstream in(input);
    currEvent.edit(in);
    EXPECT_EQ("Errands", currEvent.getName());
    EXPECT_EQ("05/30/21", currEvent.getDate());
    EXPECT_EQ("10:30 AM", currEvent.getTime());
    EXPECT_EQ("Get stuff done", currEvent.getDetails());
    EXPECT_EQ(2, currEvent.getDuration());
}

TEST(Event_test, edit_event_test_invalid_time) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    string input = "Errands\n05/30/21\n10:30\n10:30 AM\nGet stuff done\n2\n";
    istringstream in(input);
    currEvent.edit(in);
    EXPECT_EQ("Errands", currEvent.getName());
    EXPECT_EQ("05/30/21", currEvent.getDate());
    EXPECT_EQ("10:30 AM", currEvent.getTime());
    EXPECT_EQ("Get stuff done", currEvent.getDetails());
    EXPECT_EQ(2, currEvent.getDuration());
}

TEST(Event_test, edit_event_test_invalid_duration) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    string input = "Errands\n05/30/21\n10:30 AM\nGet stuff done\n-1\n2\n";
    istringstream in(input);
    currEvent.edit(in);
    EXPECT_EQ("Errands", currEvent.getName());
    EXPECT_EQ("05/30/21", currEvent.getDate());
    EXPECT_EQ("10:30 AM", currEvent.getTime());
    EXPECT_EQ("Get stuff done", currEvent.getDetails());
    EXPECT_EQ(2, currEvent.getDuration());
}

TEST(Event_test, edit_event_test_invalid_name) {
    Event currEvent = Event("Productivity Block", "05/27/21", "09:00 AM", "Some details", 3);
    string input = "\nErrands\n05/30/21\n10:30 AM\nGet stuff done\n2\n";
    istringstream in(input);
    currEvent.edit(in);
    EXPECT_EQ("Errands", currEvent.getName());
    EXPECT_EQ("05/30/21", currEvent.getDate());
    EXPECT_EQ("10:30 AM", currEvent.getTime());
    EXPECT_EQ("Get stuff done", currEvent.getDetails());
    EXPECT_EQ(2, currEvent.getDuration());
}


#endif