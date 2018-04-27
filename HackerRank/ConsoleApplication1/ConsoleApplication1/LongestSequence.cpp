#include "bits_stdc.h"

int longestSubsequenceLength(const vector<int> &A) {

	int n = A.size();
	vector<int>lToR(n, 1);
	vector<int>rToL(n, 1);

	// left to right
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j])
				lToR[i] = max(lToR[i], lToR[j] + 1);
		}
	}

	// left to right
	for (int i = n-2; i >=0; i--) {
		for (int j = n-1; j > i; j--) {
			if (A[i] > A[j])
				rToL[i] = max(rToL[i], rToL[j] + 1);
		}
	}

	int maxVal = 0;
	for (int i = 0; i < n; i++) {
		maxVal = max(maxVal, lToR[i] + rToL[i] - 1);
	}

	return maxVal;
}


int main_int9() {
	vector<int> input = { 1, 11, 2, 10, 4, 5, 2, 1 };
	cout << longestSubsequenceLength(input);
	return 0;
}