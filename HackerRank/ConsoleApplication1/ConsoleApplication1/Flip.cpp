#include "bits_stdc.h"

vector<int> flip(string A) {
	
	vector<int> out;
	int n = A.size();

	int start= -1, end =-1;
	int curStart = -1, curEnd = -1;
	int sum = 0, curSum = 0;
	for (int i = 0; i < n; i++) {
		curSum += A[i] == '1' ? -1 : 1;
		if (curSum <= 0) {
			curStart = curEnd = -1;
			curSum = 0;
		}
		else {
			if (curStart == -1)
				curStart = i;
			if (start == -1)
				start = end = i;
			if (curSum > sum) {
				start = curStart;
				sum = curSum;
				end = i;
			}
		}
	}

	if (start >= 0) {
		out.push_back(start + 1);
		out.push_back(end + 1);
	}
	return out;
}


int main_int57() {

	vector<int> out = flip("0111000100010");;
	cout << out[0] << out[1];
	return 0;
}