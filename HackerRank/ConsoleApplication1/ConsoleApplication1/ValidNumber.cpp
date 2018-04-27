#include "bits_stdc.h"

bool isDigit(char c) {

	if (c >= '0' && c <= '9')
		return true;

	return false;
}

int isNumber(const string A) {
	
	int itr = A.find_first_not_of(" ");
	int end = A.find_last_not_of(" ");

	if (A[itr] == '-')
		itr++;
	while (itr <= end && isdigit(A[itr]))
		itr++;

	if (itr > end)
		return 1;

	if (itr <= end && !(A[itr] == '.' || A[itr] == 'e'))
		return 0;

	itr++;
	if (itr > end)
		return 0;
	if (itr <= end && A[itr - 1] == 'e' && A[itr] == '-')
		itr++;

	if (itr <= end && A[itr - 1] == '.' && !isdigit(A[itr]))
		return 0;

	while (itr <= end && isdigit(A[itr]))
		itr++;

	if (itr > end)
		return 1;
	if (itr < end && A[itr] != 'e' && A[itr-2] != '.')
		return 0;
	itr++;

	if (itr <= end && A[itr] == '-')
		itr++;

	if (itr > end)
		return 0;

	while (itr <= end && isdigit(A[itr]))
		itr++;

	if (itr > end)
		return 1;

	else
		return 0;
}


/*int main() {

	cout << isNumber("1.e1");
}*/