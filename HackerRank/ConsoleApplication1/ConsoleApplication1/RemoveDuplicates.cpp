#include "bits_stdc.h"

int removeDuplicate(vector<int> &a) {


	for (int i = 0; i < a.size(); i++) {
		int j = i+1;
		while (j < a.size() && a[i] == a[j]) {
			j++;
		}
		if (j > i+1) {
			a.erase(a.begin()+ i + 1, a.begin() + j);
		}
	}

	return a.size();
}


int removeDuplicate2(vector<int> &a) {


	for (int i = 0; i < a.size(); i++) {
		int j = i + 1;
		while (j < a.size() && a[i] == a[j]) {
			j++;
		}
		if (j > i + 2) {
			a.erase(a.begin() + i + 2, a.begin() + j);
		}
	}

	return a.size();
}

int removeFromArray(vector<int> &a, int val) {

	vector<int>::iterator itr = a.begin();
	while (itr != a.end()) {
		if (*itr == val) {
			itr = a.erase(itr);
		}
		else
			++itr;
	}

	return a.size();
}

int main_intBit48() {

	vector<int> out = { 1,1,1,2 };
	removeFromArray(out,1);
	for (auto next : out) {
		cout << next << "\t";
	}

	return 0;
}