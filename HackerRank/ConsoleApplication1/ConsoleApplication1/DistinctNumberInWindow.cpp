#include "bits_stdc.h"


vector<int> dNums(vector<int> &A, int B) {

	vector<int>result;
	map<int, int> keyCount;

	for (int i = 0; i < B; i++) {
		if (keyCount.find(A[i]) != keyCount.end()) {
			keyCount[A[i]]++;
		}
		else
			keyCount[A[i]] = 1;
	}
	result.push_back(keyCount.size());
	for (int i = B; i < A.size(); i++) {
		keyCount[A[i - B]]--;
		if (keyCount[A[i - B]] == 0)
			keyCount.erase(A[i - B]);

		if (keyCount.find(A[i]) != keyCount.end()) {
			keyCount[A[i]]++;
		}
		else
			keyCount[A[i]] = 1;
		result.push_back(keyCount.size());
	}

	return result;
}

int main_intBit90() {
	vector<int> input = { 1, 2, 1, 3, 4, 3 };
	vector<int> out = dNums(input, 3);
	for (auto i : out) {
		cout << i << "\t";
	}
	cout << "\n";
	return 0;
}