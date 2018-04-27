#include "bits_stdc.h"

string integerToRoman(int n) {

	string out;
	while (n > 0) {
		if (n > 1000) {
			int msd = n / 1000;
			n = n % 1000;
			for (int i = 0; i < msd; i++) {
				out += 'M';
			}
		}
		else if (n > 100) {
			int msd = n / 100;
			n = n % 100;
			if (msd >= 5) {
				if (msd == 9) {
					out += "CM";
					msd = 0;
				}
				else {
					out += 'D';
					msd -= 5;
				}
			}

			if (msd == 4)
				out += "CD";
			else {
				for (int i = 0; i < msd; i++) {
					out += 'C';
				}
			}
		}
		else if (n > 10) {
			int msd = n / 10;
			n = n % 10;
			if (msd >= 5) {
				if (msd == 9) {
					out += "XC";
					msd = 0;
				}
				else {
					out += 'L';
					msd -= 5;
				}
			}

			if (msd == 4)
				out += "XL";
			else {
				for (int i = 0; i < msd; i++) {
					out += 'X';
				}
			}
		}
		else {
			int msd = n;
			n = 0;
			if (msd >= 5) {
				if (msd == 9) {
					out += "IX";
					msd = 0;
				}
				else {
					out += 'V';
					msd -= 5;
				}
			}

			if (msd == 4)
				out += "IV";
			else {
				for (int i = 0; i < msd; i++) {
					out += 'I';
				}
			}
		}
	}

	return out;
}

int main_string1() {

	cout << integerToRoman(3549);
	return 0;
}