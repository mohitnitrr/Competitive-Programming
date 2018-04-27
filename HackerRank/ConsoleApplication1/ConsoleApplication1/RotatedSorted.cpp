#include "bits_stdc.h"

int search(const vector<int> &A, int B) {
	int n = A.size();

	if (n == 0) {
		return -1;
	}

	int l = 0;
	int r = n - 1;

	while (r>=0 && l<n && l <= r) {
		int mid = (l + r) / 2;
		if (A[mid] == B)
			return mid;
		if (A[l] <= A[mid]) {
			if (A[l] <= B && B < A[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		else if (A[mid +1] <= A[r]) {
			if (A[mid + 1] <= B && B <= A[r])
				l = mid + 1;
			else
				r = mid - 1;
		}
	}

	return -1;
}


int main_intBit50() {

	cout << search({ 101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100 }, 202);
	return 0;
}