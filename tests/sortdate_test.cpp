#ifndef __SORTDATE_TEST__
#define __SORTDATE_TEST__

#include "gtest/gtest.h"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"
#include "../src/sortdate.cpp"

TEST(sortByDate_test, simple_test_tasks1) {
    vector<Task> queue;
    SortByDate<Task> sortingStrategy;
    queue.push_back(Task("Task 1", "06/21/21", "", 4));
    queue.push_back(Task("Task 2", "05/30/21", "", 3));
    queue.push_back(Task("Task 3", "07/04/21", "", 3));
    vector<string> expected = {"05/30/21", "06/21/21", "07/04/21"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getDate(), expected[i]);
    }
}

TEST(sortByDate_test, simple_test_tasks2) {
    vector<Task> queue;
    SortByDate<Task> sortingStrategy;
    queue.push_back(Task("Task 1", "05/21/21", "", 4));
    queue.push_back(Task("Task 2", "05/22/21", "", 3));
    queue.push_back(Task("Task 3", "12/31/20", "", 3));
    vector<string> expected = {"12/31/20", "05/21/21", "05/22/21"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i].getDate(), expected[i]);
    }
}

TEST(sortByDate_test, taskList_test1) {
    TaskList test = TaskList("Homework", "", 4);
    test.setStrategy("date");
    test.addSubTask(Task("math homework", "05/20/21", "ch. 1-3", 3));
    test.addSubTask(Task("english homework", "05/18/21", "read books", 2));
    test.addSubTask(Task("history homework", "05/18/21", "flashcards", 1));
    test.addSubTask(Task("cs100 homework", "05/17/21", "final project sprint", 5));
    vector<string> expected = {"cs100 homework", "english homework", "history homework", "math homework"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test.getQueue()[i].getName(), expected[i]) << "vectors differ at " << i;
    }
}

TEST(sortByDate_test, taskList_test2) {
    TaskList test = TaskList("Chores", "Clean up the house", 2);
    test.setStrategy("date");
    test.addSubTask(Task("Bathroom", "05/20/21", "", 3));
    test.addSubTask(Task("Dishes", "05/18/21", "", 2));
    test.addSubTask(Task("Bedroom", "05/17/21", "", 4));
    test.addSubTask(Task("Mop floors", "05/17/21", "", 5));
    vector<string> expected = {"Bedroom", "Mop floors", "Dishes", "Bathroom"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test.getQueue()[i].getName(), expected[i]) << "vectors differ at " << i;
    }
}

#endif