#include "bits_stdc.h"

int isInterleave(string A, string B, string C) {

	int m = A.size();
	int n = B.size();

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = C[j - 1] == B[j - 1] && dp[i][j-1];

			else if (j == 0)
				dp[i][j] = C[i - 1] == A[i - 1] && dp[i-1][j];

			else if (A[i-1] == C[i + j - 1] && C[i + j - 1] != B[j - 1])
					dp[i][j] = dp[i - 1][j];
			else if (A[i - 1] != C[i + j - 1] && C[i + j - 1] == B[j - 1])
					dp[i][j] = dp[i][j - 1];
			else if (C[i + j - 1] == B[j - 1] && A[i - 1] == C[i + j - 1])
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
		}
	}

	return dp[m][n];
}


int main_int13() {

	cout << isInterleave("eZCHXr0CgsB4O3TCDlitYI7kH38rEElI", "UhSQsB6CWAHE6zzphz5BIAHqSWIY24D", "eUZCHhXr0SQsCgsB4O3B6TCWCDlAitYIHE7k6H3z8zrphz5EEBlIIAHqSWIY24D");
	return 0;
}