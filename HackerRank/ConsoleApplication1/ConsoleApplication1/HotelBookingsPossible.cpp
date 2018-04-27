#include "bits_stdc.h"


bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
	sort(arrive.begin(), arrive.end());
	sort(depart.begin(), depart.end());

	int i = 0, j = 0;
	int count = 0;
	while (i < arrive.size() && j < depart.size()) {
		if (arrive[i] < depart[j]) {
			count++;
			if (count > K) {
				return false;
			}
			i++;
		}
		else {
			j++;
		}
	}

	return true;
}

