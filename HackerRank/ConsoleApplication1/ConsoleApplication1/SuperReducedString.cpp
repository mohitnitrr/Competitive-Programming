#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
namespace MyNamespace
{

	string superReducedString(string str) {

		string output;
		bool reqRecalculate = true;

		while (reqRecalculate && !str.empty())
		{
			reqRecalculate = false;
			output.clear();

			for (size_t i = 0; i < str.length();)
			{
				size_t j = i + 1;
				int count = 1;
				while ((j < str.length()) && (str.at(j) == str.at(i))) {
					reqRecalculate = true;
					j++;
					count++;
				}
				if (count % 2 != 0) {
					output.append(str, i, 1);
				}
				i = j;
			}
			str = output;
		}

		return output;
	}

	int main5() {
		string str;
		cin >> str;
		string out = superReducedString(str);
		if (out.empty())
			cout << "Empty String";
		else
			cout << out;

		return 0;
	}
}