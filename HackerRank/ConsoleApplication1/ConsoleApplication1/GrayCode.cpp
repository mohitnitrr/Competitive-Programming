#include "bits_stdc.h"

vector<int> grayCode(int A) {
	vector<int> out;
	if (A <= 0)
		return out;
	
	vector<string> outStr;
	outStr.push_back("0");
	outStr.push_back("1");

	for (int i = 2; i <= A; i++) {
		int size = outStr.size();

		for (int j = size - 1; j >= 0; j--) {
			outStr.push_back(outStr[j]);
		}

		for (int j = 0; j < size; j++) {
			outStr[j] = "0" + outStr[j];
		}

		for (int j = size; j < outStr.size(); j++) {
			outStr[j] = "1" + outStr[j];
		}

	}

	for (string str : outStr) {
		out.push_back(stoi(str, nullptr, 2));
	}

	return out;
}

int main_int100() {

	vector<int>out =  grayCode(2);
	for (auto i : out) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}