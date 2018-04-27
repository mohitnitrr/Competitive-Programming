#include "bits_stdc.h"

int mice(vector<int> &A, vector<int> &B) {

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int maxMove = INT_MIN;
	for (int i = 0; i < A.size(); i++) {
		maxMove = max(maxMove, abs(B[i] - A[i]));
	}

	return maxMove;
}
int main_int16() {
	return 0;
}