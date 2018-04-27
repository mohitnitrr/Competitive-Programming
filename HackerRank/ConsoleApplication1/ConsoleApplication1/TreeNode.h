#pragma once

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(nullptr), right(nullptr) { };
};
