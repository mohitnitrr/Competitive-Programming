#include "bits_stdc.h"

struct UberRide {
	long long time;
	long long round;
};

/*void minimum(vector<long long>&input, vector<long long>&count) {
	long long index = -1;
	long long min = LONG_MAX;
	for (long long i = 0; i < input.size(); i++) {
		if (input[i] * (count[i] + 1) < min) {
			min = input[i] * (count[i] + 1);
			index = i;
		}
	}

	count[index]++;
}

void maximum(vector<long long>&input, vector<long long>&count) {
	long long max = LONG_MIN;
	for (long long i = 0; i < input.size(); i++) {
		if (input[i] * count[i] > max) {
			max = input[i] * count[i];
		}
	}

	cout << max;
}*/

void maximum(vector<UberRide>& input) {
	long long max = LONG_MIN;
	for (long long i = 0; i < input.size(); i++) {
		if (input[i].time * input[i].round > max) {
			max = input[i].time * input[i].round;
		}
	}

	cout << max;
}



bool CompareUberRide(UberRide u1, UberRide u2)
{
	return (u1.time *(u1.round + 1) < u2.time *(u2.round + 1));
}


int main() {
	long long n;
	long long k;

	vector<UberRide> input;
	cin >> n;
	cin >> k;

	while (k-- > 0) {
		UberRide uberRide;
		cin >> uberRide.time;
		uberRide.round = 0;
		input.push_back(uberRide);
	}
	
	std::make_heap(input.begin(), input.end(), CompareUberRide);

	while (n-- > 0) {
		UberRide uberRide = input.front();
		std::pop_heap(input.begin(), input.end());
		uberRide.round++;
		input.push_back(uberRide);
		std::push_heap(input.begin(), input.end());
	}

	maximum(input);

	return 0;
}