#include "bits_stdc.h"
#include <stdio.h>
using namespace std;

vector<string> solve (vector<string> a) {
	vector<string> out;
	for (string str : a) {
		string next;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '\\') {
				if (str[i + 1] == 'b') {
					if (!next.empty())
						next.pop_back();
				}
				else if (str[i + 1] == 'n') {
					out.push_back(next);
					next.clear();
				}

				i++;
			}
			else {
				next.push_back(str[i]);
			}
		}

		if (!next.empty())
			out.push_back(next);
	}

	return out;
}

/*int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> a;
	string s;
	a.push_back("This is sample tests\b \nThis is \bnew line");
	a.push_back("This is also a new line");

    vector<string> out_;
    out_ = solve(a);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_] << "\n";
    }
}*/