#include "bits_stdc.h"

vector<int> getLetterCounts(string str) {
	vector<int> charCount(26, 0);
	for (char c : str) {
		charCount[c - 'a']++;
	}

	return charCount;
}

vector<vector<int> > anagrams(const vector<string> &A) {

	unordered_map<int, vector<int>> letterCounts;
	for (int i = 0; i < A.size(); i++) {
		letterCounts[i] = getLetterCounts(A[i]);
	}

	vector<vector<int>> out;
	vector<bool> checkFlag(A.size(), false);
	for (int i = 0; i < A.size(); i++) {
		if (!checkFlag[i]) {
			vector<int> anagrams;
			anagrams.push_back(i + 1);
			for (int j = i + 1; j < A.size(); j++) {
				if (letterCounts[i] == letterCounts[j]) {
					anagrams.push_back(j + 1);
					checkFlag[j] = true;
				}
			}
			out.push_back(anagrams);
		}
	}

	return out;
}

void printVecVec(vector<vector<int>> in) {

	for (auto vec : in) {
		for (auto i : vec) {
			cout << i << "  ";
		}
		cout << "\n";
	}
 }

int main_intBit83() {

	vector<string> strVec = { "cat", "dog", "god", "tca" };
	printVecVec(anagrams(strVec));
	return 0;
}