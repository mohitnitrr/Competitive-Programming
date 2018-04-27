#include "bits_stdc.h"

vector<int> solve(int A, int B, int C, int D) {

	priority_queue<int, vector<int>, greater<int>> in;
	vector<int> out;
	set<int> dup;
	int count = 0;
	in.push(A);
	dup.insert(A);

	if (dup.find(B) == dup.end()) {
		in.push(B);
		dup.insert(B);
	}
	if (dup.find(C) == dup.end()) {
		in.push(C);
		dup.insert(C);
	}


	while (!in.empty() && count < D) {
		int next = in.top();
		in.pop();
		if (dup.find(next*A) == dup.end()) {
			in.push(next*A);
			dup.insert(next*A);
		}
		
		if (dup.find(next*B) == dup.end()) {
			in.push(next*B);
			dup.insert(next*B);
		}
		if (dup.find(next*C) == dup.end()) {
			in.push(next*C);
			dup.insert(next*C);
		}

		out.push_back(next);
		count++;
	}


	return out;
}


int main_int35() {

	vector<int> out = solve(2, 5, 11, 5);

	for (auto i : out) {
		cout << i << " ";
	}

	return 0;
}
