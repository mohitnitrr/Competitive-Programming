#include "bits_stdc.h"

int sumOfFibonacciNumbers(int A) {


	if (A == 1)
		return 1;

	vector<int> minFib(A + 1, INT_MAX);
	int first = 1;
	int second = 2;
	int next = 2;

	minFib[1] = 1;
	while (next < A) {
		if (A == next)
			return 1;

		minFib[next] = 1;
		next = first + second;
		first = second;
		second = next;
	}

	while (true) {
		int size = minFib.size();
		for (int i = 1; i < size && minFib[i]; i++) {
			for (int j = i; j < size && minFib[j]; j++) {
				int nextNum = i+j;
				if (nextNum == A)
					return minFib[i] + minFib[j];
				else if(nextNum < A){
					minFib[nextNum] = min(minFib[nextNum], minFib[i] + minFib[j]);
				}
			}
		}
	}

	return -1;
}


/*int main() {

	cout << sumOfFibonacciNumbers(33);

	return 0;
}*/