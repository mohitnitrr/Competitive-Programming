#include "bits_stdc.h"

long long Catalan(int n, int k) {

	const int mod = 1000000007;
	if (k > n - k)
		k = n - k;

	long long res = 1;
	for (int i = 0; i < k; i++) {
		res *= n - i;
		res /= i + 1;
		//res = res % mod;
	}

	return res;
}

int chordCnt(int A) {

	long long res = Catalan(2 * A, A);
	res = res / (A + 1);
	cout <<res;

	return (int)res;
}

//int main() {
//	chordCnt(17);

//	return 0;
//}