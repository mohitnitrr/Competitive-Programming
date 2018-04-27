#include "bits_stdc.h"


vector<string> fizzBuzz(int A) {

	vector<string> out;
	for (int i = 1; i <= A; i++) {
		if (i % 3 == 0 && i % 5 == 0)
			out.push_back("FizzBuzz");
		else if (i % 5 == 0)
			out.push_back("Buzz");
		else if (i % 3 == 0)
			out.push_back("Fizz");
		else
			out.push_back(to_string(i));

	}

	return out;
}

int main_int63() {

	vector<string> out = fizzBuzz(10);
	for (auto i : out) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
