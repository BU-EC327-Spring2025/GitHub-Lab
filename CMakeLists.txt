cmake_minimum_required(VERSION 3.10)
project(Add)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files
add_library(add src/add.cpp)

# Unit tests
enable_testing()
find_package(GTest REQUIRED)

add_executable(test_add tests/test_add.cpp)
target_link_libraries(test_add GTest::GTest GTest::Main add)
add_test(NAME test_add COMMAND test_add)

