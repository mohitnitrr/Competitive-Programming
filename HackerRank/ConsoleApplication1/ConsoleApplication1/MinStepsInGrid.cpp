#include"bits_stdc.h"

int minGridSteps(const vector<int> &a, const vector<int> &b) {

	if (a.size() != b.size())
		return -1;

	int countSteps = 0;
	for (int i = 1; i < a.size(); i++) {
		int x1 = a[i];
		int y1 = b[i];

		int x2 = a[i-1];
		int y2 = b[i-1];

		countSteps += max(abs(x1 - x2), abs(y1 - y2));
	}

	return countSteps;
}

int main_intBit7() {

	vector<int> x = { 4, 8, -7, -5, -13, 9, -7, 8 };
	vector<int> y = { 0,1,2 };

	cout << minGridSteps(x, y);

	return 0;
}