#include "bits_stdc.h"

int isNobleInteger(vector<int> &arr) {

	sort(arr.begin(), arr.end());
	int next = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		int j = i;
		while ((j + 1 < arr.size()) && arr[j + 1] == arr[i]) {
			j++;
		}
		if (i != j)
			i = j;
		if ((arr.size() - i - 1) == arr[i]) {
			return 1;
		}
	}

	return -1;
}

int main_intBit10() {
	vector<int> input = { 1,1,2,2,4,4 };
	cout << isNobleInteger(input);
	return 0;
}