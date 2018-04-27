#include "bits_stdc.h"

class ComparatorMSD {
public:
	inline bool compare(int aO, int bO) {
		if (aO == 0)
			return true;
		if (bO == 0)
			return false;
		int a = aO, b = bO;
		stack<int> aDig, bDig;
		while (a > 0) {
			aDig.push(a % 10);
			a = a / 10;
		}
		while (b > 0) {
			bDig.push(b % 10);
			b = b / 10;
		}

		while (!aDig.empty() && !bDig.empty()) {
			int aTop = aDig.top();
			aDig.pop();

			int bTop = bDig.top();
			bDig.pop();
			if (aTop < bTop)
				return true;
			else if (aTop > bTop)
				return false;
		}

		if (!aDig.empty()) {
			int tmp =0;
			while (!aDig.empty()) {
				tmp = tmp * 10 + aDig.top();
				aDig.pop();
			}
			return compare(tmp, aO);
		}

		if (!bDig.empty()) {
			int tmp = 0;
			while (!bDig.empty()) {
				tmp = tmp * 10 + bDig.top();
				bDig.pop();
			}
			return compare(bO, tmp);
		}

		return false;
	}

	bool operator()(int a, int b) {
		string aStr = to_string(a);
		string bStr = to_string(b);
		string str;
		int i, j;
		if (aStr.length() <= bStr.length()) {
			str = aStr + bStr + aStr;
			i = 0;
			j = aStr.length();
			while (j < str.length()) {
				if (str[i] < str[j])
					return true;
				else if (str[i] > str[j])
					return false;

				i++; j++;
			}
		}
		else {
			str = bStr + aStr + bStr;
			i = 0;
			j = bStr.length();

			while (j < str.length()) {
				if (str[i] < str[j])
					return false;
				else if (str[i] > str[j])
					return true;

				i++; j++;
			}
		}

		return false;
	}
};

string largestNumber(const vector<int> &A) {

	priority_queue<int, vector<int>, ComparatorMSD> pq;
	for (int i = 0; i < A.size(); i++)
		pq.push(A[i]);

	string out;
	while (!pq.empty()) {
		if(pq.top() !=0)
			out += to_string(pq.top());
		pq.pop();
	}

	if (out.empty())
		out += to_string(0);
	return out;
}

int main_int60() {

	vector<int> in = {232, 23};
	cout << largestNumber(in);

	return 0;
}