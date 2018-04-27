#include "bits_stdc.h"

void uniquePermutationUtil(vector<int> &in, int index, vector<vector<int>> &out) {

	if (index == in.size() - 1)
		out.push_back(in);

	else {
		for (int i = index; i < in.size(); i++) {
			if (i != index && in[i] == in[index] || (i>index && in[i-1] == in[i])) // two cases regular character and character after gap // aabcee e should replace only once 
				continue;
			swap(in[i], in[index]);
			uniquePermutationUtil(in, index + 1, out);
			swap(in[i], in[index]);
		}
	}
}

vector<vector<int>> uniquePermutation(vector<int>& in) {
	sort(in.begin(), in.end());
	vector<vector<int>> out;
	uniquePermutationUtil(in, 0, out);
	return out;
}





int main_intBit88() {
	vector<int> input = { 0,0,0,1,9 };
	//print2dVector(uniquePermutation(input));
	return 0;

}