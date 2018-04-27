#include "bits_stdc.h"

bool validateRow(vector<string>board, int r, int c) {

	char val = board[r][c];
	if (val == '.')
		return true;

	for (int i = 0; i < 9; i++) {
		if (i != c && board[r][i] == val)
			return false;
	}
	return true;
}

bool validateCol(vector<string>board, int r, int c) {

	char val = board[r][c];
	if (val == '.')
		return true;

	for (int i = 0; i < 9; i++) {
		if (i != r && board[i][c] == val)
			return false;
	}
	return true;
}

bool validateSubSudoko(vector<string>board, int r, int c) {

	int row = (r / 3)*3;
	int col = (c / 3) *3;
	char val = board[r][c];
	if (val == '.')
		return true;

	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (i == r && j == c)
				continue;
			else if(board[i][j] == val)
				return false;
		}
	}

	return true;
}


int isValidSudoku(const vector<string> &A) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!validateRow(A, i, j) || !validateCol(A, i, j) || !validateSubSudoko(A, i, j))
				return 0;
		}
	}

	return 1;
}

int main_intBit81() {

	vector<string> input = { "....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......"};

	cout << isValidSudoku(input);

	return 0;
}