#include "bits_stdc.h"
#include "TreeNode.h"

int maxPathSumUtil(TreeNode*A, int &maxChildSum) {
	if (A == nullptr) {
		maxChildSum = 0;
		return INT_MIN;
	}

	int lSum, rSum;
	int lRet = maxPathSumUtil(A->left, lSum);
	int rRet = maxPathSumUtil(A->right, rSum);
	maxChildSum = max(lSum, rSum) + A->val;
	return max(max((lSum + rSum + A->val), A->val), max(lRet, rRet));
	
}

int maxPathSum(TreeNode* A) {

	int childSum;
	return maxPathSumUtil(A, childSum);
}

