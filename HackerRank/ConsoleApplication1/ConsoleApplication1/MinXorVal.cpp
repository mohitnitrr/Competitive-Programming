#include "bits_stdc.h"

int minXorVal(vector<int> inputs) {

	sort(inputs.begin(), inputs.end());
	int n = inputs.size();
	int minXor = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		int xor = inputs[i] ^ inputs[i + 1];
		if (xor < minXor) {
			minXor = xor;
		}
	}
	return minXor;
}



int main_intBit38() {

	cout << minXorVal({ 0, 4, 7, 9 });
	return 0;
}