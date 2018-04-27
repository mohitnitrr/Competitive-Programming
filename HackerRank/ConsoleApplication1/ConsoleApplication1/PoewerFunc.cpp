#include "bits_stdc.h"

int power(long long x, int y, int p) {

	int res = 1;      // Initialize result

	x = x % p;  // Update x if it is more than or 
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

int powerMode(int n, int p, int d) {
	//int rem =  power(n, p, d) ;
	return power(n, p, d);
	//return rem < 0 ? d + rem : rem;
}

int main_intBit49() {

	cout << powerMode(71045970, 41535484, 64735492);
	return 0;
}