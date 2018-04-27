#include "bits_stdc.h"

bool isOnEdge(int m, int n, int r, int c) {

	int moveRow[4] = { -1, 0, 1, 0 };
	int moveCol[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int nr = m + moveRow[i];
		int nc = n + moveCol[i];
		if (nr < 0 || nc < 0 || nr >= r || nc >= c)
			return true;
	}

	return false;
}

bool canCapture(int m, int n, int r, int c, vector<vector<bool> > &recur, vector<vector<char> > &A) {
	int moveRow[4] = { -1, 0, 1, 0 };
	int moveCol[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int nr = m + moveRow[i];
		int nc = n + moveCol[i];
		if (A[nr][nc] != 'X' && !recur[nr][nc])
			return false;
	}

	return true;
}

bool solveUtil(int i, int j, int r, int c, vector<vector<bool> > &recur, vector<vector<char> > &A, vector<vector<bool> > &visited) {

	if (isOnEdge(i, j, r, c))
		return false;

	bool retVal = true;
	recur[i][j] = true;
	int moveRow[4] = { -1, 0, 1, 0 };
	int moveCol[4] = { 0, 1, 0, -1 };
	for (int m = 0; m < 4; m++) {
		int nr = i + moveRow[m];
		int nc = j + moveCol[m];
		if (A[nr][nc] == 'O') {
			if (visited[nr][nc]) {
				retVal = false;
				break;
			}
			else if (!recur[nr][nc]) {
				retVal = retVal && solveUtil(nr, nc, r, c, recur, A, visited);
			}
		}	
	}
	recur[i][j] = false;

	if (retVal) {
		A[i][j] = 'X';
	}

	visited[i][j] = true;

	return retVal;
}

void solve(vector<vector<char> > &A) {
	
	int r = A.size();
	int c = A[0].size();
	vector<vector<bool> > recur(r, vector<bool>(c, false));
	vector<vector<bool>> visited(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			
			if (!visited[i][j] && A[i][j] == 'O' && solveUtil(i, j, r, c, recur, A, visited)) {
				A[i][j] = 'X';
			}

			visited[i][j] = true;
		}
	}
}


int main_int41() {
	vector<vector<char>>input = { {'X','O','O','O','O','O','O','X'}, {'X','X','O','O','X','O','O','X'}, {'O','X','X','O','X','O','X','X'} };
	solve(input);

	for (auto vec : input) {
		for (char c : vec) {
			cout << c;
		}
		cout << endl;
	}

	return 0;
}