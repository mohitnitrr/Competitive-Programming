#include "bits_stdc.h"

bool isOpenBracket(char c) {
	return c == '(' || c == '{' || c == '[';
}

bool isCloseBracket(char c) {
	return c == ')' || c == '}' || c == ']';
}

char similarOpenBracket(char c) {
	if (c == ')')
		return '(';
	else if (c == '}')
		return '{';
	else
		return '[';
}

int isValidParathesis(string str) {

	stack<char> openedBrackets;
	for (int i = 0; i < str.length(); i++) {
		if (isOpenBracket(str[i]))
			openedBrackets.push(str[i]);
		else {
			if (openedBrackets.size() >0 && openedBrackets.top() == similarOpenBracket(str[i]))
				openedBrackets.pop();
			else
				return 0;
		}
	}

	if (openedBrackets.size() > 0)
		return 0;

	return 1;
}

int main_intBit61() {

	cout << isValidParathesis("]}");
	return 0;
}