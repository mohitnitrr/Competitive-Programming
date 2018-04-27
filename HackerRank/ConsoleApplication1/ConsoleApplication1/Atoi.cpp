#include "bits_stdc.h"

bool isNumeric(char c) {
	
	if (c >= '0' && c <= '9')
		return true;

	return false;
}

bool isOverflow(int out, int next) {

	int maxVal = INT_MAX;
	int base = maxVal / 10;
	int mod = maxVal % 10;
	if (base < out || (base == out && next >= mod))
		return true;

	return false;
}

int atoi(const string A) {
	if (A.size() < 1)
		return 0;

	int isNegative = 0;
	if (A[0] == '-')
		isNegative = 1;
	

	int out = 0;
	for (int i = 0; i < A.size(); i++) {

		if (i == 0 && (A[i] == '-' || A[i] == '+'))
			continue;

		if (isNumeric(A[i])) {
			if (isOverflow(out, A[i] - '0')) {
				out = isNegative ? INT_MIN : INT_MAX;
				isNegative = false;
				break;
			}
			else
				out = out * 10 + A[i] - '0';
		}
		else {
			break;
		}
	}

	if (isNegative)
		out = -out;

	return out;
}


int main_int74() {

	cout << atoi("-54332872018247709407 4 54");
	return 0;
}