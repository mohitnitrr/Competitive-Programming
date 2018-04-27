#include "bits_stdc.h"

int maxRectangle1(vector<int> input, bool sortIn = false) {
	stack<int> increasingOrder;
	int max_rect = 0;

	if (sortIn)
		sort(input.begin(), input.end(), greater<int>());

	for (int i = 0; i < input.size(); i++) {
		while (!increasingOrder.empty() && input[increasingOrder.top()] > input[i]) {
			int h = input[increasingOrder.top()];
			increasingOrder.pop();
			int rhs = i - 1;
			int lhs = increasingOrder.empty() ? -1 : increasingOrder.top();
			max_rect = max((h*(rhs - lhs)), max_rect);
		}
		increasingOrder.push(i);
	}
	int rhs = increasingOrder.empty() ? 0 : increasingOrder.top();
	while (!increasingOrder.empty()) {
		int h = input[increasingOrder.top()]; increasingOrder.pop();
		int lhs = increasingOrder.empty() ? -1 : increasingOrder.top();

		max_rect = max((h*(rhs - lhs)), max_rect);
	}

	return max_rect;
}

int maximalRectangle(vector<vector<int> > &A) {

	int r = A.size();
	int c = A[0].size();

	vector<vector<int>> rectMat(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (i == 0)
				rectMat[i][j] = A[i][j];
			else {
				rectMat[i][j] = A[i][j] == 1 ? rectMat[i - 1][j] + A[i][j] : 0;
			}
		}
	}
	int maxVal = INT_MIN;
	for (int i = 0; i < r; i++) {
		maxVal = max(maxVal, maxRectangle1(rectMat[i], true));
	}

	return maxVal;
}

int main_int49() {
	vector<vector<int>> in = { { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 }, { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
	{ 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 } };
	//{ {1,1},{1,1} };
	cout << maximalRectangle(in);
	return 0;
}