#include "bits_stdc.h"

int countElementInArray(vector<int> &a, int val) {

	int l = 0;
	int r = a.size() - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (a[mid] <= val)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return r;
}

int matrixMedian(vector<vector<int> > &A) {
	int row = A.size();
	int col = A[0].size();

	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < row; i++) {
		if (A[i][0] < min)
			min = A[i][0];
		if (A[i][col - 1] > max)
			max = A[i][col - 1];
	}

	int desired = (row * col + 1) / 2;
	while (min < max) {
		int mid = (min + max) / 2;
		int place = 0;
		for (int i = 0; i < row; i++) {
			place += countElementInArray(A[i], mid) + 1;
		}
		if (place < desired)
			min = mid + 1;
		else
			max = mid - 1;
	}

	return min;
}

int main_intBit53() {
	vector<vector<int>> a = { { 1, 3, 5 },{ 2, 6, 9 },{ 3, 6, 9 } };
	cout << matrixMedian(a);
	return 0;
}