#include "bits_stdc.h"

string simplifyPath(string A) {
	int n = A.size();
	int i = 1;
	int j = 1;
	stack<string> path;
	string out;
	while (1) {

		while (i < n && A[i] != '/') {
			i++;
		}
		
		if (i == n)
			i = i - 1;

		string str = A.substr(j, i - j);
		if (str == "..") {
			if (path.empty()) {
				cout << "Invalid state";
			}
			else {
				path.pop();
			}
		}
		else if (!str.empty() && str != ".")
			path.push(str);

		j = i + 1;
		if (i == n)
			break;
		i++;
	}

	while (!path.empty())
	{
		out.insert(0, path.top());
		out.insert(0, "/");
		path.pop();
	}
	if(out.empty())
		out.insert(0, "/");

	return out;
}

int main_int91() {

	cout<< simplifyPath("/..");
	return 0;
}