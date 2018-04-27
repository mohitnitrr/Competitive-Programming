#include"bits_stdc.h"

int isPalindrome(int n) {

	int x=0;
	int base = 10;
	int temp = n;
	while (temp > 0) {
		int rem = temp % base;
		x = x * base + rem;
		temp = temp / base;
	}

	if (x == n)
		return 1;

	return 0;
}

int reverse(int num) {
	// Handling negative numbers
	bool negativeFlag = false;
	if (num < 0)
	{
		negativeFlag = true;
		num = -num;
	}

	int prev_rev_num = 0, rev_num = 0;
	while (num != 0)
	{
		int curr_digit = num % 10;

		rev_num = (rev_num * 10) + curr_digit;

		// checking if the reverse overflowed or not.
		// The values of (rev_num - curr_digit)/10 and
		// prev_rev_num must be same if there was no
		// problem.
		if ((rev_num - curr_digit) / 10 != prev_rev_num)
		{
			return 0;
		}

		prev_rev_num = rev_num;
		num = num / 10;
	}

	return (negativeFlag == true) ? -rev_num : rev_num;
}


int main_intBit21()
{
	//cout << isPalindrome(121) << "\n";

	cout << reverse(-1146467285);

	return 0;
}