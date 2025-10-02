cmake_minimum_required(VERSION 3.10)

project(hw1)
set(HW1_SRC_LIST src/*.cpp)

include(CTest)
set(MemoryCheckCommand valgrind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(smartPointerTestExec    src/smartPointerTest.cpp)
add_executable(performanceTestExec     src/performanceTest.cpp)

target_include_directories(smartPointerTest      PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(performanceTest       PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(SmartPointers)
target_link_libraries(smartPointerTest                PATypes)
target_link_libraries(performanceTest                 PATypes)

enable_testing()

add_test(success_smartPointerTest smartPointerTestExec)
