#include"bits_stdc.h"

int maxWaterTrap(vector<int> arr) {
	
	int n = arr.size();
	vector<int>leftToRight(n,0);
	vector<int>rightToLeft(n,0);

	leftToRight[0] = 0;
	for (int i = 1; i < n; i++) {
		leftToRight[i] = max(leftToRight[i-1] , arr[i - 1]);
	}

	rightToLeft[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		rightToLeft[i] = max(rightToLeft[i + 1] , arr[i + 1]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (min(leftToRight[i], rightToLeft[i])-arr[i]) > 0 ? min(leftToRight[i], rightToLeft[i]) - arr[i]: 0;
	}

	return sum;
}


int main_intBit63() {

	cout<<maxWaterTrap({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	return 0;
}