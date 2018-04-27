#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

int getWordsCount(string str) {
	int wordCount = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if(isupper(str.at(i))){
			wordCount++;
		}
	}

	return wordCount + 1;
}

int main4() {
	string str;
	cin >> str;
	cout << getWordsCount(str);

	return 0;
}