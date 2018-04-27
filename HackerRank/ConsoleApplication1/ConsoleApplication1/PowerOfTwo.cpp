#include"bits_stdc.h"

int gcd(int x, int y) {

	if (x == 0)
		return y;
	return gcd(y%x, x);
}

vector<int> seiveOfEratothenesModified(int n) {

	vector<bool> primes;
	int primesRequired = sqrt(n);
	primes.resize(primesRequired + 1);
	fill(primes.begin(), primes.end(), true);

	for (size_t i = 2; i <= primesRequired; i++)
	{
		if (primes[i]) {
			for (int j = i * 2; j <= primesRequired; j = j + i) {
				primes[j] = false;
			}
		}
	}

	vector<int> actualFactor;
	for (int i = 2; i <= primesRequired; i++) {
		if (primes[i] && n%i == 0) {
			actualFactor.push_back(i);
			if(primes[n/i])
				actualFactor.push_back(n / i);
		}
	}

	return actualFactor;
}

bool isPowerOfTwoInteger(int x) {

	if (x < 0)
		return false;

	vector<int> primes = seiveOfEratothenesModified(x);

	if (primes.size() == 0)
		return false;
	else {
		vector<int> powers;
		for (int &nextFactor : primes) {
			int count = 0;
			int temp = x;
			while (temp % nextFactor == 0) {
				count++;
				temp = temp / nextFactor;
			}
			powers.push_back(count);
		}

		if (powers.size() == 1 && powers[0] > 1)
			return true;
		else {
			int result = powers[0];
			for (int i = 1; i < powers.size(); i++)
				result = gcd(powers[i], result);

			return result == 1 ? false : true;
		}
	}

	return false;
}

int main_intBit17() {

	cout<< isPowerOfTwoInteger(7988)?"true":"false";
	return 0;
}