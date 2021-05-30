CMAKE_MINIMUM_REQUIRED(VERSION 2.8...3.13)
PROJECT(TaskScheduler)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(json)


ADD_EXECUTABLE(taskScheduler src/main.cpp)
ADD_EXECUTABLE(test tests/test.cpp)

FIND_PACKAGE(nlohmann_json 3.2.0 REQUIRED)

TARGET_LINK_LIBRARIES(test gtest nlohmann_json::nlohmann_json)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(taskScheduler PRIVATE nlohmann_json::nlohmann_json)