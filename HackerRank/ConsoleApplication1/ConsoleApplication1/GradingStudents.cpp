#include "stdafx.h"

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

vector < int > solve(vector < int > grades) {
	for (size_t i = 0; i < grades.size(); i++) {
		if (grades[i] > 38 && grades[i]%5 > 0) {
			grades[i] = grades[i] + 5 - grades[i] % 5;
		}
	}

	return grades;
}

int main3() {
	int n;
	cin >> n;
	vector<int> grades(n);
	for (int grades_i = 0; grades_i < n; grades_i++) {
		cin >> grades[grades_i];
	}
	vector < int > result = solve(grades);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;

	return 0;
}