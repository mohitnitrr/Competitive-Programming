#include "bits_stdc.h"

vector<int> equal(vector<int> &A) {

	unordered_map<int, vector<int>> sumToIndex;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			int sum = A[i] + A[j];
			if (sumToIndex.find(sum) == sumToIndex.end())
				sumToIndex[sum] = { i,j };
			else {
				sumToIndex[sum].push_back(i);
				sumToIndex[sum].push_back(j);
			}
		}
	}

	vector<vector<int>> out;
	for (auto val : sumToIndex) {
		if (val.second.size() > 2) {
			out.push_back(val.second);
		}
	}

	sort(out.begin(), out.end());
	vector<int> res(out[0].begin(), out[0].begin() + 4);
	return res;
}

int main_intBit86() {

	vector<int> inputs = { 3, 4, 7, 1, 2, 9, 8 };
	
	vector<int> output = equal(inputs);
	for (auto x : output) {
		cout << x << " \t";
	}
	return 0;
}