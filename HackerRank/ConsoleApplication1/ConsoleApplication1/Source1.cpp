#include "bits_stdc.h"


long triplets(long t, vector <int> d) {
	
	int n = d.size();
	sort(d.begin(), d.end());
	long count = 0;
	for (int i = 0; i < n-2; i++) {
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			long curSum = d[i];
			curSum += d[j];
			curSum += d[k];
			if (curSum > t) {
				k--;
			}
			else {
				count += k - j;
				j++;
			}
		}
	}

	return count;
}

/*int main() {

	vector<int> in = { 3,1,2,4};
	cout << triplets(7, in);
	return 0;
}*/