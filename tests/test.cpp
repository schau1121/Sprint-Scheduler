#include "gtest/gtest.h"
#include "sortdate_test.cpp"
#include "sortpriority_test.cpp"
#include "task_test.cpp"
#include "tasklist_test.cpp"
#include "event_test.cpp"
#include "create_tests.cpp"
#include "save_load_tests.cpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
