#include "bits_stdc.h"

int singleNumber(const vector<int> & input) {

	int xorOutput = 0;

	for (auto next : input) {
		xorOutput ^= next;
	}
	return xorOutput;
}


int singleNumber2(vector<int> inputs) {

	int output = 0;
	int inputCount = inputs.size();
	for (int i = 0; i < 31; i++) {
		int set_bit = 1 << i;

		int setbitCount = 0;;
		for (auto & next : inputs) {
			if (next & set_bit)
				setbitCount++;
		}
		if (setbitCount % 3 == 1) {
			output |= 1 << i;
		}
	}

	return output;
}

int main_intBit42() {
	//cout << singleNumber({ 1, 2, 2, 3, 1 });

	cout << singleNumber2({ 1, 2, 4, 3, 3, 2, 2, 3, 1, 1 });
	return 0;
}