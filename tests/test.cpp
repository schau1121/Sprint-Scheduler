#include "gtest/gtest.h"
#include "task_test.cpp"
#include "create_tests.cpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
