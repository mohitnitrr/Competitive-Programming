#include "stdafx.h" 

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

int main6() {
	string str;
	size_t len;
	int rot;
	cin >> len >> str >> rot; 
	rot = rot % 26;
	string output;
	const char* strChar = str.c_str();
	for (size_t i = 0; i < len; i++)
	{
		char nextChar = strChar[i];
		if (strChar[i]>=97 && strChar[i] <= 122) {
			if ((nextChar + rot) > 122) {
				char diff = nextChar + rot - 122;
				if(diff > 0 )
					nextChar = 97 + diff - 1;
				else {
					nextChar = 97 - diff - 1;
				}
			}
			else {
				nextChar = nextChar + rot;
			}
			output += nextChar;
		}
		else if (strChar[i] >= 65 && strChar[i] <= 90) {
			nextChar = nextChar + rot;
			if (nextChar > 90) {
				char diff = nextChar - 90;
				nextChar = 65 + diff - 1;
			}
			output += nextChar;
		}
		else {
			output += strChar[i];
		}
	}

	cout << output;

	return 0;
}