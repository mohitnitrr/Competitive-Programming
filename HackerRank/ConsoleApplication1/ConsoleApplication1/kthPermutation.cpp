#include "bits_stdc.h"


void getKthPermutationUtil(vector<int>& in, int index, int B, int &count, vector<int>& out) {
	if (index == in.size() - 1) {
		count++;
		if (count == B)
			copy(in.begin(), in.end(), back_inserter(out));
	}
	else {
		for (int i = index; i < in.size() && count < B; i++) {
			swap(in[i], in[index]);
			getKthPermutationUtil(in, index + 1, B, count, out);
			swap(in[i], in[index]);
		}
	}
}

string getkthPermutation(int A, int B) {
	vector<int> in(A, 0);
	for (int i = 1; i <= A; i++) {
		in[i-1] = i;
	}
	int count = 0;
	vector<int> out;
	
	
	
	long int i = 1;
	do {
		// check for nth iteration
		if (i == B)
			break;

		i++;
	} while (next_permutation(in.begin(), in.end()));


	//getKthPermutationUtil(in, 0, B, count, out);
	string outString;
	for (auto i : in) {
		outString += to_string(i);
	}
	
	return outString;
}

/*int main() {

	cout << getkthPermutation(3, 6);
	return 0;
}*/