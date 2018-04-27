#include "bits_stdc.h"

int maxArr(vector<int> &arr) {


	int max1 = INT_MIN, min1 = INT_MAX;
	int max2 = INT_MIN, min2 = INT_MAX;

	for (int i = 0; i < arr.size(); i++) {

		// Updating max and min variables
		// as described in algorithm.
		max1 = max(max1, arr[i] + i);
		min1 = min(min1, arr[i] + i);
		max2 = max(max2, arr[i] - i);
		min2 = min(min2, arr[i] - i);
	}

	// Calculating maximum absolute difference.
	return max(max1 - min1, max2 - min2);
}


int main_int56() {

	return 0;
}