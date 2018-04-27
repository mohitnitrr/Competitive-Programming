#include "bits_stdc.h"

vector<int> twoSumAproch1(const vector<int> &B, int A) {

	vector<int> in(B.begin(), B.end());
	unordered_map<int, vector<int>> numberToIndex;
	for (int i = 0; i < in.size(); i++) {
		if (numberToIndex.find(in[i]) != numberToIndex.end()) {
			numberToIndex[in[i]].push_back(i);
		}
		else {
			vector<int> list;
			list.push_back(i);
			numberToIndex[in[i]] = list;
		}
	}

	sort(in.begin(), in.end());
	int l = 0;
	int r = in.size() - 1;
	vector<int>out;
	while (l < r) {

		if (in[l] + in[r] > A)
			r--;
		else if (in[l] + in[r] < A)
			l++;
		else {
			for (int j = 0; j < numberToIndex[in[r]].size(); j++) {
				for (int k = 0; k < numberToIndex[in[l]].size(); k++) {
					out.push_back(numberToIndex[in[l]][k]);
					out.push_back(numberToIndex[in[r]][j]);
				}
			}

			while (l< r && in[l] == in[l + 1])
				l++;

			while (l< r && in[r] == in[r - 1])
				r--;

			l++;
			r--;
		}
	}

	return out;
}

vector<int> twoSumAproch2(const vector<int> &in, int A) {

	vector<int> out;
	for (int i = 1; i < in.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (in[i] + in[j] == A) {
				out.push_back(j);
				out.push_back(i);
				return out;
			}
		}
	}

	return out;
}

void print1D_(vector<int> in) {

	for (auto n : in) {
		cout << n << " \t";
	}
}

int main_intBit80() {

	vector<int> input = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
	print1D_(twoSumAproch2(input, -3));
	return 0;
}