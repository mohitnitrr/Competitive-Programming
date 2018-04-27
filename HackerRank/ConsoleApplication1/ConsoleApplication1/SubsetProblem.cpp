#include "bits_stdc.h"

void subsetProblemUtil(vector<int> &in, int index, vector<vector<int>> &out, vector<int>& currSubset) {

	if (index == in.size())
		out.push_back(currSubset);

	else {	
		subsetProblemUtil(in, index + 1, out, currSubset);
		currSubset.push_back(in[index]);
		subsetProblemUtil(in, index + 1, out, currSubset);
		currSubset.pop_back();
	}
}


vector<vector<int>> subsetProblem(vector<int>& in) {
	vector<vector<int>> out;
	vector<int> currSubset;
	subsetProblemUtil(in, 0, out, currSubset);
	sort(out.begin(), out.end());
	return out;
}




int main_intBit72() {

	vector<int> input = { 1,2,3 };
	//print2dVector(subsetProblem(input));

	return 0;
}