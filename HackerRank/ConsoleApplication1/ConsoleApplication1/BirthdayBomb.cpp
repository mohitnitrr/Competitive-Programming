#include "bits_stdc.h"

vector<int> solve(int A, vector<int> &B) {

	int n = B.size();
	vector<vector<int>> dp(n);
	vector<int>sum(n, 0);

	if(B[0] <= A ) dp[0].push_back(0);
	sum[0] = B[0];
	int maxSum = INT_MIN;
	int retIndex = 0;
	for (int i = 1; i < n; i++) {
		sum[i] = B[i];
		for (int j = 0; j < i; j++) {
			int currSum = sum[j] + B[i];
			if (currSum > sum[i] && currSum <= A) {
				dp[i].clear();
				dp[i] = dp[j];
				sum[i] = currSum;

				if (currSum > maxSum) {
					maxSum = currSum;
					retIndex = i;
				}
			}
		}
		dp[i].push_back(i);
	}

	
	return dp[retIndex];
}

int main_int25() {

	vector<int> in = { 6,8,5,4,7 };
	vector<int> out = solve(11, in);

	for (auto x : out) {
		cout << x << " ";
	}

	return 0;
}

