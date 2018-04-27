#include "bits_stdc.h"


void insertAndRemovefromQueue(deque<int> &q, const vector<int> &A, int index) {
	
	while (!q.empty() && A[q.back()] <= A[index])
		q.pop_back();
	q.push_back(index);
}

vector<int> slidingMaximum(const vector<int> &A, int B) {

	deque<int> queue;
	vector<int> out;
	int i = 0;
	for (; i < B; i++) {
		insertAndRemovefromQueue(queue, A, i);
	}

	for (; i < A.size(); i++) {
		out.push_back(A[queue.front()]);
		if (queue.front() <= i-B)
			queue.pop_front();
		insertAndRemovefromQueue(queue, A, i);
	}

	if (!queue.empty())
		out.push_back(A[queue.front()]);

	return out;

}

void printVector(vector<int> &inputs) {

	for (auto next : inputs) {
		cout << next << "\t";
	}
}

int main_intBit67() {

	printVector(slidingMaximum({ 648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368 }, 9));

	return 0;
}