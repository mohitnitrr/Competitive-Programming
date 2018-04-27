#include "bits_stdc.h"


int ___main() {

	unordered_map<string, string> keyValue;
	keyValue["hello"] = "world";
	keyValue["hello"] = "ko";
	
	unordered_map<string, string>::iterator itr = keyValue.begin();
	unordered_map<string, string>::iterator end = keyValue.end();

	while (itr != end) {
		cout << itr->first << "\n" << endl;
		itr++;
	}
	
	return 0;
}