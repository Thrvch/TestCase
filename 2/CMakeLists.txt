cmake_minimum_required(VERSION 3.10)
project(WordCount)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CPPUTEST_INCLUDE_DIRS "/usr/include/CppUTest")
set(CPPUTEST_LIBRARIES "/usr/lib/x86_64-linux-gnu/libCppUTest.a" "/usr/lib/x86_64-linux-gnu/libCppUTestExt.a")
set(SOURCES
    src/word.cpp
    src/word_count_map.cpp
)

add_library(list_lib STATIC ${SOURCES})
target_include_directories(list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(WordCount src/main.cpp src/word.cpp src/word_count_map.cpp)

add_executable(TestWordCount test/test_word.cpp)

target_link_libraries(TestWordCount
    PRIVATE
    list_lib
    ${CPPUTEST_LIBRARIES}
)

target_include_directories(TestWordCount
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CPPUTEST_INCLUDE_DIRS}
)

enable_testing()
add_test(NAME TestWordCount COMMAND TestWordCount)