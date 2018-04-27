#include "bits_stdc.h"


int minimumTotal(vector<vector<int> > &A) {

	int r = A.size();

	for (int i = 1; i < r; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				A[i][j] += A[i - 1][j];
			else if (j == i)
				A[i][j] += A[i - 1][j - 1];
			else {
				A[i][j] += min(A[i - 1][j - 1], A[i - 1][j]);
			}
		}
	}

	int ret = A[r-1][0];
	for (int i = 1; i <= r-1; i++)
		ret = min(ret, A[r - 1][i]);

	return ret;
}

int main_int47() {

	vector<vector<int>> in = { { 2 }, { 3,4 }, { 6,5,7 }, { 4,1,8,3 } };
	cout << minimumTotal(in);

	return 0;
}