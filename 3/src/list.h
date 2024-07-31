#pragma once

#include <cstddef>

struct SomeDataType {
    int value;
};

struct List {
    List* next;
    SomeDataType payload;
};

void removeEveryFifthElement(List*& head);
void deleteList(List*& head);
std::size_t listLength(const List* head);

