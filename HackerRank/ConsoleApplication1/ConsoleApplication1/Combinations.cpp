#include "bits_stdc.h"

void combinationsUtil(int n, int k, int index, vector<vector<int>> &out, vector<int>& currSubset) {

	if (currSubset.size() == k) {
		out.push_back(currSubset);
		return;
	}

	if (index > n)
		return;

	else {
		currSubset.push_back(index);
		combinationsUtil(n, k, index + 1, out, currSubset);
		currSubset.pop_back();
		combinationsUtil(n, k, index + 1, out, currSubset);
	}
}


vector<vector<int>> combinations(int n, int k) {
	vector<vector<int>> out;
	vector<int> currSubset;
	combinationsUtil(n, k, 1, out, currSubset);
	sort(out.begin(), out.end());
	return out;
}


int main_intBit73() {
	//print2dVector(combinations(4, 2));
	return 0;
}