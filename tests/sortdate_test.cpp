#include "gtest/gtest.h"
#include "base.hpp"
#include "task.hpp"
#include "tasklist.hpp"
#include "../src/sortdate.cpp"

TEST(sortByDate_test, simple_test1) {
    vector<Base*> queue;
    SortByDate sortingStrategy;
    queue.push_back(new Task("Task 1", "06/21/21", "", 4));
    queue.push_back(new Task("Task 2", "05/30/21", "", 3));
    queue.push_back(new Task("Task 3", "07/04/21", "", 3));
    vector<string> expected = {"05/30/21", "06/21/21", "07/04/21"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i]->getDate(), expected[i]);
    }
}
