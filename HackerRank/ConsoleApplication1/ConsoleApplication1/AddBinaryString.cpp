#include "bits_stdc.h"
int getInt(char c) {
	return c - '0';
}
char getChar(int i) {
	return i + '0';
}

string addBinaryString(string a, string b) {

	string sum = "";
	int i = a.length() - 1, j = b.length() - 1;
	int carry = 0;
	for (; i >= 0 && j >= 0; i--, j--) {
		sum += getChar(getInt(a[i]) ^ getInt(b[j]) ^ carry);
		carry = (getInt(a[i]) + getInt(b[j]) + carry) >= 2 ? 1 : 0;
	}

	while (i >= 0) {
		sum += getChar(getInt(a[i]) ^ carry);
		carry = a[i] == '1' && carry == 1 ? 1 : 0;
		i--;
	}

	while (j >= 0) {
		sum += getChar(getInt(b[j]) ^ carry);
		carry = b[j] == '1' && carry == 1 ? 1 : 0;
		j--;
	}
	if (carry)
		sum += '1';
	reverse(sum.begin(), sum.end());
	return sum;
}
int main_intBit29() {

	cout << addBinaryString("1010110111001101101000", "1000011011000000111100110");
	return 0;
}