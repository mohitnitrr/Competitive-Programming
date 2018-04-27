#include "bits_stdc.h"

using namespace std;

int main_1() {
	int arr[] = { 1,2,3,4 };
	unsigned int length = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < length; i+= 2)
	{
		std::swap(arr[i], arr[i + 1]);
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i];
	}

	return 0;
}