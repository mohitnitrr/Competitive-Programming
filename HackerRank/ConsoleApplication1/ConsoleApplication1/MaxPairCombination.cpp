#include "bits_stdc.h"



/*
vector<int> solve(vector<int> &A, vector<int> &B) {

	int n = A.size();
	vector<int> out;
	int count = 0;
	Heap outHeap;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = A[i] + B[j];
			if (count < n)
				out.push_back(sum);
			else {
				if (outHeap.top() < sum)
					outHeap.insertAtTop(sum);
			}
			count++;
			if (count == n)
				outHeap.constructHeap(out);
		}
	}
	out.clear();
	out.resize(n);
	for (int i = n-1; i >= 0; i--) {
		out[i] = outHeap.top();
		outHeap.pop();
	}

	return out;
}

int main() {
	vector<int> h1{1 };
	vector<int> h2{ 1 };

	vector<int> out  = solve(h1, h2);

	for (auto i : out) {
		cout << i << " ";
	}

	cout << "\n";

	return 0;
}
*/