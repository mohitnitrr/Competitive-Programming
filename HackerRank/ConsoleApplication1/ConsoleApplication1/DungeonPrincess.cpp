#include "bits_stdc.h"


int calculateMinimumHP(vector<vector<int> > &A) {

	int m = A.size();
	int n = A[0].size();

	vector<vector<int>>dp(m, vector<int>(n, 0));
	vector<vector<int>>res(m, vector<int>(n, 0));
	int minVal = INT_MIN;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = A[i][j];
				res[i][j] = dp[i][j] < 0 ? -dp[i][j] + 1 : 0;
			}
			else if (i == 0) {
				dp[i][j] = A[i][j] + dp[i][j - 1];
				res[i][j] = max(dp[i][j] <= 0 ? -dp[i][j] + 1 : INT_MIN,  res[i][j-1]);
			}
			else if (j == 0) {
				dp[i][j] = A[i][j] + dp[i - 1][j];
				res[i][j] = max(dp[i][j] <= 0 ? -dp[i][j] + 1 :INT_MIN, res[i-1][j]);
			}
				
			else {
				if (res[i - 1][j] < res[i][j - 1]) {
					dp[i][j] = dp[i - 1][j] + A[i][j];
					res[i][j] = max((dp[i][j] <= 0 ? -dp[i][j] + 1 : INT_MIN), res[i - 1][j]);
				}
				else {
					dp[i][j] = dp[i][j - 1] + A[i][j];
					res[i][j] = max((dp[i][j] <= 0 ? -dp[i][j] + 1 : INT_MIN), res[i][j - 1]);
				}
			}
			
		}
	}

	return res[m-1][n-1];
}

int main26() {
	vector<vector<int>> input = { {-2,-3,3}, {-5,-10,1},{10,30,-5} };
	cout << calculateMinimumHP(input);
	return 0;
}