#include "bits_stdc.h"

bool checkValid(vector<int> &arr, int current_val, int bucket) {
	
	long long current_sum = 0;
	int requiredBucket = 1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > current_val)
			return false;
		if (current_sum + arr[i] > current_val) {
			requiredBucket++;
			current_sum = arr[i];
			if (requiredBucket > bucket)
				return false;
		}
		else {
			current_sum += arr[i];
		}
	}

	return true;
}

int paint(int A, int B, vector<int> &C) {
	
	int const M = 10000003;
	long long totalLength = 0;
	for (auto i : C) {
		totalLength += i;
	}

	long long l = 0;
	long long r = totalLength;
	long long minLength = LONG_MAX;
	while (l <= r) {
		
		int mid = (l + r) / 2;
		if (checkValid(C, mid, A)) {
			r = mid - 1;
			minLength = mid < minLength ? mid : minLength;
		}
		else {
			l = mid + 1;
		}
	}

	return (minLength * B) % M;
}
int main_intBit56() {

	vector<int> board = { 1, 10 };
	cout << paint(2, 5, board);
	return 0;
}