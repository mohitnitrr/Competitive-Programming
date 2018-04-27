#include"bits_stdc.h"
vector<int> seiveOfEratothenes(int n) {
	
	vector<bool> primes;
	primes.resize(n + 1);
	fill(primes.begin(), primes.end(), true);

	for (size_t i = 2; i <=n; i++)
	{
		if (primes[i]) {
			for (int j = i * 2; j <= n; j = j + i) {
				primes[j] = false;
			}
		}
	}

	vector<int> actualPrimes;
	for (int i = 2; i <= n; i++) {
		if (primes[i])
			actualPrimes.push_back(i);
	}

	return actualPrimes;
}

vector<int> primeSum(int n) {

	vector<int> primeSum;
	if (n <= 2 || n % 2 != 0)// even number
		return primeSum;

	vector<int> primes = seiveOfEratothenes(n);

	for (int i = 0; i < primes.size(); i++) {
		int diff = n - primes[i];
		if (binary_search(primes.begin(), primes.end(), diff)) {
			primeSum.push_back(primes[i]);
			primeSum.push_back(diff);
			break;
		}

	}
	
	return primeSum;
}

int main_intBit13() {
	
	primeSum(12);

	return 0;
}