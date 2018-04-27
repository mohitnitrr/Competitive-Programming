#include "bits_stdc.h"

int uniquePathsWithObstacles(vector<vector<int> > &A) {

	int r = A.size();
	int c = A[0].size();
	vector<vector<int>> sol(r, vector<int>(c, 0));

	sol[0][0] = A[0][0] == 1 ? 0 : 1;

	for (int i = 1; i < c; i++)
		sol[0][i] = A[0][i] == 1 ? 0 : sol[0][i - 1];

	for (int i = 1; i < r; i++)
		sol[i][0] = A[i][0] == 1 ? 0 : sol[i-1][0];

	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			sol[i][j] = A[i][j] == 1 ? 0 : sol[i - 1][j] + sol[i][j - 1];
		}
	}

	return sol[r - 1][c - 1];
}


int uniquePaths(int A, int B) {

	vector<vector<int>> sol(A, vector<int>(B, 0));

	for (int i = 0; i < B; i++)
		sol[0][i] = 1;

	for (int i = 1; i < A; i++)
		sol[i][0] = 1;

	for (int i = 1; i < A; i++) {
		for (int j = 1; j < B; j++) {
			sol[i][j] = sol[i - 1][j] + sol[i][j - 1];
		}
	}

	return sol[A - 1][B - 1];
}


/*int main() {

	cout << uniquePaths(2, 2);
}*/
int main_int46() {

	vector<vector<int>> in = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	cout << uniquePathsWithObstacles(in);
	return 0;
}