#include "bits_stdc.h"

vector<int> plusOne(vector<int> A) {

	int carry = 1;
	int index = A.size() - 1;
	vector<int> out;
	int msdIndex = 0;
	while (A[msdIndex] == 0)
		msdIndex++;

	while (carry != 0 && index >= msdIndex) {
		int lastDigit = (A[index] + 1) % 10;
		carry = (A[index] + 1) / 10;
		out.push_back(lastDigit);
		index--;
	}
	if (carry > 0)
		out.push_back(carry);

	while (index >= msdIndex) {
		out.push_back(A[index--]);
	}

	reverse(out.begin(), out.end());

	return out;
}

int main_int55() {
	vector<int> in = {0,7,9,9 };
	vector<int> out = plusOne(in);

	for (int i : out) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}