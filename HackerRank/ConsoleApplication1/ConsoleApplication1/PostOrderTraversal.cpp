#include "bits_stdc.h"
#include "TreeNode.h"


vector<int> postOrderTraversal(TreeNode* root) {

	stack<TreeNode*> nodes;
	vector<int> out;
	bool done = false;
	TreeNode *curr = root;
	while (!done) {
		
		while (curr) {
			if (curr->right)
				nodes.push(curr->right);		
			nodes.push(curr);

			curr = curr->left;
		}

		if (nodes.empty())
			done = true;
		else {
			TreeNode* top = nodes.top();
			nodes.pop();
			if (!nodes.empty() && top->right == nodes.top()) {
				TreeNode *right = nodes.top();
				nodes.pop();
				curr = right;
				nodes.push(top);
			}
			else {
				out.push_back(top->val);
			}
		}

	}

	return out;
}

int main_int2() {

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

	vector<int> post = postOrderTraversal(root);
	for (auto i : post)
	{
		cout << i << " ";

	}
	cout << "\n";
	return 0;
}