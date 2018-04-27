#include "bits_stdc.h"

void combinationSumUtil(vector<int> in, int sum, int index, vector<vector<int>> &out, vector<int>& currSubset) {

	if (0 == sum) {
		out.push_back(currSubset);
		return;
	}

	if (index >= in.size() || sum < 0)
		return;
	else {
		if(in[index] > sum)
			combinationSumUtil(in, sum, index + 1, out, currSubset);
		else {
			currSubset.push_back(in[index]);
			combinationSumUtil(in, sum - in[index], index+1, out, currSubset);
			currSubset.pop_back();
			combinationSumUtil(in, sum, index + 1, out, currSubset);
		}
	}
}


vector<vector<int>> combinationSum(vector<int> input, int sum) {
	vector<vector<int>> out;
	vector<int> currSubset;
	sort(input.begin(), input.end());
	//input.erase(unique(input.begin(), input.end()), input.end());
	combinationSumUtil(input, sum, 0, out, currSubset);
	sort(out.begin(), out.end());
	return out;
}


int main_intBit74() {
	vector<int> input = { 8, 10, 6, 11, 1, 16, 8 };
	//print2dVector(combinationSum(input, 28));

	return 0;
}