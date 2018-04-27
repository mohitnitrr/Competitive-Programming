#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string removeAllInstance(string str, char c) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c) {
			str.erase(str.begin() + i);
			i--;
		}
	}

	return str;
}


string reducedString(string str) {

	bool reqRecalculate = true;
	while (reqRecalculate && !str.empty())
	{
		reqRecalculate = false;
		for (size_t i = 0; i < str.length(); i++)
		{
			size_t j = i + 1;
			if ((j < str.length()) && (str.at(j) == str.at(i))) {
				reqRecalculate = true;
				str = removeAllInstance(str, str.at(i));
				break;
			}
		}
	}
	return str;
}

int main5() {
	string str;
	cin >> str;
	string out = reducedString(str);
	if (out.empty())
		cout << "Empty String";
	else
		cout << out;

	return 0;
}