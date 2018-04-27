#include "bits_stdc.h"



vector<int> nearSmallerNumber(vector<int> input) {
	stack<int> minElement;
	vector<int> out;
	for (int i = 0; i < input.size();i++) {
		while (!minElement.empty() && minElement.top() >= input[i]) {
			minElement.pop();
		}

		if (minElement.empty()) {
			out.push_back(-1);
		}
		else {
			out.push_back(minElement.top());
		}

		minElement.push(input[i]);
	}
	
	return out;
}

int main_intBit66() {
	//printVector(nearSmallerNumber({ 4, 5, 2, 10, 8 }));

	return 0;
}