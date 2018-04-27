#include "bits_stdc.h"

vector<vector<int>> getSpiral(const int& number) {
	int row = number;
	int col = number;

	int startRow = 0;
	int startCol = 0;
	int endRow = row - 1;
	int endCol = col - 1;

	int count = 1;

	vector<vector<int> > matrix(row);
	for (int i = 0; i < row; i++)
		matrix[i].resize(col);

	while (startRow <= endRow && startCol <= endCol) {
		//print first row 
		for (int i = startCol; i <= endCol; i++) {
			matrix[startRow][i] = count++;
		}
		startRow++;

		//print last col 
		for (int i = startRow; i <= endRow; i++) {
			matrix[i][endCol] = count++;
		}
		endCol--;

		//print last row
		if (startRow <= endRow) {
			for (int i = endCol; i >= startCol; i--) {
				matrix[endRow][i] = count++;
			}
			endRow--;
		}
		//print first col
		if (startCol <= endCol) {
			for (int i = endRow; i >= startRow; i--) {
				matrix[i][startCol] = count++;
			}
			startCol++;
		}
	}

	return matrix;
}

int main_intBit2() {
	
	vector<vector<int>> returnVal = getSpiral(4);
	for (vector<int> &x : returnVal) {
		for (int &y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}