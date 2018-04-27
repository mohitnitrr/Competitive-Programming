#include "bits_stdc.h"

int verifyPrime(int n) {
	if (n < 2)
		return 0;
	if (n < 4)
		return 1;
	else {
		if (n % 2 == 0 || n % 3 == 0)
			return 0;
		else {
			for (int i = 5; i*i < n; i = i + 6)
				if (n%i == 0 || n % (i + 2) == 0)
					return 0;
		}

	}

	return 1;
}

int main_intBit23() {
	cout << verifyPrime(84923);

	return 0;
}