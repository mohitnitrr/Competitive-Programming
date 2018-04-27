#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <ctype.h>

using namespace std;

int main10() {
	map<char, unsigned int> charCount;
	string s;
	cin >> s;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (charCount.find(s[i]) == charCount.end()) {
			charCount[s[i]] = 1;
		}
		else {
			charCount[s[i]] = charCount[s[i]] + 1;
		}
	}

	set<unsigned int> possibleWeight;

	map<char, unsigned int>::iterator itr = charCount.begin();
	map<char, unsigned int>::iterator end = charCount.end();

	while (itr != end) {
		char c = itr->first;
		int count = itr->second;
		for (long j = 1; j <= count; j++) {
			possibleWeight.insert(j*(c - 'a' + 1));
		}
		itr++;
	}

	unsigned int queries;
	cin >> queries;
	int weight = 0;
	while (queries-- != 0) {
		cin >> weight;
		if (possibleWeight.find(weight) != possibleWeight.end())
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	}

	return 0;
}