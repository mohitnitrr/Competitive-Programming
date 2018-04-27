#include "bits_stdc.h"

int candy(vector<int> &A) {


	int candySum = 0;
	int minCurr = 1;
	for (int i = 0; i < A.size(); i++) {
		int backMax = 1;
		for (int j = i; j < A.size() - 1; j++) {
			if (A[j] > A[j + 1]) {
				backMax++;
			}
			else {
				break;
			}
		}

		if (i> 0 && A[i] > A[i - 1]) {
			minCurr++;
		}
		else if (minCurr > 1) {
			minCurr = backMax;
		}
		minCurr = max(minCurr, backMax);
		candySum += minCurr;
	}
	return candySum;
}


int main_int15() {
	vector<int> inputs = { 9,8,7,7,6,6,5,4,3 };
	cout << candy(inputs);

	return 0;
}