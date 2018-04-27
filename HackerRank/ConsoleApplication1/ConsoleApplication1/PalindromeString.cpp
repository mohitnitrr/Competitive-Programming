#include "bits_stdc.h"


int isPalindrome(string str) {

	int l = 0;
	int h = str.length()-1;

	while (l < h) {
		while (!isalnum(str[l]))
			l++;
		while (!isalnum(str[h]))
			h--;
		if (l < h && tolower(str[l]) != tolower(str[h])) {
			return 0;
		}
		l++;
		h--;
	}
	return 1;
}

int main_intBit26() {

	cout << isPalindrome("race a car");

	return 0;
}