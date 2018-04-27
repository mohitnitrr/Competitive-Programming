#include "bits_stdc.h"

struct Uber {
	long long start;
	long long end;
};

bool compareUber(Uber u1, Uber u2)
{
	return (u1.start < u2.start);
}

int ___testmain() {
	long long count;
	cin >> count;
	vector<Uber> input;
	while (count-- > 0) {
		Uber uber;
		cin >> uber.start;
		cin >> uber.end;
		input.push_back(uber);
	}

	sort(input.begin(), input.end(), compareUber);

	stack<Uber> seperateUbers;

	seperateUbers.push(input[0]);

	for (long long i = 1; i < input.size(); i++)
	{
		Uber top = seperateUbers.top();

		if (top.end < input[i].start)
			seperateUbers.push(input[i]);

		else if (top.end < input[i].end)
		{
			top.end = input[i].end;
			seperateUbers.pop();
			seperateUbers.push(top);
		}

	}

	long long output = 0;
	while (!seperateUbers.empty()) {
		Uber top = seperateUbers.top();
		seperateUbers.pop();
		output += top.end - top.start + 1;
	}

	cout<<output;

	return 0;
}