#include "bits_stdc.h"

stack<int> storage;
int minVal = INT_MAX;

class MinStack {

public:
	MinStack();
	void push(int x);
	void pop();
	int top();
	int getMin();

};

MinStack::MinStack() {
};

void MinStack::push(int x) {
	if (storage.empty()) {
		storage.push(x);
		minVal = x;
	}
	else if (x < minVal) {
		int val = 2 * x - minVal;
		storage.push(val);
		minVal = x;
	}
	else {
		storage.push(x);
	}

};

void MinStack::pop() {
	if (!storage.empty()) {
		if (storage.top() < minVal) {
			minVal = 2 * minVal - storage.top();
			storage.pop();
		}
		else {
			storage.pop();
		}
	}
};

int MinStack::top() {
	if (storage.empty())
		return -1;

	else if(storage.top() < minVal) {
		return minVal;
	}
	return storage.top();
};

int MinStack::getMin() {
	if (storage.empty())
		return -1;

	return minVal;
};

int main_intBit62() {
	
	MinStack minStack;
	cout << minStack.getMin();

	minStack.push(680232627);
	minStack.push(383101258);
	minStack.push(240914318);
	cout << minStack.getMin();

	return 0;
}