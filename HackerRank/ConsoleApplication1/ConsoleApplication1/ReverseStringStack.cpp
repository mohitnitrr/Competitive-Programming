#include "bits_stdc.h"

string reverseStringStack(string str) {
	
	stack<char> stack;
	for (int i = 0; i < str.length(); i++) {
		stack.push(str[i]);
	}

	string out;
	while (!stack.empty()) {
		out += stack.top();
		stack.pop();
	}

	return out;
}

int main_intBit60() {

	cout << reverseStringStack("abc");
	return 0;
}