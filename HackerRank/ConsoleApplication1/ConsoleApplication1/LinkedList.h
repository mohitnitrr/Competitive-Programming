

class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int inVal) :val(inVal), next(nullptr) {}
};


class LinkedList {

public:
	ListNode* head;
	LinkedList(ListNode *head = nullptr) :head(head) {};
	void pushBack(int val);
	bool palindrome();
	void print();
	void reverse();
	void reverseII(int m, int n);
	void kreverse(int k);
	void removeDuplicatesFromSortedList();
	void removeDuplicatesFromSortedListII();
	void removeNthNodeFromEnd(int index);
	void rotateListAntiClockWise(int index);
	void rotateListClockWise(int index);
	void substractFirstHalf(ListNode* node);

	void mergeSort();


	//gettterHead Node
	ListNode* getHeadNode()const { return head; }

	bool palindromeUtil(ListNode **left, ListNode *right);
	ListNode* reverseUtil(ListNode *head);

	ListNode *add(ListNode *a, ListNode*b);

	//L0->Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> …
	ListNode* reorderList(ListNode* A);

	ListNode* detectCycle(ListNode* A);

};

ListNode * merge(ListNode* l1, ListNode* l2);