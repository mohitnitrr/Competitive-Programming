#include "bits_stdc.h"

bool checkValidity(vector<int> &arr, int current_val, int bucket) {

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

int bookAllocate(vector<int> &A, int B) {

	long long totalPages = 0;
	if (B > A.size())
		return -1;

	for (auto i : A) {
		totalPages += i;
	}

	long long l = 0;
	long long r = totalPages;
	long long minPages = LONG_MAX;
	while (l <= r) {

		int mid = (l + r) / 2;
		if (checkValidity(A, mid, B)) {
			r = mid - 1;
			minPages = mid < minPages ? mid : minPages;
		}
		else {
			l = mid + 1;
		}
	}

	return minPages;
}
int main_intBit55() {

	vector<int> board = { 1, 10 };
	//cout << paint(2, 5, board);
	return 0;
}