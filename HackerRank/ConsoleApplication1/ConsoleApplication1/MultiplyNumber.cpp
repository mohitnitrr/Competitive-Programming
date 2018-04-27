#include "bits_stdc.h"

string multiplyUtil(string str, int n) {

	if (n == 0)
		return "0";

	int carry = 0;
	string out;
	for (int i = str.length()-1; i >= 0; i--) {
		int val = (str[i] - '0') * n + carry;
		int dig = val % 10;
		carry = val / 10;
		out += dig + '0';
	}

	if (carry > 0)
		out += carry + '0';

	reverse(out.begin(), out.end());
	return out;
}

string addUtil(string str, string b) {

	reverse(str.begin(), str.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	string out;
	int i = 0, j = 0;

	while (i < str.length() || j < b.length()) {
		int firstDig = 0;
		int secDig = 0;
		if (i < str.length())
			firstDig = str[i] - '0';
		if (j < b.length())
			secDig = b[j] - '0';

		int val =  firstDig+ secDig + carry;
		int dig = val % 10;
		carry = val / 10;
		out += dig + '0';

		i++; j++;
	}

	if (carry > 0)
		out += carry + '0';
	reverse(out.begin(), out.end());

	return out;
}

string multiply(string A, string B) {

	string out;
	for (int j =0,i = B.length() - 1; i >= 0; i--, j++) {
		string tenMultiple(j, '0');
		string temp = multiplyUtil(A, B[i] - '0');
		out = addUtil(out, temp + tenMultiple);
	}

	int i = 0;
	if (out.size() > 1) {
		while (out[i] == '0') {
			i++;
		}
	}
	return out.substr(i, out.length() -i);
}

int main_int73() {

	cout << multiply("01", "0");
	return 0;
}