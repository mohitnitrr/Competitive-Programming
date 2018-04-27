#include "bits_stdc.h"

vector<int> getSpiral(vector<vector<int>> mat) {
	int row = mat.size();
	int col = mat[0].size();

	int startRow=0; 
	int startCol = 0;
	int endRow = row-1;
	int endCol = col-1;
	
	vector<int> spriralOrder;

	while (startRow <= endRow && startCol <= endCol) {
		//print first row 
		for (int i = startCol; i <= endCol; i++) {
			spriralOrder.push_back(mat[startRow][i]);
		}
		startRow++;

		//print last col 
		for (int i = startRow; i <= endRow; i++) {
			spriralOrder.push_back(mat[i][endCol]);
		}
		endCol--;

		//print last row
		if (startRow <= endRow) {
			for (int i = endCol; i >= startCol; i--) {
				spriralOrder.push_back(mat[endRow][i]);
			}
			endRow--;
		}
		//print first col
		if (startCol <= endCol) {
			for (int i = endRow; i >= startRow; i--) {
				spriralOrder.push_back(mat[i][startCol]);
			}
			startCol++;
		}
	}
	
	return spriralOrder;
}

int main_inbit() {
	vector<vector<int>> test = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> returnVal = getSpiral(test);
	for (int x : returnVal) {
		cout << x << " ";
	}
	return 0;
}