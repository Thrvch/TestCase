#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "prime.h"

TEST_GROUP(PrimeNumbersGroup) {};

TEST(PrimeNumbersGroup, TestFirstPrime) {
    std::vector<int> primes = compute_primes(1);
    CHECK_EQUAL(1, primes.size());
    CHECK_EQUAL(2, primes[0]);
}

TEST(PrimeNumbersGroup, TestFirstFivePrimes) {
    std::vector<int> primes = compute_primes(5);
    CHECK_EQUAL(5, primes.size());
    CHECK_EQUAL(2, primes[0]);
    CHECK_EQUAL(3, primes[1]);
    CHECK_EQUAL(5, primes[2]);
    CHECK_EQUAL(7, primes[3]);
    CHECK_EQUAL(11, primes[4]);
}

TEST(PrimeNumbersGroup, TestZeroPrimes) {
    std::vector<int> primes = compute_primes(0);
    CHECK_EQUAL(0, primes.size());
}

TEST(PrimeNumbersGroup, TestNegativePrimes) {
    std::vector<int> primes = compute_primes(-5);
    CHECK_EQUAL(0, primes.size());
}

int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
