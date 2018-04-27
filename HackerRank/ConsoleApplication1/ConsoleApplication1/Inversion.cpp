#include "bits_stdc.h"


int countInversions(vector<int> &A) {

	int count = 0;
	for (int i = 1; i < A.size(); i++) {
		for (int j = i; j > 0 && A[j] < A[j - 1]; j--) {
			swap(A[j], A[j-1]);
			count++;
		}
	}

	return count;
}

int main_int5() {
	vector<int> input = { 2, 4, 1, 3, 5 };
	cout << countInversions(input);

	return 0;
}