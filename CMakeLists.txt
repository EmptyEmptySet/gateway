cmake_minimum_required(VERSION 3.20)
project(gateway CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TEST src/main.cpp)
target_include_directories(TEST PRIVATE ${PROJECT_SOURCE_DIR}/src/include)


add_library(TEST_LIB STATIC lib/test.cpp)
target_include_directories(TEST_LIB PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(LOGGER_LIB STATIC logger/logger.cpp)
target_include_directories(LOGGER_LIB PUBLIC ${PROJECT_SOURCE_DIR}/logger)


target_link_libraries(TEST PRIVATE TEST_LIB)
target_link_libraries(TEST PRIVATE LOGGER_LIB)
target_link_libraries(TEST_LIB PRIVATE LOGGER_LIB)

