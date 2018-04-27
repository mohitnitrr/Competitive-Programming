#include "bits_stdc.h"

int countTriangles(vector<int> sides) {

	const unsigned int M = 1000000007;
	
	sort(sides.begin(), sides.end());
	int n = sides.size();
	int count = 0;
	for (int i = n - 1; i > 1; i--) {	
		int l = 0;
		int r = i - 1;
		while (l < r) {
			if (sides[l] + sides[r] > sides[i]) {
				count = (count + (r - l)% M) % M;
				r--;
			}
			else
				l++;
		}
		
	}

	return count;
}

int main_intBit43() {

	cout << countTriangles({ 1, 1, 1, 2, 2});
	return 0;
}