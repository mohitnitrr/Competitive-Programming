#include "bits_stdc.h"

string longestCommonPrefix(const vector<string>& inStrings) {

	int minLength = INT_MAX;
	string minLengthStr;
	for (const string & nextStr: inStrings) {
		int length = nextStr.length();
		if (minLength > length) {
			minLength = length;
			minLengthStr = nextStr;
		}
	}

	string outputStr = "";
	for (int i = 0; i < minLength; i++) {
		for (int j = 0; j < inStrings.size(); j++) {
			if (inStrings[j][i] != minLengthStr[i])
				return outputStr;				
		}
		outputStr += minLengthStr[i];
	}

	return outputStr;
}


int main_intBit27() {
	vector<string> arr = { "abcdefgh",

		"aefghijk",

		"abcefgh" };

	cout << longestCommonPrefix(arr);

	return 0;

}