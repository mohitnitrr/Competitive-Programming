#include "stdafx.h" 

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

int main7() {
	string s;
	cin >> s;
	int count = 0;
	const char * str = s.c_str();
	for (size_t i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && str[i] != 'S')
			count++;
		else if (i % 3 == 1 && str[i] != 'O')
			count++;
		else if (i % 3 == 2 && str[i] != 'S')
			count++;
	}

	cout << count;

	return 0;
}