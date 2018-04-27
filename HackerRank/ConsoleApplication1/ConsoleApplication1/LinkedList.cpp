#include "LinkedList.h"
#include <iostream>
#include "bits_stdc.h"

using namespace std;

void LinkedList::pushBack(int val) {
	if (head == nullptr) {
		head = new ListNode(val);
		return;
	}

	ListNode *next = head;
	while (next->next != nullptr) {
		next = next->next;
	}

	next->next = new ListNode(val);
}

void LinkedList::print() {

	ListNode *next = head;
	while (next != nullptr) {
		cout << next->val << "-->";
		next = next->next;
	}
	cout << "NULL" << "  ";

}

bool LinkedList::palindromeUtil(ListNode **left, ListNode *right) {
	if (right == nullptr)
		return true;

	if (palindromeUtil(left, right->next)) {
		if ((*left)->val == right->val) {
			*left = (*left)->next;
			return true;
		}
	}

	return false;
}

bool LinkedList::palindrome() {
	
	return palindromeUtil(&head, head);
}

void LinkedList::reverse() {
	head = reverseUtil(head);
	return;
}

ListNode* LinkedList::reverseUtil(ListNode *head) {
	ListNode *prev = nullptr;
	ListNode *curr = head;
	ListNode *next = nullptr;
	
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}


void LinkedList::removeDuplicatesFromSortedList() {

	ListNode *curr = head;
	while (curr != nullptr) {
		if (curr->next != nullptr && curr->val == curr->next->val) {
			ListNode *dup = curr->next;
			curr->next = dup->next;
			free(dup);
		}
		else
			curr = curr->next;
	}
}

void LinkedList::removeDuplicatesFromSortedListII() {
	
	ListNode *prev = nullptr;
	ListNode *curr = head;
	bool dup = false;
	while (curr != nullptr) {
		if (curr->next != nullptr && curr->val == curr->next->val) {
			ListNode *dupNode = curr->next;
			curr->next = dupNode->next;
			free(dupNode);
			dup = true;
		}
		else if (dup) {
			if (prev == nullptr)
				head = curr->next;
			else
				prev->next = curr->next;

			free(curr);
			curr = (prev == nullptr) ?head: prev->next;
			dup = false;
		}
		else {
			prev = curr;
			curr = curr->next;
		}

	}
}


ListNode * merge(ListNode* l1, ListNode* l2) {

	if (l1 == nullptr)
		return l2;
	else if (l2 == nullptr)
		return l1;
	else {
		if (l1->val < l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else {
			l2->next = merge(l1, l2->next);
			return l2;
		}
			
	}
	return nullptr;
}

void LinkedList::removeNthNodeFromEnd(int index) {

	ListNode *nthnodePrev = nullptr;
	ListNode *curr = head;
	int count = 0;

	while (curr != nullptr && count < index) {
		curr = curr->next;
		count++;
	}

	if (count == index) {
		while (curr != nullptr) {
			curr = curr->next;
			nthnodePrev = nthnodePrev == nullptr ? head : nthnodePrev->next;
		}
	}

	ListNode * nthNode;
	if (nthnodePrev == nullptr) {
		nthNode = head;
		head = nthNode->next;
	}
	else {
		nthNode = nthnodePrev->next;
		nthnodePrev->next = nthNode->next;
	}

	free(nthNode);
}


void LinkedList::rotateListAntiClockWise(int index) {
	
	ListNode* prev = nullptr;
	ListNode* next = head;
	int count = 0;
	while (next->next != nullptr && count < index) {
		prev = next;
		next = next->next;
		count++;
	}

	ListNode *last = next;
	while (last->next != nullptr) {
		last = last->next;
	}
	
	if (prev) {
		last->next = head;
		head = next;
		prev->next = nullptr;
	}

}


void LinkedList::rotateListClockWise(int index) {
	ListNode *nthnodePrev = nullptr;
	ListNode *curr = head;
	int count = 1;
	int length = 0;
	while (curr != nullptr)
	{
		length++;
		curr = curr->next;
	}
	index = index % length;
	curr = head;
	while (curr->next != nullptr && count < index) {
		curr = curr->next;
		count++;
	}
	if (count == index) {
		while (curr->next != nullptr) {
			curr = curr->next;
			nthnodePrev = nthnodePrev == nullptr ? head : nthnodePrev->next;
		}

		if (nthnodePrev) {
			curr->next = head;
			head = nthnodePrev->next;
			nthnodePrev->next = nullptr;
		}
	}
}

void LinkedList::reverseII(int m, int n) {

	int count = 1;
	ListNode *curr = head;
	ListNode *prev = nullptr;
	ListNode *next = nullptr;

	while (count < m) {
		prev = curr;
		curr = curr->next;
		count++;
	}

	ListNode *prevStor = prev;
	ListNode *currStor = curr;
	while (count <= n) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	currStor->next = curr;
	if (prevStor)
		prevStor->next = prev;
	else
		head = prev;
}

ListNode* kreverseUtil(ListNode * node, int k) {
	
	if (node == nullptr)
		return nullptr;

	ListNode *curr = node;
	ListNode *prev = nullptr;
	ListNode *next = nullptr;
	int count = 0;
	while (curr != nullptr && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	node->next = kreverseUtil(curr, k);
	
	return prev;
}

void LinkedList::kreverse(int k) {
	head = kreverseUtil(head, k);
}

ListNode* midNode(ListNode* head) {

	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode *slow = head;
	ListNode *fast = head;
	ListNode *prev = nullptr;
	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	
	prev->next = nullptr;
	return slow;
}

ListNode* mergeSortUtil(ListNode* node) {
	
	if (node == nullptr || node->next == nullptr)
		return node;

	ListNode *mid = midNode(node);
	ListNode * l1 = mergeSortUtil(node);
	ListNode * l2 = mergeSortUtil(mid);
	return merge(l1, l2);
}

void LinkedList::mergeSort() {
	head = mergeSortUtil(head);
}

void LinkedList::substractFirstHalf(ListNode *head) {
	
	int length = 0;
	ListNode* curr = head;
	while (curr != nullptr) {
		length++;
		curr = curr->next;
	}

	int mid = length / 2;
	curr = head;
	ListNode *prev = nullptr;
	ListNode *next = nullptr;
	int count = 0;
	while (count < mid ) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

		count++;
	}
	
	ListNode* prevMid = prev;
	ListNode* midNode = curr;
	if (length & 1) {
		curr = curr->next;
	}

	while (prev != nullptr && curr != nullptr) {
		prev->val = curr->val - prev->val;
		prev = prev->next;
		curr = curr->next;
	}

	curr = prevMid;
	prev = midNode;
	next = nullptr;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}

ListNode* LinkedList::add(ListNode  *a, ListNode *b) {

	a = reverseUtil(a);
	b = reverseUtil(b);

	ListNode *ac = a;
	ListNode *bc = b;
	ListNode *out = nullptr;
	ListNode* outNext =  nullptr;
	int carry = 0;
	while (ac || bc) {
		int firstDig = 0, secondDig = 0;
		if (ac) {
			firstDig = ac->val;
			ac = ac->next;
		}
		if (bc) {
			secondDig = bc->val;
			bc = bc->next;
		}

		int currDig = (firstDig + secondDig + carry) % 10;
		carry = (firstDig + secondDig + carry) / 10;

		ListNode *nextNode = new ListNode(currDig);
		if (!out) {
			out = nextNode; outNext = out;
		}
		else {
			outNext->next = nextNode;
			outNext = nextNode;
		}
	}

	if (carry > 0) {
		outNext->next = new ListNode(carry);
	}

	a = reverseUtil(a);
	b = reverseUtil(b);
	out = reverseUtil(out);

	return out;
}

ListNode * mergeTwoList(ListNode* l1, ListNode* l2) {

	if (l1 == nullptr)
		return l2;
	else if (l2 == nullptr)
		return l1;

	ListNode *l1Next = l1->next;
	l1->next = l2;
	l2->next = mergeTwoList(l1Next, l2->next);
	return l1;
}

//L0->Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> …
ListNode* LinkedList::reorderList(ListNode* A) {

	int length = 0;
	ListNode* curr = A;
	while (curr) {
		length++;
		curr = curr->next;
	}

	int mid = length / 2;
	curr = A;
	int count = 0;
	while (count < mid-1) {
		curr = curr->next;
		count++;
	}

	ListNode *l2 = reverseUtil(curr->next);
	curr->next = nullptr;
	return mergeTwoList(A, l2);
}

ListNode* LinkedList::detectCycle(ListNode* A) {

	if (A == nullptr)
		return nullptr;

	ListNode *slow = A;
	ListNode *fast = A->next;
	bool isCycle = false;
	while (fast && fast->next) {
		if (slow == fast || slow == fast->next) {
			isCycle = true;
			slow = slow == fast ? fast : fast->next;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	if (isCycle) {
		fast = A->next;
		slow = slow->next;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}

	return nullptr;
}

/*ListNode* partition(ListNode* A, int B) {

	ListNode *prev = nullptr;
	ListNode *curr = A;
	ListNode *before = nullptr;
	ListNode *next = nullptr;
	ListNode *retHead = nullptr;
	while (curr) {
		next = curr->next;

		if (curr->val < B) {
			if (prev)
				prev->next = next;

			if (!before) {
				before = curr;
				curr->next = A;
				retHead = curr;
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

	return retHead;
}
*/