#include "bits_stdc.h"


bool isSafe(vector<string> &board, int row, int col) {
	
	//row check;
	for (int i = 0; i < board[0].size(); i++) {
		if (board[row][i] == 'Q') {
			return false;
		}
	}

	//col check
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] == 'Q') {
			return false;
		}
	}

	// diagonal check;
	for (int i = row, j = col; i >= 0 && j >= 0; j--, i--) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}

	// diagonal check;
	for (int i = row, j = col; i < board.size() && j < board[0].size(); j++, i++) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}

	// diagonal check;
	for (int i = row, j = col; i >= 0 && j < board[0].size(); j++, i--) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}

	for (int i = row, j = col; i < board.size() && j >=0; j--, i++) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}

	return true;
}

bool NQueenSolUtil(vector<string> &board, int col, vector<vector<string>> &out) {
	if (col >= board[0].size())
		out.push_back(board);
	else {
		for (int i = 0; i < board.size(); i++) {
			if (isSafe(board, i, col)) {
				board[i][col] = 'Q';
				NQueenSolUtil(board, col + 1, out);
				board[i][col] = '.';
			}
		}
	}

	return false;
}

void resetBoard(vector<string> &board, int n) {
	board.clear();
	for (int i = 0; i < n; i++) {
		string str(n, '.');
		board.push_back(str);
	}
}
vector<vector<string>> NQueenSol(int n) {
	vector<vector<string>> out;

	vector<string> board;
	resetBoard(board, n);
	
	NQueenSolUtil(board, 0, out);

	/*if (out.size() == 0){
		cout << "Solution not possible";
	}*/

	return out;
}


int main_intBit78() {

	//print2dVector(NQueenSol(4));
	return 0;
}