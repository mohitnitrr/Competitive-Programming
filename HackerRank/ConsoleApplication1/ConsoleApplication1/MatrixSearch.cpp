#include "bits_stdc.h"

int doBinarySearch(vector<vector<int> > &A, int B, int outRow) {

	int l = 0;
	int r = A[0].size() - 1;

	while (l<= r) {
		int mid = (l + r) / 2;
		if (A[outRow][mid] == B)
			return mid;
		else if (B < A[outRow][mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return -1;
}

int searchMatrix(vector<vector<int> > &A, int B) {

	int row = A.size();
	int col = A[0].size();

	//first check for row
	int outRow = -1;
	for (int i = 0; i < row; i++) {
		if (A[i][0] <= B && B <= A[i][col - 1]) {
			outRow = i;
			break;
		}
	}

	if (outRow == -1)
		return 0;
	else {
		int outCol = doBinarySearch(A, B, outRow);
		if (outCol != -1)
			return 1;
	}

	return 0;
}


int main_intBit52() {

	vector<vector<int>> a = { { 1,   3,  5,  7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	cout << searchMatrix(a, 3);

	return 0;
}