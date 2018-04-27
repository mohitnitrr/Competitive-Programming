#include "bits_stdc.h"
#include "TreeNode.h"

TreeNode* convertToBSTUtil(vector<int> in, int l, int r) {
	int mid = (l + r) / 2;
	TreeNode *node = new TreeNode(in[mid]);

	if (mid > l)
		node->left = convertToBSTUtil(in, l, mid - 1);
	if (mid < r)
		node->right = convertToBSTUtil(in, mid + 1, r);

	return node;
}

TreeNode* convertToBST(vector<int> in) {

	return convertToBSTUtil(in, 0, in.size()-1);
}


int diameterUtil(TreeNode* A, int *height) {

	if (A == nullptr)
		return 0;

	int lH, rH;
	int leftD = diameterUtil(A->left, &lH);
	int rightD = diameterUtil(A->right, &rH);
	*height = max(lH, rH) + 1;
	return max((lH + rH + 1), max(leftD, rightD));
}

int diameter(TreeNode*A) {
	int h;
	return diameterUtil(A, &h);
}
bool isBalancedUtil(TreeNode*A, int *height) {

	if (A == nullptr) {
		*height = 0;
		return true;
	}

	int hl, hr;
	bool bl = isBalancedUtil(A->left, &hl);
	bool br = isBalancedUtil(A->right, &hr);
	*height = max(hl, hr) + 1;
	if (bl && br && (abs(hl - hr) < 2)) {
		return true;
	}
	return false;
}

int isBalanced(TreeNode* A) {
	int h;
	return isBalancedUtil(A, &h);
}

void printInorder(TreeNode* root) {

	stack<TreeNode*> nodes;
	TreeNode* curr = root;
	while (true) {
		while (curr) {
			nodes.push(curr);
			curr = curr->left;
		}

		if (nodes.empty())
			break;
		
		TreeNode *top = nodes.top();
		nodes.pop();
		cout << top->val << " ";
		curr = top->right;
	}
}

int main_int3() {

	vector<int> input = { 10, 2 };
	TreeNode *root = convertToBST(input);
	printInorder(root);
	cout << "\n";
	cout << isBalanced(root);

	return 0;
}