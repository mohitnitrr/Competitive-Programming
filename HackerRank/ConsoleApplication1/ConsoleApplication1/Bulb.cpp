#include "bits_stdc.h"


int bulbs(vector<int> &A) {

	int soFarSwitches = 0;
	for (int i = 0; i < A.size(); i++) {
		if (((soFarSwitches % 2 == 1) && A[i] == 1) || ((soFarSwitches % 2 == 0) && A[i] == 0))
			soFarSwitches++;
	}

	return soFarSwitches;
}


int main_int17() {
	vector<int>input = { 0, 1, 0, 1 };
	cout << bulbs(input);
	return 0;
}