#include "bits_stdc.h"

vector<int> rodCutUtil(int A, vector<int> &B, int l, int r) {

	vector<int> out;
	if (l > r)
		return out;
	else if (l == r)
		out.push_back(B[l]);
	else if (l + 1 == r) {
		out.push_back(B[l]);
		out.push_back(B[r]);
	}
	else {
		int mid = (r - l + 1) % 2 == 0 ? (l + r) / 2 + 1 : (l + r) / 2;
		out.push_back(B[mid]);
		vector<int> left = rodCutUtil(B[mid], B, l, mid - 1);
		vector<int> right = rodCutUtil(A-B[mid], B, mid + 1, r);
		out.insert(out.end(), left.begin(), left.end());
		out.insert(out.end(), right.begin(), right.end());
	}

	return out;
}
vector<int> rodCut(int A, vector<int> &B) {

	sort(B.begin(), B.end());
	return rodCutUtil(A, B, 0, B.size() - 1);
}

int main_int30() {

	vector<int> input = { 1,2,5 };
	vector<int> out = rodCut(6, input);

	for (auto i : out) {
		cout << i << " ";
	}

	return 0;
}