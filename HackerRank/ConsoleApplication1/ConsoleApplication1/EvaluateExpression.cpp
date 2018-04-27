#include "bits_stdc.h"

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int evalRPN(vector<string> A) {
	stack<int>operands;
	for (int i = 0; i < A.size(); i++) {
		if (isdigit(A[i][0]) || atoi(A[i].c_str())) {
			operands.push(atoi(A[i].c_str()));
		}
		else {
			int b = operands.top();
			operands.pop();
			int a = operands.top();
			operands.pop();
			if (A[i].compare("/") == 0) {
				operands.push(a / b);
			}
			else if (A[i].compare("*") == 0) {
				operands.push(a * b);
			}
			else if (A[i].compare("+") == 0) {
				operands.push(a + b);
			}
			else if (A[i].compare("-") == 0) {
				operands.push(a - b);
			}
		}
	}

	return operands.top();
}

int main_intBit65() {

	vector<string> pos = { "-500", "-10", "/" };
	cout << evalRPN(pos);
	return 0;
}