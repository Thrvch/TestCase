#include "list.h"
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>


TEST_GROUP(ListTest) {
    List* head;

    void setup()  {
        head = nullptr;
    }

    void teardown() {
        deleteList(head);
    }

    void createList(int size) {
        List* tail = nullptr;
        for (int i = 1; i <= size; ++i) {
            List* newNode = new List{nullptr, {i}};
            if (!head) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }
    }
};

TEST(ListTest, EmptyList) {
    removeEveryFifthElement(head);
    CHECK_EQUAL(0, listLength(head));
}

TEST(ListTest, LessThanFiveElements) {
    createList(4);
    removeEveryFifthElement(head);
    CHECK_EQUAL(4, listLength(head));
}

TEST(ListTest, ExactlyFiveElements) {
    createList(5);
    removeEveryFifthElement(head);
    CHECK_EQUAL(4, listLength(head));
    CHECK_EQUAL(1, head->payload.value);
    CHECK_EQUAL(4, head->next->next->next->payload.value);
}

TEST(ListTest, MoreThanFiveElements) {
    createList(11);
    removeEveryFifthElement(head);
    CHECK_EQUAL(9, listLength(head));
    CHECK_EQUAL(1, head->payload.value);
    CHECK_EQUAL(6, head->next->next->next->next->payload.value);
    CHECK_EQUAL(11, head->next->next->next->next->next->next->next->next->payload.value);
}

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
