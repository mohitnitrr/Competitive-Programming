#include "bits_stdc.h"

int anytwo(string A) {

	int n = A.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i - 1] == A[j - 1] && i != j) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

			if (dp[i][j] > 1)
				return 1;
		}
	}

	return 0;
}

int main_int11() {

	cout << anytwo("abba");
	return 0;
}