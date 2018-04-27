#include "bits_stdc.h"

vector<int> intersect(vector<int> a, vector<int>b) {
	int n1 = a.size();
	int n2 = b.size();

	int i = 0;
	int j = 0;
	vector<int> out;
	while (i < n1 && j < n2) {
		
		if (a[i] == b[j]) {
			out.push_back(a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}

	return out;
}

int main_intBit46() {
	vector<int> out = intersect({ 1, 2, 3, 3, 4, 5, 6 }, { 3, 3, 5 });
	for (auto next : out) {
		cout << next << "\t";
	}
	return 0;
}