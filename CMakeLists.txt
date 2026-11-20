cmake_minimum_required(VERSION 3.20)
project(gateway CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TEST src/main.cpp)
add_library(TEST_LIB STATIC lib/test.cpp)

target_include_directories(TEST PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(TEST PRIVATE ${PROJECT_SOURCE_DIR}/src/include)

target_include_directories(TEST_LIB PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(TEST PRIVATE TEST_LIB)
