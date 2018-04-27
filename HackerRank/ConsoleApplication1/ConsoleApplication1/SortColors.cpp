#include "bits_stdc.h"

void sortColors(vector<int> &A) {

	int colorCount[3] = {0,0,0};
	for (int i = 0; i < A.size(); i++) {
		colorCount[A[i]]++;
	}
	
	for (int i = 0; i < A.size(); i++) {
		if (colorCount[0]) {
			A[i] = 0;
			colorCount[0]--;
		}

		else if (colorCount[1]) {
			A[i] = 1;
			colorCount[1]--;
		}

		else {
			A[i] = 2;
			colorCount[2]--;
		}
	}

}

int main_int83() {

	vector<int> in = { 0,1,0,2,0,1,0 };
	sortColors(in);
	for (int i : in) {
		cout << i << " ";
	}

	cout << "\n";
	return 0;
}