#include "LinkedList.h"
#include <iostream>

using namespace std;


ListNode* partition(ListNode* A, int B) {

	ListNode *prev = nullptr;
	ListNode *curr = A;
	ListNode *before = nullptr;
	ListNode *next = nullptr;

	while (curr && curr->val <= B) {
		before = curr;
		curr = curr->next;
	}

	while (curr) {
		next = curr->next;

		if (curr->val < B) {
			if (prev)
				prev->next = next;

			if (!before) {
				before = curr;
				curr->next = A;
				A = curr;
			}
			else {
				curr->next = before->next;
				before->next = curr;
				before = curr;
			}
		}
		else {
			prev = curr;
		}
		curr = next;
	}

	return A;
}


int main_int81() {
	LinkedList list;
	list.pushBack(1);
	list.pushBack(1);
	
	list.print();
	cout << "\n";

	LinkedList list2;
	list2.pushBack(4);
	list2.pushBack(5);
	list2.pushBack(6);
	list2.pushBack(7);
	list2.pushBack(8);
	list2.pushBack(9);
	list2.pushBack(10);
	list2.print();
	cout << "\n";
	
	//list2.removeNthNodeFromEnd(1);
	//list2.removeNthNodeFromEnd(1);

	//list2.rotateListClockWise(1);
	//list2.rotateListClockWise(2);

	//list2.reverseII(2, 4);
	//list2.kreverse(3);

	//list2.mergeSort();

	//list2.substractFirstHalf(list2.getHeadNode());
	//list2.print();
	//cout << "\n";

	//LinkedList result(merge(list.getHeadNode(), list2.getHeadNode()));
	//result.print();
	//cout << "\n";

	//list.reverse();
	//list.removeDuplicatesFromSortedListII();

	//list.print();
	//cout << "\n";
	
	//cout << list.palindrome();

	//LinkedList list3;
	//list3.head = list3.add(list.getHeadNode(), list2.getHeadNode());
	
	//list2.reorderList(list2.getHeadNode());
	//list2.print();

	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(3);
	a->next->next->next = new ListNode(4);
	a->next->next->next->next = new ListNode(5);
	a = partition(a, 5);
	
	LinkedList l(a);
	l.print();
	return 0;
}