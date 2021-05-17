#include "gtest/gtest.h"
#include "../src/task.cpp"
#include "../src/sortdate.cpp"

TEST(sortByDate_test, simple_test_tasks1) {
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

TEST(sortByDate_test, simple_test_tasks2) {
    vector<Base*> queue;
    SortByDate sortingStrategy;
    queue.push_back(new Task("Task 1", "05/21/21", "", 4));
    queue.push_back(new Task("Task 2", "05/22/21", "", 3));
    queue.push_back(new Task("Task 3", "12/31/20", "", 3));
    vector<string> expected = {"12/31/20", "05/21/21", "05/22/21"};
    queue = sortingStrategy.sort(queue);
    for(int i = 0; i < queue.size(); i++) {
        EXPECT_EQ(queue[i]->getDate(), expected[i]);
    }
}
