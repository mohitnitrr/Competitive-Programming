#include "bits_stdc.h"

int minCharPalindromeString(string str) {
	
	int n = str.length();
	std::vector<std::vector<int>> charCount(n, std::vector<int>(n, 0));

	for (int i = 1; i < n; i++) {
		for (int row = 0; row < n - i; row++) {
			int col = row + i;
			charCount[row][col] = str[row] == str[col]? charCount[row + 1][col -1] : min(charCount[row+1][col], charCount[row][col-1]) +1;
		}
	}

	return charCount[0][n - 1];
}

int main_intBit37() {

	cout << minCharPalindromeString("AACECAAAA");

	return 0;
}