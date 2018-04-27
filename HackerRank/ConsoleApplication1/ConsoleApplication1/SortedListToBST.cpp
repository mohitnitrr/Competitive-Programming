#include "bits_stdc.h"
#include "LinkedList.h"
#include "TreeNode.h"


TreeNode* sortedListToBST(ListNode* A) {

	if (A == nullptr)
		return nullptr;
	if (A->next == nullptr)
		return new TreeNode(A->val);

	ListNode* prev = nullptr;
	ListNode* slow = A;
	ListNode*fast = A;
	while (fast && fast->next) {
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev) prev->next = nullptr;

	TreeNode *node = new TreeNode(slow->val);
	node->left = sortedListToBST(A);
	node->right = sortedListToBST(slow->next);
	slow->next = nullptr;

	return node;
}

int main_2() {

	ListNode *A = new ListNode(2);
	A->next = new ListNode(3);
	A->next->next = new ListNode(4);

	TreeNode *root = sortedListToBST(A);

	cout << root->val << " ";
	cout << root->left->val << " ";
	cout << root->right->val << " ";
	cout << "\n";
	return 0;
}