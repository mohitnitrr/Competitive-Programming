#include "bits_stdc.h"

vector<int> repeatAndMiss(vector<int> &arr) {
	int xorVal = 0;
	int n = arr.size();
	vector<int> retVal;

	for (auto &next : arr) {
		xorVal ^= next;
	}

	for (int i = 1; i <= n; i++) {
		xorVal ^= i;
	}

	int right_set_bit = xorVal & ~(xorVal - 1);
	int elementWithSetbit, elementWithOffbit;

	for (auto &next : arr) {
		if (next & right_set_bit)
			elementWithSetbit ^= next;
		else
			elementWithOffbit ^= next;
	}

	for (int i = 1; i <= n; i++) {
		if (i & right_set_bit)
			elementWithSetbit ^= i;
		else
			elementWithOffbit ^= i;
	}

	for (auto &next : arr) {
		if (next == elementWithSetbit) {
			retVal.push_back(elementWithSetbit); // repeating number
			retVal.push_back(elementWithOffbit); // missing number
			break;
		}
		else if (next == elementWithOffbit) {
			retVal.push_back(elementWithOffbit); // repeating number
			retVal.push_back(elementWithSetbit); // missing number
			break;
		}
	}

	return retVal;
}

int main_intBit6() {

	return 0;
}