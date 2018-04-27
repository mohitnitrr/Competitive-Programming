#include "bits_stdc.h"
#include "TreeNode.h"


vector<vector<int> > levelOrder(TreeNode* A) {
	queue<TreeNode*> q;
	vector<vector<int> > out;
	q.push(A);
	while (!q.empty())
	{
		vector<int> nextlevel;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			TreeNode* front = q.front();
			q.pop();
			nextlevel.push_back(front->val);

			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}

		out.push_back(nextlevel);
	}

	return out;
}

