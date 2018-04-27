#include "bits_stdc.h"

int SmallestSubString(string S) {
	
	int start = 0, end = 0 , len = S.length();
	int minlen = INT_MAX;
	
	vector<bool> visited(26, false);
	int dist_count = 0;
	for (char c : S) {
		if (visited[c - 'a'] == false) {
			dist_count++;
			visited[c - 'a'] = true;
		}
	}

	vector<int> charCount(26, 0);
	int curr_distCount = 0;
	for (int i = 0; i < len; i++) {
		charCount[S[i] - 'a']++;
		if (charCount[S[i] - 'a'] == 1 || ( i != start && S[i] == S[start])) {
			
			if(charCount[S[i] - 'a'] == 1) curr_distCount++;
			
			end = i;
			while (charCount[S[start] - 'a'] > 1) {
				charCount[S[start] - 'a']--;
				start++;
			}

			if (curr_distCount == dist_count) {
				minlen = min(minlen, end - start + 1);
			}
		}
	}

	return minlen;
}
int main_int_1() {

	cout << SmallestSubString("aaccbbacaab");
	return 0;
}