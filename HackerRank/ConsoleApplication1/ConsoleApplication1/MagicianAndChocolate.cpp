#include "bits_stdc.h"

class Heap {

	vector<int> mdata;
public:
	Heap() {};
	Heap(vector<int> in) { constructHeap(in); }
	void constructHeap(vector<int> in);
	void heapify(int i);
	int top();
	void pop();
	void insertAtTop(int n);
};

void Heap::insertAtTop(int n) {
	mdata[0] = n;
	heapify(0);
}

void Heap::constructHeap(vector<int> in) {
	mdata = in;
	for (int i = mdata.size() - 1; i >= 0; i--) {
		int parent = (i - 1) / 2;
		heapify(parent);
	}
}

void Heap::heapify(int i) {
	while (i <= (mdata.size() - 1) / 2) {
		int left = 2 * i + 1;
		int right = 2 * (i + 1);
		int larger = i;
		if (left < mdata.size() && mdata[left] > mdata[larger])
			larger = left;
		if (right < mdata.size() && mdata[right] > mdata[larger])
			larger = right;
		if (larger != i)
			swap(mdata[larger], mdata[i]);
		else
			break;

		i = larger;
	}
}

int Heap::top() {
	if (mdata.size() > 0)
		return mdata[0];

	return INT_MIN;
}

void Heap::pop() {
	if (mdata.size() > 0) {
		mdata[0] = INT_MIN;
		heapify(0);
		//mdata.resize(mdata.size() - 1);
	}
}

int nchoc(int A, vector<int> &B) {

	int const modulo = 1000000007;
	Heap heap(B);
	int sum = 0;
	while (A--) {
		sum += (heap.top() % modulo);
		sum = sum % modulo;
		heap.insertAtTop(heap.top() / 2);
	}

	return sum;
}


int main_intBit89() {

	vector<int> in = { 2147483647, 2000000014, 2147483647 };
	cout << nchoc(10, in);
	return 0;
}