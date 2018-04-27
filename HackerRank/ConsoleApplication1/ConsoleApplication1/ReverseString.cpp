#include "bits_stdc.h"

void reverseWord(string &str, int startIndex, int endIndex) {

	while (startIndex < endIndex) {
		char temp = str[startIndex];
		str[startIndex] = str[endIndex];
		str[endIndex] = temp;
		startIndex++;
		endIndex--;
	}

	return;
}

void reverseString(string &str) {
	
	int startIndex = 0;
	for (int i = 0; i < str.length();i++) {
		bool wordFound = false;
		while (i < str.length() && isalnum(str[i])) {
			if (!wordFound) {
				wordFound = true;
				startIndex = i;
			}
			i++;
		}
		if (wordFound) {
			reverseWord(str, startIndex, i - 1);
			wordFound = false;
		}
	}
	reverseWord(str, 0, str.length() - 1);
}

void reverseStringWord(string &str) {

	int startIndex = 0;
	for (int i = 0; i < str.length(); i++) {
		bool wordFound = false;
		while (i < str.length() && isalnum(str[i])) {
			if (!wordFound) {
				wordFound = true;
				startIndex = i;
			}
			i++;
		}
		if (wordFound) {
			reverseWord(str, startIndex, i - 1);
			wordFound = false;
		}
	}

}

int main_intBit33() {

	string str = "fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
	reverseString(str);
	cout << str;
	return 0;
}