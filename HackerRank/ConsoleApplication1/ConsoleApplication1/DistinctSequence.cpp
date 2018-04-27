#include "bits_stdc.h"

int numDistinct(string A, string B) {

	int n = A.size();
	int m = B.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if(i == 0 && j ==0)
				dp[i][j] = 1;

			else if (i == 0)
				dp[i][j] = 0;

			else if (j == 0)
				dp[i][j] = 1;

			else {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	return dp[n][m];
}


int main_int12() {

	cout << numDistinct("GeeksforGeeks", "Gks");
	return 0;
}