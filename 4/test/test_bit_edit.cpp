#include "bit_edit.h"
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>


TEST_GROUP(BitManipulatorTests) {};

TEST(BitManipulatorTests, TestZero) {
    auto result = getMinMax(0);
    CHECK_EQUAL(0u, result.first);
    CHECK_EQUAL(0u, result.second);
}

TEST(BitManipulatorTests, TestAllOnes) {
    auto result = getMinMax(UINT32_MAX);
    CHECK_EQUAL(UINT32_MAX, result.first);
    CHECK_EQUAL(UINT32_MAX, result.second);
}

TEST(BitManipulatorTests, TestSingleBit) {
    auto result = getMinMax(1);
    CHECK_EQUAL(1u, result.first);
    CHECK_EQUAL(0x80000000u, result.second);
}

TEST(BitManipulatorTests, TestMultipleBits) {
    auto result = getMinMax(0b10101010);
    CHECK_EQUAL(0b1111, result.first);
    CHECK_EQUAL(0xF0000000u, result.second);
}

TEST(BitManipulatorTests, TestAlternateBits) {
    auto result = getMinMax(0xAAAAAAAA);
    CHECK_EQUAL(0xFFFF, result.first);
    CHECK_EQUAL(0xFFFF0000, result.second);
}


int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
