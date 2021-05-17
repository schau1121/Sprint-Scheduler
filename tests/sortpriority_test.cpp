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


#endif