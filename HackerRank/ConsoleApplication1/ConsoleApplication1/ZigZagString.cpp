#include "bits_stdc.h"


string convert(string A, int B) {

	if (B == 1)
		return A;

	string out;
	int len = A.length();
	int v = 2 * (B - 1);
	for (int i = 0; i < B; i++) {
		int start = i;
		int back = v - i;
		
		while (start < len) {
			out += A[start];
			if (i != 0 && i != B-1 && start != back && back < len) {
				out += A[back];
				back += v;
			}
			start += v;
		}
	}

	return out;
}

/*int main() {

	cout << convert("ABCD", 1);
	return 0;
}*/