#include "list.h"

void removeEveryFifthElement(List*& head) {
    if (!head) return;

    List* current = head;
    List* prev = nullptr;
    int count = 0;

    while (current) {
        count++;
        if (count == 5) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            List* temp = current;
            current = current->next;
            delete temp;
            count = 0;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void deleteList(List*& head) {
    while (head) {
        List* temp = head;
        head = head->next;
        delete temp;
    }
}

size_t listLength(const List* head) {
    size_t length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}
