#ifndef __SORTPRIORITY_TEST__
#define __SORTPRIORITY_TEST__

#include "gtest/gtest.h"
#include "../src/sortpriority.cpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"

TEST(sortByPriority_test, simple_test_tasks1) {
    vector<Base*> queue;
    SortByPriority sortingStrategy;
    queue.push_back(new Task("Task 1", "06/21/21", "", 4));
    queue.push_back(new Task("Task 2", "05/30/21", "", 2));
    queue.push_back(new Task("Task 3", "07/04/21", "", 3));
    vector<string> expected = {"Task 1", "Task 3", "Task 2"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i]->getName(), expected[i]);
    }
}

TEST(sortByPriority_test, simple_test_tasks2) {
    vector<Base*> queue;
    SortByPriority sortingStrategy;
    queue.push_back(new Task("CS100", "06/21/21", "", 1));
    queue.push_back(new Task("MATH149B", "05/30/21", "", 5));
    queue.push_back(new Task("MATH146C", "07/04/21", "", 3));
    vector<string> expected = {"MATH149B", "MATH146C", "CS100"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i]->getName(), expected[i]);
    }
}

TEST(sortByPriority_test, taskList_test1) {
    Base* test = new TaskList("Homework", "", 4);
    test->setStrategy(new SortByPriority());
    test->addSubTask(new Task("math homework", "05/20/21", "ch. 1-3", 3));
    test->addSubTask(new Task("english homework", "05/18/21", "read books", 2));
    test->addSubTask(new Task("history homework", "05/18/21", "flashcards", 1));
    test->addSubTask(new Task("cs100 homework", "05/17/21", "final project sprint", 5));
    vector<string> expected = {"cs100 homework", "math homework", "english homework", "history homework"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test->getQueue()[i]->getName(), expected[i]) << "vectors differ at " << i;
    }
}

TEST(sortByPriority_test, taskList_test2) {
    Base* test = new TaskList("Chores", "", 4);
    test->setStrategy(new SortByPriority());
    test->addSubTask(new Task("Bathroom", "05/20/21", "", 3));
    test->addSubTask(new Task("Dishes", "05/18/21", "", 2));
    test->addSubTask(new Task("Bedroom", "05/17/21", "", 4));
    test->addSubTask(new Task("Mop floors", "05/17/21", "", 5));
    vector<string> expected = {"Mop floors", "Bedroom", "Bathroom", "Dishes"};
    for(int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(test->getQueue()[i]->getName(), expected[i]) << "vectors differ at " << i;
    }
}

#endif