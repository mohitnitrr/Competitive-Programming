#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string timeConversion(string s) {

	std::string::size_type sz;   // alias of size_t
	int hr = std::stoi(s, &sz);
	string hrStr = to_string(hr);
	if (hrStr.length() == 1) {
		hrStr = "0" + hrStr;
	}
	//cout << sz;
	//cout << hr;
	int min = std::stoi(s.substr(sz + 1), &sz);
	//cout << min;
	int sec = std::stoi(s.substr(sz + 1 + sz + 1), &sz);
	//cout<<sec;

	string type = s.substr(sz + 1 + sz + 1 + sz);
	//cout << type << "\n";
	if (type == "PM" && hr != 12) {
		hr += 12;
		hrStr = to_string(hr);
	}
	else if (type == "AM" && hr == 12) {
		hrStr = "00";
	}

	string output;
	output.append(hrStr);
	output.append(s.substr(sz));
	//cout << output;

	return output.substr(0, output.length() -2);
}

int main2() {
	string s;
	cin >> s;
	string result = timeConversion(s);
	cout << result << endl;
	return 0;
}