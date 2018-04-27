#include "bits_stdc.h"

int majorityElement(const vector<int> &A) {
	int major_index = 0;
	int count = 1;
	for (int i = 1; i < A.size(); i++) {
		if (A[major_index] == A[i]) {
			count++;
		}
		else {
			count--;
		}

		if (count == 0) {
			major_index = i;
			count = 1;
		}
	}

	return A[major_index];
}

int main_int19() {

	vector<int> input = { 2, 1, 2 };
	cout << majorityElement(input);
	return 0;
}