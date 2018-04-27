#include "bits_stdc.h"

bool isSafe(int x, int y, int row, int col){

	if (x >= 0 && x < col && y >= 0 && y < row)
		return true;

	return false;
}

string solve(int col, int row, int C, int D, vector<int> E, vector<int> F) {

	vector<vector<int>> mat(row, vector<int>(col, 1));
	vector<vector<bool>> visited(row, vector<bool>(col, false));

	//moves
	int moveX[8]  = { 1, 1, 1, 0, -1, -1, -1, 0 };
	int moveY[8] =  { 1, 0, -1, -1, -1, 0, 1, 1 };

	for (int i = 0; i< C; i++) {
		int c1 = E[i] -1;
		int r1 = F[i] -1;
		for (int j = 0; j <= D; j++) {
			for (int k = 0; k < 8; k++) {
				int blockX = c1 + j*moveX[k];
				int blockY = r1 + j*moveY[k];
				if (isSafe(blockX, blockY, row, col))
					mat[blockY][blockX] = 0;
			}
		}
	}

	queue<pair<int, int>> q;
	vector<vector<int> > out;
	if (mat[0][0] == 1)
		q.push({ 0,0 });
	else
		return "NO";
	while (!q.empty())
	{
		vector<int> nextlevel;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			pair<int, int> front = q.front();
			q.pop();
			if (front.first == row - 1 && front.second == col - 1)
				return "YES";
			else {			
				for (int k = 0; k < 8; k++) {
					int blockX = front.second + moveX[k];
					int blockY = front.first + moveY[k];
					if (isSafe(blockX, blockY, row, col) && !visited[blockY][blockX]) {
						q.push({ blockY, blockX });
					}				
				}

				visited[front.first][front.second] = true;
			}
		}
	}

	return "NO";
}

int main_int40() {

	cout << solve(2, 3, 1, 1, { 2 }, { 3 });
	return 0;
}