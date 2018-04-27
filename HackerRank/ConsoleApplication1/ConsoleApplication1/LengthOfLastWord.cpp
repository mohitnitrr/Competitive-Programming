#include "bits_stdc.h"

int lengthOfLastWord(string str) {

	int i = str.length() - 1;

	while (i>=0 && !isalnum(str[i]))
		i--;

	int lastIndex = i;

	while (i >= 0 && isalnum(str[i]))
		i--;

	return lastIndex - i;
}

int main_intBit32() {

	cout << lengthOfLastWord("Hello World");

	return 0;
}