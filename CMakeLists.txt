cmake_minimum_required(VERSION 3.10)

project(hw1)
set(HW1_SRC_LIST src/*.cpp)

include(CTest)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(smartPointerTestExec     src/smartPointerTest.cpp)
add_executable(uniquePointerTestExec    src/uniquePointerTest.cpp)
add_executable(memorySpanTestExec       src/memorySpanTest.cpp)

add_executable(performanceTestExec	src/performanceTest.cpp)

target_include_directories(smartPointerTestExec			PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(uniquePointerTestExec		PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(memorySpanTestExec			PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_include_directories(performanceTestExec      PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(SmartPointers)
target_link_libraries(smartPointerTestExec	SmartPointers)
target_link_libraries(uniquePointerTestExec	SmartPointers)
target_link_libraries(memorySpanTestExec	SmartPointers)
target_link_libraries(performanceTestExec	SmartPointers)

enable_testing()

add_test(success_smartPointerTest	smartPointerTestExec)
add_test(success_uniquePointerTest	uniquePointerTestExec)
add_test(success_memorySpanTest		memorySpanTestExec)
