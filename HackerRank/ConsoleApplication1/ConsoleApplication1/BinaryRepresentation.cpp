#include "bits_stdc.h"

string binaryReprresentation(int n) {

	if (n == 0)
		return "0";

	string binStr;
	while (n > 0) {
		if (n & 1)
			binStr += '1';
		else
			binStr += '0';

		n = n >> 1;
	}

	reverse(binStr.begin(), binStr.end());

	return binStr;
}


int main_intBit25() {

	cout << binaryReprresentation(0);

	return 0;
}