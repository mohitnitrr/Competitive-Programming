#include "bits_stdc.h"

string divideByTwo(string instr) {

	string out;
	int rem = 0;
	for (int i = 0; i < instr.length(); i++) {
		int val = instr[i] - '0';
		char outChar = ((val / 2) + (rem ? 5 : 0)) + '0';
		if (outChar != '0' || out.length() > 0)
			out += outChar;
		rem = val % 2;
	}

	return out;
}

int powerTwo(string a) {
	int len = a.length();
	int k = 0;
	int lastDigit = a[len - 1] - '0';
	while (lastDigit != 0 && lastDigit % 2 == 0) {
		a = divideByTwo(a);
		len = a.length();
		lastDigit = a[len - 1] - '0';
		k++;
	}

	if (k > 0 && len == 1 && lastDigit == 1)
		return 1;
	else
		return 0;
}

int main_intBit30() {
	
	cout << powerTwo("147573952589676412928");
	return 0;
}