#include "bits_stdc.h"


int maximumGap(const vector<int> &A) {

	if (A.size() < 2)
		return 0;

	int maxVal = INT_MIN;
	int minVal = INT_MAX;
	for (int i = 0; i < A.size(); i++) {
		maxVal = max(maxVal, A[i]);
		minVal = min(minVal, A[i]);
	}

	vector<bool> present(maxVal, false);
	for (int i = 0; i < A.size(); i++) {
		present[A[i] - 1] = true;
	}

	int diff = INT_MIN;
	int prevIndex = minVal - 1;
	for (int i = minVal; i < maxVal; i++) {
		if (present[i]) {
			diff = max(diff, i - prevIndex);
			prevIndex = i;
		}
	}

	return diff;
}

int maximumGap1(const vector<int> &A) {

	if (A.size() < 2)
		return 0;

	vector<int> temp(A);
	sort(temp.begin(), temp.end());
	int diff = INT_MIN;
	for (int i = 1; i < temp.size(); i++) {
		diff = max(diff, temp[i] - temp[i - 1]);
	}

	return diff;
}

int main_int54() {

	vector<int> in = { 1,10,5, 6, 18 };
	cout << maximumGap1(in);
	return 0;
}