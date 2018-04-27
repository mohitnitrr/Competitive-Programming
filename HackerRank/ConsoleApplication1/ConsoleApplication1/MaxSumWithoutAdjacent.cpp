#include "bits_stdc.h"

int adjacent(vector<vector<int> > &A) {
	
	int r = A.size();
	int c = A[0].size();

	vector<vector<int>> dp(r, vector<int>(c + 1, 0));
	for (int j = 1; j <= c; j++) {
		for (int i = 0; i < r; i++) {
			if (j == 1)
				dp[i][j] = A[i][j-1];
			else if (i == 0) {
				dp[i][j] = max(max(dp[i][j - 1],dp[i+1][j-1]), max(dp[i][j - 2] , dp[i+1][j-2])+ A[i][j-1]);
			}
			else {
				int notIncluding = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
				int including = max(dp[i][j - 2], dp[i - 1][j - 2]) + A[i][j-1];
				dp[i][j] = max(notIncluding, including);
			}
		}
	}

	return dp[r-1][c];
}

int main_int50() {
	vector<vector<int>> in = { {1, 2, 3, 4}, { 2,3, 4, 5 } };

	cout << adjacent(in);

	return 0;
}