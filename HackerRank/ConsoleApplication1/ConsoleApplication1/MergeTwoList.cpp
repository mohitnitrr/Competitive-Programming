#include "bits_stdc.h"

void merge(vector<int> &a, vector<int> b) {

	int n1 = a.size();
	int n2 = b.size();

	int i = 0;
	int j = 0;
	vector<int> out;
	while (i < n1 && j < n2) {

		if (a[i] == b[j]) {
			out.push_back(a[i]);
			out.push_back(b[j]);
			i++;
			j++;
		}
		else if (a[i] < b[j]) {
			out.push_back(a[i]);
			i++;
		}
		else {
			out.push_back(b[j]);
			j++;
		}
	}

	while (i < n1)
	{
		out.push_back(a[i]);
		i++;
	}
	while (j < n2)
	{
		out.push_back(b[j]);
		j++;
	}
	a = out;
	return;
}

int main_intBit47() {

	vector<int> out = { 1, 5, 8 };
	merge(out, { 6, 9 });
	for (auto next : out) {
		cout << next << "\t";
	}

	return 0;
}