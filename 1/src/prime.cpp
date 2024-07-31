#include "prime.h"
#include <cmath>

using namespace std;

vector<int> compute_primes(int N){
    if (N <= 0) {
        return {};
    }
	int limit = max(15, static_cast<int>(N * log(N) + N * log(log(N))));
	vector<bool> is_prime(limit+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i*i <= limit; ++i){
		if (is_prime[i]){
			for (int k = i*i; k <= limit; k += i){
				is_prime[k] = false;
			}
		}
	}

	vector<int> primes;
    for (int num = 2; num <= limit && primes.size() < static_cast<size_t>(N); ++num) {
        if (is_prime[num]) {
            primes.push_back(num);
        }
    }

    return primes;
}

