#include "bits_stdc.h"

int romanToInt(string str) {

	map<char, int> symVal;
	symVal['I'] = 1;
	symVal['V'] = 5;
	symVal['X'] = 10;
	symVal['L'] = 50;
	symVal['C'] = 100;
	symVal['D'] = 500;
	symVal['M'] = 1000;

	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1 && symVal[str[i]] < symVal[str[i + 1]]) {
			sum -= symVal[str[i]];
		}
		else {
			sum += symVal[str[i]];
		}
	}

	return sum;
}


int main_intBit31()
{
	cout << romanToInt("MCMIV");
	return 0;
}