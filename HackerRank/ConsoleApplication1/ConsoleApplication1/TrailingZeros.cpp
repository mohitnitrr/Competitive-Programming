#include "bits_stdc.h"

int trailingZeros(int n) {

	int count5s = 0;
	while (n != 0) {
		count5s += n / 5;
		n = n / 5;
	}

	return count5s;
}

int main_intBit14() {
	
	cout << trailingZeros(5);

	return 0;
}