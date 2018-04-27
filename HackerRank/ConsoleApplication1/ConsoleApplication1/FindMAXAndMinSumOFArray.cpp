#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main1() {
	vector<int> arr(5);
	int min, max, sum;
	sum = 0;
	min = INT_MAX;
	max = INT_MIN;
	for (int arr_i = 0; arr_i < 5; arr_i++) {
		cin >> arr[arr_i];
		sum += arr[arr_i];
		if (arr[arr_i] < min)
			min = arr[arr_i];
		if (arr[arr_i] > max)
			max = arr[arr_i];

		cout << sum - max << " " << sum - min;
	}

	return 0;
}