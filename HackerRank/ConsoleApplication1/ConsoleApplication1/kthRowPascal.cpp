#include "bits_stdc.h"

vector<long> getPascalKthRow(const int row) {

	vector<long> pascalRow;
	long next;
	for (int i = 0; i <= row; i++) {
		if (i == 0)
			next = 1;
		else
			next = next * (row - i + 1) / i;

		pascalRow.push_back(next);
	}

	return pascalRow;
}


int main_intBit4() {

	vector<long> returnVal = getPascalKthRow(3);
	for (auto &y : returnVal) {
		cout << y << " ";
	}

	

	return 0;
}