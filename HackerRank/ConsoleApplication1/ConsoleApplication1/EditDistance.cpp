#include "bits_stdc.h"

int minDistance(string A, string B) {
	int m = A.size();
	int n = B.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1,0));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;

			else if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
			}
		}
	}

	return dp[m][n];
}


int main_int24() {

	cout << minDistance("Anshuman", "Antihuman");
	return 0;
}