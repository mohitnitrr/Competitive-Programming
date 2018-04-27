#include "bits_stdc.h"

vector<vector<int>> prettyPrint(const int& number) {
	int row = number*2 -1;
	int col = number*2 -1;

	int startRow = 0;
	int startCol = 0;
	int endRow = row - 1;
	int endCol = col - 1;

	int count = number;

	vector<vector<int> > matrix(row);
	for (int i = 0; i < row; i++)
		matrix[i].resize(col);

	while (startRow <= endRow && startCol <= endCol) {
		//print first row 
		for (int i = startCol; i <= endCol; i++) {
			matrix[startRow][i] = count;
		}
		startRow++;

		//print last col 
		for (int i = startRow; i <= endRow; i++) {
			matrix[i][endCol] = count;
		}
		endCol--;

		//print last row
		if (startRow <= endRow) {
			for (int i = endCol; i >= startCol; i--) {
				matrix[endRow][i] = count;
			}
			endRow--;
		}
		//print first col
		if (startCol <= endCol) {
			for (int i = endRow; i >= startRow; i--) {
				matrix[i][startCol] = count;
			}
			startCol++;
		}

		count--;
	}

	return matrix;
}

int main_intBit20() {

	vector<vector<int>> returnVal = prettyPrint(7);
	for (vector<int> &x : returnVal) {
		for (int &y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}