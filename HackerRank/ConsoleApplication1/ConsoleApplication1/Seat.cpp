#include "bits_stdc.h"

int seats(string A) {

	int const mod = 10000003;
	vector<int> indices;
	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 'x') {
			indices.push_back(i);
		}
	}
	int countMove = 0;
	int n = indices.size();
	for (int i = 1; i < indices.size(); i++) {
		countMove += ((indices[i] - indices[i - 1] -1)*max(min(i, n - 1 - i),1));
		countMove = countMove%mod;
	}

	return countMove;
}
int main_int20() {

	cout << seats(".x.x.x..x");

	return 0;
}