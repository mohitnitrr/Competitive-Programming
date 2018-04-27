#include "bits_stdc.h"

int hammingDistance(const vector<int> &A) {

	int n = A.size();
	int ret = 0;
	
	int maxEle = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxEle = max(maxEle, A[i]);
	}

	for (int i = 0; i < 32 && (1 << i) <= maxEle; i++) {
		int curr = 0;
		for (int j = 0; j < n; j++) {
			curr += A[j] & (1 << i)? 1 : 0;
		}

		ret += curr * (n - curr);
	}

	return 2*ret;
}

int main_int71() {

	vector<int>A = { 2, 4, 6 };
	cout<<hammingDistance(A);
	return 0;
}