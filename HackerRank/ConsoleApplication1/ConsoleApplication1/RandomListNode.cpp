#include "bits_stdc.h"

class RandomListNode {

public:
	RandomListNode* next;
	RandomListNode* random;
	int label;

	RandomListNode(int x) : label(x), next(NULL), random(NULL) {};
};

void printRandomListNode(RandomListNode *head) {
	RandomListNode* curr = head;

	while (curr != nullptr) {
		cout << curr->label << "-->";
		curr = curr->next;
	}
	cout << "NULL" << "\n";
}

RandomListNode* copyRandomList(RandomListNode* A) {

	unordered_map<RandomListNode*, RandomListNode*>originalToNew;
	RandomListNode* curr = A;
	while (curr != nullptr) {
		RandomListNode* newNode = new RandomListNode(curr->label);
		originalToNew[curr] = newNode;
		curr = curr->next;
	}

	curr = A;
	RandomListNode* dupHead = originalToNew[curr];
	RandomListNode* dupCurr = dupHead;
	while (curr != nullptr) {
		dupCurr->next = originalToNew[curr->next];
		dupCurr->random = originalToNew[curr->random];

		curr = curr->next;
		dupCurr = dupCurr->next;
	}

	return dupHead;
}

int main_intBit82() {
	RandomListNode* orignal = new RandomListNode(1);
	orignal->next = new RandomListNode(2);
	orignal->next->next = new RandomListNode(3);

	printRandomListNode(orignal);
	printRandomListNode(copyRandomList(orignal));
	return 0;
}