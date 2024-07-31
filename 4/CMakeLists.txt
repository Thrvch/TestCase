cmake_minimum_required(VERSION 3.10)
project(BitEdit)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавление флагов компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Явно указываем пути к CppUTest
set(CPPUTEST_INCLUDE_DIRS "/usr/include/CppUTest")
set(CPPUTEST_LIBRARIES "/usr/lib/x86_64-linux-gnu/libCppUTest.a" "/usr/lib/x86_64-linux-gnu/libCppUTestExt.a")

# Добавление исходных файлов
set(SOURCES
    src/bit_edit.cpp
)

# Создание библиотеки
add_library(list_lib STATIC ${SOURCES})
target_include_directories(list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Добавление исполняемого файла для тестов
add_executable(TestBitEdit test/test_bit_edit.cpp)

# Подключение библиотеки и CppUTest к тестам
target_link_libraries(TestBitEdit
    PRIVATE
    list_lib
    ${CPPUTEST_LIBRARIES}
)

# Добавление директорий для поиска заголовочных файлов
target_include_directories(TestBitEdit
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CPPUTEST_INCLUDE_DIRS}
)

# Добавление тестов
enable_testing()
add_test(NAME TestBitEdit COMMAND TestDelete5ListElem)