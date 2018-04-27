#include "bits_stdc.h"

int getColumnNumber(string colTitle) {

	int colNum = 0;
	int base = 26;
	int j = 0;
	for (int i = colTitle.length() - 1; i >=0; i--) {
		colNum += (colTitle[i] - 'A' + 1)*(pow(base, j++));
	}

	return colNum;
}

string getColumnTitle(int num) {
	string colTitle;
	int base = 26;
	while (num > 0) {
		int rem = num%base;
		if (rem == 0) {
			colTitle += 'Z';
			num = num / base - 1;
		}
		else {
			colTitle += rem - 1 + 'A';
			num = num / base;
		}
	}
	reverse(colTitle.begin(), colTitle.end());

	return colTitle;
}

int main_intBit18() {

	cout << getColumnNumber("BAQUZ");
	//cout << "\n";
	cout << getColumnTitle(943566);

	return 0;
}