cmake_minimum_required(VERSION 3.10)
project(PrimeNumbersProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CPPUTEST_INCLUDE_DIRS "/usr/include/CppUTest")
set(CPPUTEST_LIBRARIES "/usr/lib/x86_64-linux-gnu/libCppUTest.a" "/usr/lib/x86_64-linux-gnu/libCppUTestExt.a")
set(SOURCES
    src/prime.cpp
)

add_library(list_lib STATIC ${SOURCES})
target_include_directories(list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(PrimeNumbersProject src/main.cpp src/prime.cpp)

add_executable(TestPrimeNumbers test/test_prime.cpp src/prime.cpp)

target_link_libraries(TestPrimeNumbers
    PRIVATE
    list_lib
    ${CPPUTEST_LIBRARIES}
)

target_include_directories(TestPrimeNumbers
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CPPUTEST_INCLUDE_DIRS}
)

enable_testing()
add_test(NAME TestPrimeNumbers COMMAND TestPrimeNumbers)