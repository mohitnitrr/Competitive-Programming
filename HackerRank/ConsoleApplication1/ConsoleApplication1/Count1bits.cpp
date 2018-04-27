#include "bits_stdc.h"

int count1bits(unsigned int n) {

	int count = 0;
	while (n > 0) {
		if (n & 1)
			count++;

		n >>= 1;
	}

	return count;
}

int reverseBit(unsigned int n) {

	int size_t = sizeof(unsigned int) * 8;
	unsigned int out = 0;

	for (int i = 0; i < size_t -1 ; i++) {
		out |= n & 1;
		n >>= 1;
		out <<= 1;
	}
	out |= n & 1;

	return out;
}

int main_intBit40() {

	cout << reverseBit(4294967295);
	return 0;
}