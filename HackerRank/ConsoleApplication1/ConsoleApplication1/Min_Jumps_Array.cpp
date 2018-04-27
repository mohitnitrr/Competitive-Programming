#include "bits_stdc.h"

int min_Jumps_Array(vector<int> A) {
	
	int n = A.size();
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] >= (i - j) && dp[j] != INT_MAX)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}

	return (dp[n - 1] == INT_MAX)? -1: dp[n-1];
}

int min_Jumps_Array2(vector<int> A) {

	int n = A.size();
	vector<int> dp(n, 0);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = A[i]; j < n; j++) {
			dp[j] = min(dp[j], dp[j-A[i]]+1);
		}
	}

	return (dp[n - 1] == 0) ? -1 : dp[n - 1];
}

int main_int14() {
	vector<int> in = { 33, 21, 50, 0, 0, 46, 34, 3, 0, 12, 33, 0, 31, 37, 15, 17, 34, 18, 0, 4, 12, 41, 18, 35, 37, 34, 0, 47, 0, 39, 32, 49, 5, 41, 46, 26, 0, 2, 49, 35, 4, 19, 2, 27, 23, 49, 19, 38, 0, 33, 47, 1, 21, 36, 18, 33, 0, 1, 0, 39, 0, 22, 0, 9, 36, 45, 31, 4, 14, 48, 2, 33, 0, 39, 0, 37, 48, 44, 0, 11, 24, 16, 10, 23, 22, 41, 32, 14, 22, 16, 23, 38, 42, 16, 15, 0, 39, 23, 0, 42, 15, 25, 0, 41, 2, 48, 28 };
	cout << min_Jumps_Array2(in);
	return 0;
}