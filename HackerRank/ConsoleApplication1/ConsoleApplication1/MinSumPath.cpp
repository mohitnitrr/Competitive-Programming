#include "bits_stdc.h"

int minPathSum(vector<vector<int> > &A) {
	int r = A.size();
	int c = A[0].size();
	vector<vector<int>>  cost(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if(i ==0 && j == 0)
				cost[0][0] = A[0][0];
			else if (i == 0)
				cost[i][j] = cost[i][j - 1] + A[i][j];
			else if (j==0)
				cost[i][j] = cost[i-1][j] + A[i][j];
			else
				cost[i][j] = min(cost[i][j - 1], cost[i - 1][j]) + A[i][j];
		}
	}

	return cost[r - 1][c - 1];
}

int main_int6() {
	vector<vector<int>> in = { { 1, 3, 2 },{ 4, 3, 1 },{ 5, 6, 1} };
	cout << minPathSum(in);
	return 0;
}