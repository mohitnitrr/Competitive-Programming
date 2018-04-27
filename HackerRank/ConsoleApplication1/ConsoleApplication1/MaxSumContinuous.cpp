#include "bits_stdc.h"

int maxsum(vector<int> & arr) {
	int maxSum = arr[0];
	int currSum = 0;

	for (size_t i = 0; i < arr.size(); i++)
	{
		currSum += arr[i];
		if (currSum > maxSum)
			maxSum = currSum;
		
		if (currSum < 0)
			currSum = 0;
	}

	return maxSum;
}

int main_intBit1() {

	vector<int> sample = { -307, -316, -236, -136, -323, -370, -386 };
	cout << maxsum(sample);
	return 0;
}