#include "bits_stdc.h"

int diffK(vector<int> arr, int k) {

	int n = arr.size();
	int l = 0;
	int r = 1;

	while (r < n && l < n) {
		if (arr[r] - arr[l] == k && l != r)
			return 1;
		else if (arr[r] - arr[l] > k)
			l++;
		else
			r++;
	}

	return 0;
}

int main_intBit45() {

	cout << diffK({ 1, 3, 5 }, 0);
	return 0;
}