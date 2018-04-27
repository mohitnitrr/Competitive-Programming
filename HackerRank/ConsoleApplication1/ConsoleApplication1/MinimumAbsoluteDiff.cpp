#include "bits_stdc.h"

int minimumAbsDiff(vector<int> A, vector<int> B, vector<int> C) {

	int alength = A.size();
	int blength = B.size();
	int clength = C.size();
	int i = 0, j = 0, k=0;
	int outDiff = INT_MAX;
	while (i < alength && j < blength && k<clength) {

		int minVal = min(min(A[i], B[j]), C[k]);
		int maxVal = max(max(A[i], B[j]), C[k]);
		int diff = abs(maxVal - minVal);

		if (outDiff > diff)
			outDiff = diff;
		if (minVal == A[i])
			i++;
		else if (minVal == B[j])
			j++;
		else
			k++;
	}

	return outDiff;
}

int main_intBit44() {
	cout << minimumAbsDiff({ 1, 4, 5, 8, 10 }, { 6, 9, 10 }, { 2, 3, 6, 10 });
	return 0;
}