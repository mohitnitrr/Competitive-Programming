#include"bits_stdc.h"

string longestPalindrome(string str) {
	int n = str.length();
	vector<vector<bool>> palCount;

	palCount.resize(n);
	for (int i = 0; i < n; i++) {
		palCount[i].resize(n);
	}

	int rVal = INT_MIN;
	int startIndex = -1;
	int endIndex = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j)
				palCount[i][j] = true;
			else if(i + 1 == j) {
				palCount[i][j] = str[i] == str[j] ? true : false;
			}
		}
	}

	for (int i = 2; i < n; i++) {
		for (int row = 0; row < n - i; row++) {
			int col = row + i;
			palCount[row][col] = str[row] == str[col] && palCount[row + 1][col - 1] ?true: false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (palCount[i][j] && rVal < j-i+1)
			{
				rVal = j - i + 1;
				startIndex = i;
			}
		}
	}

	return str.substr(startIndex, rVal);
}

int main_intBit36() {

	cout << longestPalindrome("abacddcaba");
	return 0;
}