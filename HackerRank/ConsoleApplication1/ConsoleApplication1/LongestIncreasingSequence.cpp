#include "bits_stdc.h"

int longestIncreasingLength(const vector<int> &A) {

	int n = A.size();
	vector<int>lToR(n, 1);
	int maxVal = 0;
	// left to right
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				lToR[i] = max(lToR[i], lToR[j] + 1);
				maxVal = max(maxVal, lToR[i]);
			}			
		}
	}
	return maxVal;
}

int main_int10(){
	vector<int> input = { 1, 11, 2, 10, 4, 5, 2, 1 };
	cout << longestIncreasingLength(input);
	return 0;
}