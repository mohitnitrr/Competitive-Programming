#include "bits_stdc.h"

int maxRectangle(vector<int> input) {
	stack<int> increasingOrder;
	int max_rect = 0;
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
	int rhs = increasingOrder.empty() ? 0: increasingOrder.top();
	while (!increasingOrder.empty()) {
		int h = input[increasingOrder.top()]; increasingOrder.pop();
		int lhs = increasingOrder.empty() ? -1 : increasingOrder.top();
		
		max_rect = max((h*(rhs - lhs)), max_rect);
	}

	return max_rect;
}

int main_intBit69() {

	cout << maxRectangle({ 6, 2, 5, 4, 5, 1, 6 });
	return 0;
}