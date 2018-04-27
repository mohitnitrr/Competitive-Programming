#include "bits_stdc.h"

int arrangeUtil(vector<int> &A, vector<bool> &recur, vector<bool> &visited, int i) {

	int temp = A[i];
	recur[i] = true;
	if (recur[A[i]])
		A[i] = A[A[i]];
	else {
		A[i] = arrangeUtil(A, recur, visited, A[i]);
	}

	visited[i] = true;
	recur[i] = false;
	return temp;
}

void arrange(vector<int> &A) {
	int n = A.size();
	vector<bool> recur(n, false);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			arrangeUtil(A, recur, visited, i);
	}
}

int main_int62() {

	vector<int> in = { 4,5,3,2,1,0 };
	arrange(in);

	for (auto i : in)
		cout << i << " ";

	cout << endl;

	return 0;
}