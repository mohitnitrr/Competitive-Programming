#include "bits_stdc.h"


vector<int> maxone(vector<int> A, int B) {
	int start = 0, end = 0;
	int retval = 0;
	vector<int> indices, out;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0)
			indices.push_back(i);
	}

	if (indices.size() <= B) {
		start = 0;
		end = A.size() - 1;
	}
	else {
		indices.push_back(A.size());
		int n = indices.size();
		for (int i = 0; i < indices.size() - B; i++) {
			int l = i == 0 ? 0 : indices[i - 1] + 1;
			int r = indices[i + B] - 1;
			if ((r - l + 1) > retval) {
				retval = r - l + 1;
				start = l;
				end = r;
			}
		}
	}
	for (int i = start; i <= end; i++) {
		out.push_back(i);
	}
	return out;
}

/*int main() {

	vector<int> out = maxone({ 0, 1, 1, 1, }, 0);

	for (int i : out) {
		cout << i << " ";
	}
	cout << " \n ";

	return 0;
}*/