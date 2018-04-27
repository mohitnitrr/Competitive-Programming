#include "bits_stdc.h"

int colorFulNumber(int A) {
	
	vector<int> digits(10, 0);
	int n = A;
	int count = A == 0 ? 1 : 0;
	while (n > 0) {
		int rem = n % 10;
		digits[rem]++;
		n = n / 10;
		count++;
	}

	if (count > 1 && (digits[0] || digits[1]))
		return 0;

	if ((digits[8] && digits[2] && digits[4]) || (digits[2] && digits[3] && digits[6])) {
		n = A;
		while (n > 0) {
			int rem = n % 10;
			if (rem == 2 || rem == 3 || rem == 4)
				rem = n % 100;
			if ((digits[8] && (rem == 42 || rem == 24)) || (digits[6] && (rem == 23 || rem == 32)))
				return 0;
			n = n / 10;
		}
	}

	for (int i = 1; i < 10; i++) {
		if (digits[i] > 1)
			return 0;
	}

	return 1;
}


int main_intBit79() {

	cout<< colorFulNumber(3245);
	return 0;
}