#include "bits_stdc.h"
#include "TreeNode.h"

bool isLeaf(TreeNode * A) {
	return !A->left && !A->right;
}

void rootToLeafPathSumUtil(TreeNode* A, int B, vector<int> &curr, vector<vector<int>> &out) {

	if (A == nullptr)
		return;

	B = B - A->val;
	curr.push_back(A->val);
	if (B == 0 && isLeaf(A) && !curr.empty()) {
		out.push_back(curr);
	}

	rootToLeafPathSumUtil(A->left, B, curr, out);
	rootToLeafPathSumUtil(A->right, B, curr, out);
	curr.pop_back();
}

vector<vector<int> >pathSum(TreeNode* A, int B) {

	vector<vector<int>> out;
	vector<int> curr;
	rootToLeafPathSumUtil(A, B, curr, out);
	return out;
}

int const mod = 1003;
void sumRootToLeafUtil(TreeNode* A, int curr, int &out) {

	if (A == nullptr)
		return;

	curr = (curr * 10 + A->val) % mod;
	if (isLeaf(A)) {
		out += curr;
		out = out % mod;
	}

	sumRootToLeafUtil(A->left, curr, out);
	sumRootToLeafUtil(A->right, curr, out);
}

int sumRootToLeaf(TreeNode* A) {
	int curr = 0;
	int out = 0;
	sumRootToLeafUtil(A, curr, out);
	return out;
}

/*int main() {

	TreeNode* root = new TreeNode(1);

	//level 2
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	//level 3
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	
	
	vector<vector<int>> out = pathSum(root, 21);
	for (auto x : out) {
		for (int i : x) {
			cout << i << " ";
		}
		cout << endl;
	}

	cout << sumRootToLeaf(root);
	return 0;
}*/