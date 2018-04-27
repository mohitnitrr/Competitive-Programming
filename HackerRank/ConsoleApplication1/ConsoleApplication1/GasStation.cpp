#include "bits_stdc.h"

int canCompleteCircuit(const vector<int> &gas, const vector<int> &distance) {

	int start = 0;
	int end = 1;
	int currPetrol = gas[0] - distance[0];

	while(start != end || currPetrol < 0){

		while (currPetrol < 0) {
			currPetrol -= gas[start] - distance[start];
			start = (start + 1) % gas.size();
			if (start == 0)
				return -1;
		}

		currPetrol += gas[end] - distance[end];
		end = (end + 1) % gas.size();
	}

	return start;
}


int main_int21() {

	vector<int> a = { 684, 57, 602, 987 };
	vector<int> b = { 909, 535, 190, 976 };
	cout << canCompleteCircuit(a, b);
	return 0;
}