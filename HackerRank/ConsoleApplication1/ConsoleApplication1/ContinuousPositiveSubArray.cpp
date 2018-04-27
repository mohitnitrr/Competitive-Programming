#include "bits_stdc.h"

vector<int> getPositiveSubArray(vector<int> &arr) {

	int sum = 0;
	int start = -1;
	int end = -1;

	int retStart = -1;
	int retEnd = -1;
	int retSum = 0;
	bool cont = false;
	vector<int> retVec;
	for (int i = 0; i < arr.size(); i++) {

		if (arr[i] < 0) {
			start = end = -1;
			sum = 0;
			cont = false;

		}
		else {
			if (start == -1)
				start = end = i;
			else {
				end++;
				cont = true;
			}
			sum += arr[i];

			if (retSum < sum || (cont && retSum == sum)) {
				retSum = sum;
				retStart = start;
				retEnd = end;
			}
		}
	}

	if (retStart != -1 && retStart != -1) {
		for (int j = retStart; j <= retEnd; j++) {
			retVec.push_back(arr[j]);
		}
	}
	return retVec;
}


int main_intBit5() {
	vector<int> input = { 0, 0, -1, 0 };
	vector<int> retVal = getPositiveSubArray(input);

	for (auto &y : retVal) {
		cout << y << " ";
	}
	return 0;
}