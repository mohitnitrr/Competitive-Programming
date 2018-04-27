#include "bits_stdc.h"

bool isOpenBracketOROperator(char c) {
	return c == '(' || c=='^' || c=='*' || c=='+' || c=='-' || c=='/';
}

int braces(string A) {

	stack<char> bracketop;
	for (int i = 0; i < A.size(); i++) {
		if (isOpenBracketOROperator(A[i])) {
			bracketop.push(A[i]);
		}
		else if( A[i] == ')'){
			if (!bracketop.empty() && bracketop.top() == '(')
				return 1;
			else {
				while (!bracketop.empty() && bracketop.top() != '(') {
					bracketop.pop();
				}
				if (!bracketop.empty() && bracketop.top() == '(')
					bracketop.pop();
			}
		}
	}
	return 0;
}
int main_intBit68() {

	cout << braces("(a/b)+(b*d)+(a*a)+a");
	return 0;
}