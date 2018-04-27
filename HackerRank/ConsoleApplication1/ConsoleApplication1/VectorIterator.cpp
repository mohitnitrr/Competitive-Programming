#include "bits_stdc.h"

int main_() {

	vector<int> vc;
	vc.push_back(2);
	vector<int>::iterator itr = vc.begin();
	(*itr) = 4;

	return 0;
}