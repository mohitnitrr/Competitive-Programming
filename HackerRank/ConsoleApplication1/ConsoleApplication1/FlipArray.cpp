#include "bits_stdc.h"


int solveFilpArray(const vector<int> &A) {

	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
	}

	int k = sum / 2;
	int n = A.size();
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 0; i <= k; i++) {
		dp[0][i] = 0;
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {

			dp[i][j] = dp[i - 1][j];

			if (j >= A[i - 1] && (j - A[i - 1] == 0 || dp[i - 1][j - A[i - 1]]> 0))
				dp[i][j] = min(dp[i][j], dp[i-1][j - A[i - 1]] + 1);
		}
	}

	int count = 0;
	for (int i = k; i >= 0; i--) {
		if (dp[n][i] > 0) {
			count = dp[n][i];
			break;
		}
	}

	return count;
}

/*int main() {

	vector<int> vec = { 18, 18, 20, 4, 3, 4, 22, 17, 9, 10, 19, 9, 19, 19, 17, 4, 17, 21, 17, 22, 11, 19, 1, 21, 11, 21, 22, 15, 20, 22, 22, 13, 15, 19, 14, 15, 1, 14, 9, 7, 1, 4, 16, 19 };
	cout << solveFilpArray(vec);
}*/