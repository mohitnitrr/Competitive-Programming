#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

int main8() {

	const char* target = "hackerrank";
	int targetLastCharindex = strlen(target) - 1;
	int queries;
	cin >> queries;
	while (queries-- != 0) {
		int targetCharpoint = 0;
		string s;
		cin >> s;
		const char* input = s.c_str();

		for (size_t i = 0; i < strlen(input); i++)
		{
			if (input[i] == target[targetCharpoint])
				targetCharpoint++;
			
			if (targetCharpoint == targetLastCharindex)
				break;
		}

		if (targetCharpoint == targetLastCharindex)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}