#ifndef __SORTPRIORITY_TEST__
#define __SORTPRIORITY_TEST__

#include "gtest/gtest.h"
#include "../src/sortpriority.cpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/event.cpp"

TEST(sortByPriority_test, simple_test_tasks1) {
    vector<Task> queue;
    SortByPriority<Task> sortingStrategy;
    queue.push_back(Task("Task 1", "06/21/21", "", 4));
    queue.push_back(Task("Task 2", "05/30/21", "", 2));
    queue.push_back(Task("Task 3", "07/04/21", "", 3));
    vector<string> expected = {"Task 1", "Task 3", "Task 2"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getName(), expected[i]);
    }
}

TEST(sortByPriority_test, simple_test_tasks2) {
    vector<Task> queue;
    SortByPriority<Task> sortingStrategy;
    queue.push_back(Task("CS100", "06/21/21", "", 1));
    queue.push_back(Task("MATH149B", "05/30/21", "", 5));
    queue.push_back(Task("MATH146C", "07/04/21", "", 3));
    vector<string> expected = {"MATH149B", "MATH146C", "CS100"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getName(), expected[i]);
    }
}

TEST(sortByPriority_test, taskList_test1) {
    TaskList test = TaskList("Homework", "", 4);
    test.setStrategy("priority");
    test.addSubTask(Task("math homework", "05/20/21", "ch. 1-3", 3));
    test.addSubTask(Task("english homework", "05/18/21", "read books", 2));
    test.addSubTask(Task("history homework", "05/18/21", "flashcards", 1));
    test.addSubTask(Task("cs100 homework", "05/17/21", "final project sprint", 5));
    vector<string> expected = {"cs100 homework", "math homework", "english homework", "history homework"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test.getQueue()[i].getName(), expected[i]) << "vectors differ at " << i;
    }
}

TEST(sortByPriority_test, taskList_test2) {
    TaskList test = TaskList("Chores", "", 4);
    test.setStrategy("priority");
    test.addSubTask(Task("Bathroom", "05/20/21", "", 3));
    test.addSubTask(Task("Dishes", "05/18/21", "", 2));
    test.addSubTask(Task("Bedroom", "05/17/21", "", 4));
    test.addSubTask(Task("Mop floors", "05/17/21", "", 5));
    vector<string> expected = {"Mop floors", "Bedroom", "Bathroom", "Dishes"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test.getQueue()[i].getName(), expected[i]) << "vectors differ at " << i;
    }
}

TEST(sortByPriority_test, event_test1) {
    Event test = Event("Productivity block", "05/21/21", "12:00 PM", "", 2.5);
    TaskList test2 = TaskList("CS100 Project Sprint", "Finish this weeks assigned work", 5);
    TaskList test3 = TaskList("Homework", "", 2);
    TaskList test4 = TaskList("Chores", "Clean the house", 4);
    test.addSubTask(test2);
    test.addSubTask(test3);
    test.addSubTask(test4);
    vector<string> expected = {"CS100 Project Sprint", "Chores", "Homework"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test.getQueue()[i].getName(), expected[i]) << "vectors differ at " << i;
    }
}

#endif