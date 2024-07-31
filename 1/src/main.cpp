#include <iostream>
#include "prime.h"

using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> primes = compute_primes(N);
    cout << "First " << N << " prime numbers are: ";
    for (int prime : primes) {
    	cout << prime << " ";
    }
    cout << endl;

    return 0;
}



