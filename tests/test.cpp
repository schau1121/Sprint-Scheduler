#include "gtest/gtest.h"
#include "create_tests.cpp"
//#include "sortdate_test.cpp"
//#include "sortpriority_test.cpp"
//#include "task_test.cpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
