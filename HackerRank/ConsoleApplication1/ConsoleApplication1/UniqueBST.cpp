#include "bits_stdc.h"
#include "TreeNode.h"

vector<TreeNode*> generateTreesUtil(int start, int end) {
	vector<TreeNode*> list;
	if (start > end ) {
		list.push_back(nullptr);
		return list;
	}

	for (int i = start; i <= end; i++) {
		vector<TreeNode*> left = generateTreesUtil(start, i - 1);
		vector<TreeNode*> right = generateTreesUtil(i+1, end);

		for (int lNode = 0; lNode < left.size(); lNode++) {
			for (int rNode = 0; rNode < right.size(); rNode++) {

				TreeNode *node = new TreeNode(i);
				node->left = left[lNode];
				node->right = right[rNode];
				list.push_back(node);
			}
		}

	}
	return list;
}

vector<TreeNode*> generateTrees(int A) {

	return generateTreesUtil(1, A);
}


int main_int31() {

	generateTrees(3);

	return 0;
}