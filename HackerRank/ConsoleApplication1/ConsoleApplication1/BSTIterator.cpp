#include "bits_stdc.h"
#include "TreeNode.h"

class BSTIterator {

public:
	BSTIterator(TreeNode *root);
	bool hasNext();
	int next();
};

TreeNode *currNode = nullptr;
stack<TreeNode*> nodes;

BSTIterator::BSTIterator(TreeNode *root) {
	currNode = root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {

	if (nodes.empty() && currNode == nullptr)
		return 0;

	return 1;
}

/** @return the next smallest number */
int BSTIterator::next() {

	int val = 0;
	while (currNode) {
		nodes.push(currNode);
		currNode = currNode->left;
	}
	
	if(!nodes.empty()) {

		val = nodes.top()->val;
		currNode = nodes.top()->right;
		nodes.pop();
	}

	return val;
}

int main_int1() {

	//level 1
	 TreeNode* root = new TreeNode(10);

	//level 2
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);

	//level 3
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(12);
	
	BSTIterator itr(root);
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();
	cout << itr.next();

	return 0;
}