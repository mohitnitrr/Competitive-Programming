#include "bits_stdc.h"

vector<int> LargestContSequenceSumZero(vector<int> &A) {
	
	unordered_map<int, int> sumAtIndex;
	int sum = 0;
	int minIndex = 0;
	int maxIndex = 0;
	int diff = INT_MIN;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		if (sum == 0 && diff < i+1) {
			minIndex = 0;
			maxIndex = i;
			diff = i + 1;
		}

		if (sumAtIndex.find(sum) != sumAtIndex.end()) {
			if (diff < (i - sumAtIndex[sum])) {
				minIndex = sumAtIndex[sum]+1;
				maxIndex = i;
				diff = i - sumAtIndex[sum];
			}			
		}
		else {
			sumAtIndex[sum] = i;
		}
	}

	vector<int> out;
	if (diff > 0) {
		out.resize(diff);
		copy(A.begin() + minIndex, A.begin() + maxIndex + 1, out.begin());
	}

	return out;
}



int main_int80() {
	vector<int> in = { -19, 8, 2, -8, 19, 5, -2, -23 };
	//print1D_(LargestContSequenceSumZero(in));
	return 0;
}