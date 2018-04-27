#include "bits_stdc.h"

vector<vector<int>> getPascal(const int &row ) {

	vector<vector<int>> pascalTriangle;
	pascalTriangle.resize(row);

	for (int i = 0; i < row; i++) {
		pascalTriangle[i].resize(i+1);
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				pascalTriangle[i][j] = 1;
			}
			else {
				pascalTriangle[i][j] = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j];
			}
		}
	}

	return pascalTriangle;
}


int main_bit3() {

	vector<vector<int>> returnVal = getPascal(4);
	for (vector<int> &x : returnVal) {
		for (int &y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}

	return 0;
}