#include "bits_stdc.h"

vector<int> wave(vector<int> &A) {

	vector<int>out;
	sort(A.begin(), A.end());
	int n = A.size();
	for (int i = 0; i < n; i = i + 2) {
		if(i+1 < n) out.push_back(A[i + 1]);
		out.push_back(A[i]);
	}

	return out;
}

/*int main() {
	vector<int>  in = {1,2,3,4,5,6};
	vector<int> out = wave(in);
	for (int i : out) {
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}*/