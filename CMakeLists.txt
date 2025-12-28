cmake_minimum_required(VERSION 3.14)
project(implementations)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debug flags if this isn't the Release build
#string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} "Release" IS_RELEASE)
#if(NOT IS_RELEASE)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
#endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

include_directories(include)

#file(GLOB LIB_SOURCES src/lib/*.c)
#add_library(implementations SHARED LIB_SOURCES)
#add_library(implementations STATIC LIB_SOURCES)
#add_library(implementations SHARED src/lib/linked_list.c)
add_library(implementations SHARED src/data_structures/lists/linked_list.c)

add_executable(example example.c)
target_link_libraries(example implementations)


# Add test subdirectory if this isn't the Release build
#string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} "Release" IS_RELEASE)
#if(NOT IS_RELEASE)
#  add_subdirectory(test)
#endif()
add_subdirectory(test)
