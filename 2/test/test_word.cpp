#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "word.h"

TEST_GROUP(WordCounterTests) {};

TEST(WordCounterTests, EmptyString) {
    auto result = count_words("");
    CHECK_EQUAL(0, result.size());
}

TEST(WordCounterTests, SingleWord) {
    auto result = count_words("Hello");
    CHECK_EQUAL(1, result.size());
    CHECK_EQUAL(1, result.count(5));
}

TEST(WordCounterTests, MultipleWords) {
    auto result = count_words("The quick brown fox jumps over the lazy dog");
    CHECK_EQUAL(3, result.size());
    CHECK_EQUAL(4, result.count(3));  // "The", "fox", "the", "dog"
    CHECK_EQUAL(2, result.count(4));  // "over", "lazy"
    CHECK_EQUAL(3, result.count(5));  // "quick", "brown", "jumps"
}

TEST(WordCounterTests, WordsWithPunctuation) {
    auto result = count_words("Hello, world! How are you?");
    CHECK_EQUAL(2, result.size());
    CHECK_EQUAL(3, result.count(3));  // "How", "are", "you"
    CHECK_EQUAL(2, result.count(5));  // "Hello", "world"
}

TEST(WordCounterTests, WordsWithSymbolsAtMiddle) {
    auto result = count_words("his seven-layer cake only had six layers.");
    CHECK_EQUAL(4, result.size());
    CHECK_EQUAL(3, result.count(3));  // "had", "six", "his"
    CHECK_EQUAL(2, result.count(4));  // "cake", "only"
    CHECK_EQUAL(1, result.count(6));  // "layers"
    CHECK_EQUAL(1, result.count(11)); // "seven-layer"
}

TEST(WordCounterTests, WordsWithNumbers) {
    auto result = count_words("I bought 12 eggs, but 2 were broken.");
    CHECK_EQUAL(5, result.size());
    CHECK_EQUAL(2, result.count(1));  // "I", "2"
    CHECK_EQUAL(1, result.count(2));  // "12"
    CHECK_EQUAL(1, result.count(3));  // "but"
    CHECK_EQUAL(2, result.count(4));  // "eggs", "were"
    CHECK_EQUAL(2, result.count(6));  // "bought", "broken"
}

int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
