#include"bits_stdc.h"

void heapify(vector<int> &A, int i = 0) {

	while (i <= (A.size()-1)/2) {
		int left = 2 * i + 1;
		int right = 2 * (i + 1);
		int largest = i;
		if (left < A.size() && A[left] > A[largest])
			largest = left;
		if (right < A.size() && A[right] > A[largest])
			largest = right;
		if (largest != i)
			swap(A[largest], A[i]);
		else
			break;

		i = largest;
	}
}

void constructHeap(vector<int> &A) {

	for (int i = A.size()-1; i >=0; i--) {
		int parent = (i - 1) / 2;
		heapify(A, parent);
	}
}

int kthsmallest(const vector<int> &A, int B) {

	vector<int> heap(A.begin(), A.begin() + B);
	constructHeap(heap);
	for (int i = B; i < A.size(); i++) {
		if (A[i] < heap[0])
		{
			heap[0] = A[i];
			heapify(heap);
		}
	}

	return heap[0];
}

int main_intBit57(){
	vector<int> inputs = { 5, 42, 36, 81, 70, 35, 93, 41, 92, 14, 15, 50, 100, 51 };
	cout << kthsmallest(inputs, 11);
	return 0;
}