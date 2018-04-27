#include "bits_stdc.h"

int maximumGapij(const vector<int> &A) {

	int maxDis = -1;
	map<int, pair<int, int>> bucket;
	for (int i = 0; i < A.size(); i++) {
		if (bucket.find(A[i]) == bucket.end())
			bucket[A[i]] = make_pair(i,i);
		else {
			bucket[A[i]].second = i;
		}
	}

	map<int, pair<int, int>>::iterator itr = bucket.begin();
	map<int, pair<int, int>>::iterator end = bucket.end();

	while (itr != end) {
		maxDis = max(maxDis, itr->second.second - itr->second.first);
		map<int, pair<int, int>>::iterator next = itr;
		next++;
		if (next == end)
			break;
		while (next != end)
		{
			maxDis = max(maxDis, next->second.second - itr->second.first);
			next++;
		}

		itr++;
	}
	return maxDis;
}

int maximumGapApp2(const vector<int> &A) {
	int n = A.size();
	vector<int> minimum(n);
	vector<int> maximum(n);

	minimum[0] = A[0];
	for (int i = 1; i < n; i++) {
		minimum[i] = min(minimum[i - 1], A[i]);
	}

	maximum[n - 1] = A[n - 1];
	for (int i = n-2; i >= 0; i--) {
		maximum[i] = max(maximum[i+1], A[i]);
	}

	int i = 0, j = 0, maxDis = 0;
	while (i < n && j < n) {
		if (maximum[j] >= minimum[i]) {
			maxDis = max(maxDis, j - i);
			j++;
		}
		else
			i++;
	}

	return maxDis;
}

/*int main() {
	vector<int> in = { 1,1,1,1 };
	cout << maximumGapij(in);
	return 0;
}*/