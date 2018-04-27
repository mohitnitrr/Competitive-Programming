#include "bits_stdc.h"

int maxp3(vector<int> &A) {

	int n = A.size();

	if (n < 3)
		return -1;

	if (n == 3)
		return A[0] * A[1] * A[2];

	sort(A.begin(), A.end());
	
	int mul = A[n-1] * A[n-2] * A[n-3];

	if(A[n - 1] > 0 && A[n-2] *A[n - 3] <= A[0]*A[1])
		mul = A[n - 1] * A[0] * A[1];

	return mul;
	
}

int main_int18() {

	vector<int> input = { 58, 56, 27, -18, -37, -52, -28, 67, -5, -92, -8 };
	cout << maxp3(input);
	return 0;
}