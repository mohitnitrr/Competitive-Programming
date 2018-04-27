#include "bits_stdc.h"

int xorSum(vector<int> inputs) {

	const unsigned int M = 1000000007;
	long countBits = 0;
	int inputCount = inputs.size();
	for (int i = 0; i < 31; i++) {
		int set_bit = 1 << i;

		int setbitCount = 0;;
		for (auto & next : inputs) {
			if (next & set_bit)
				setbitCount++;
		}

		countBits += setbitCount*(inputCount - setbitCount)*2;
		countBits %= M;
	}

	return countBits;
}


int main_intBit41() {

	cout << xorSum({1, 3, 5});
	return 0;
}