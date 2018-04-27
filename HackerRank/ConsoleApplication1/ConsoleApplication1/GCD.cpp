#include "bits_stdc.h"

int GCD(int x, int y) {

	if (x == 0)
		return y;
	return GCD(y%x, x);
}

int main_intBit16() {

	cout << GCD(6, 9);

	return 0;
}