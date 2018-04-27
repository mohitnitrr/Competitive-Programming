#include "bits_stdc.h"

int numDecodings(string A) {
	int n = A.size();
	vector<int> dp(n+1);
	dp[0] = 1;
	dp[1] = A[0] - '0'? 1 : 0;
	for (int i = 2; i <= n; i++) {
		int x = A[i-1] - '0';
		int y = A[i-2] - '0';
		if (x != 0) {
			dp[i] = dp[i - 1];
		}

		if(y==1 || (y==2 && x <7))
			dp[i] += dp[i - 2];	
	}

	return dp[n];
}
int main_int22() {
	cout << numDecodings("2611055971756562");
	return 0;
}