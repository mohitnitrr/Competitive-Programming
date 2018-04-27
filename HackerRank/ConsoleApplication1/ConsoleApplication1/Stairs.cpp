#include "bits_stdc.h"

int climbStairs(int A) {
	vector<int>countWays(A+1,0);
	for (int i = 0; i <= A; i++) {
		if (i <= 2)
			countWays[i] = i;
		else {
			countWays[i] = countWays[i - 1] + countWays[i - 2];
		}
	}

	return countWays[A];
}

int main_int7() {

	cout << climbStairs(3);
	return 0;
}