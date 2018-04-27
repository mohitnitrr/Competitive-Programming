#include "bits_stdc.h"
#include "TreeNode.h"

class Tree {

	void verticalOrderTraversalUtil(TreeNode* node, int vOrdermap, map<int, vector<int>> &nodesWithLevels);
public:
	TreeNode* root;
	Tree() :root(nullptr) { };
	vector<vector<int>> verticalOrderTraversal();
	vector<int> InorderTraversal();
	vector<vector<int> > zigzagLevelOrder(TreeNode* A);
	int maxDepth(TreeNode* A);
	int minDepth(TreeNode* A);
	int kSmallestElement(TreeNode* A, int k);
	
	TreeNode* invertTree(TreeNode* root);
	int hasPathSum(TreeNode* A, int B);
	vector<int> preOrderTraversal(TreeNode *node);
	//int isBalanced(TreeNode* A);

	int lca(TreeNode* A, int B, int C);
	int isSameTree(TreeNode* A, TreeNode* B);
	int isSymmetric(TreeNode* A);

	TreeNode* treeToLinkedList(TreeNode* node);
	int t2Sum(TreeNode* A, int B);

};


void Tree::verticalOrderTraversalUtil(TreeNode* node, int vOrder, map<int, vector<int>> &nodesWithLevels) {

	if (!node)
		return;

	if (nodesWithLevels.find(vOrder) != nodesWithLevels.end())
		nodesWithLevels[vOrder].push_back(node->val);
	else {
		vector<int> levelNodes;
		levelNodes.push_back(node->val);
		nodesWithLevels[vOrder] = levelNodes;
	}
	verticalOrderTraversalUtil(node->left, vOrder - 1, nodesWithLevels);
	verticalOrderTraversalUtil(node->right, vOrder + 1, nodesWithLevels);
}

vector<vector<int>> Tree::verticalOrderTraversal() {
	
	map<int, vector<int>> nodesWithLevels;
	verticalOrderTraversalUtil(root, 0, nodesWithLevels);
	vector<vector<int>> out;
	for (auto nextLevel : nodesWithLevels) {
		out.push_back(nextLevel.second);
	}

	return out;
}

vector<int> Tree::InorderTraversal() {

	TreeNode* curr = root;
	stack<TreeNode*> tmpStack;
	vector<int> out;
	while (true) {

		while (curr) {
			tmpStack.push(curr);
			curr = curr->left;
		}

		if (tmpStack.empty())
			break;
		else {
			curr = tmpStack.top();
			tmpStack.pop();
			out.push_back(curr->val);
			curr = curr->right;
		}
	}

	return out;
}

int Tree::kSmallestElement(TreeNode* A, int k) {
	TreeNode* curr = A;
	stack<TreeNode*> tmpStack;
	int count = 0;
	while (true) {

		while (curr) {
			tmpStack.push(curr);
			curr = curr->left;
		}

		if (tmpStack.empty())
			return -1;
		else {
			curr = tmpStack.top();
			tmpStack.pop();
			count++;
			if (count == k)
				return curr->val;
			curr = curr->right;
		}
	}

	return -1;
}

vector<vector<int> > Tree::zigzagLevelOrder(TreeNode* A) {
	vector<vector<int>> out;
	stack<TreeNode*> lTor;
	stack<TreeNode*> rTol;

	rTol.push(A);
	while (!lTor.empty() || !rTol.empty()) {
		vector<int> levelData;

		if (!lTor.empty()) {
			while (!lTor.empty()) {
				TreeNode* topEle = lTor.top();
				levelData.push_back(topEle->val);
				if (topEle->right)
					rTol.push(topEle->right);
				if (topEle->left)
					rTol.push(topEle->left);

				lTor.pop();
			}
		}

		else if (!rTol.empty()) {
			while (!rTol.empty()) {
				TreeNode* topEle = rTol.top();
				levelData.push_back(topEle->val);
				if (topEle->left)
					lTor.push(topEle->left);
				if (topEle->right)
					lTor.push(topEle->right);

				rTol.pop();
			}
		}

		out.push_back(levelData);
	}

	return out;
}

int Tree::maxDepth(TreeNode* A) {
	if (A == nullptr)
		return 0;

	return max(maxDepth(A->left), maxDepth(A->right)) + 1;
}

int Tree::minDepth(TreeNode* A) {
	if (!A->left && !A->right)
		return 1;

	if (A->left && !A->right)
		return minDepth(A->left) + 1;
	else if(A->right && !A->left)
		return minDepth(A->right) + 1;

	return min(minDepth(A->left), minDepth(A->right)) + 1;
}

TreeNode* Tree::invertTree(TreeNode* node) {
	if (node == nullptr)
		return nullptr;

	TreeNode* temp = node->left;
	node->left = node->right;
	node->right = temp;

	invertTree(node->left);
	invertTree(node->right);

	return node;
}

int Tree::hasPathSum(TreeNode* A, int B) {

	if (A == nullptr || B < 0)
		return 0;

	if (B - A->val == 0 &&  A->left == nullptr && A->right == nullptr)
		return 1;

	return hasPathSum(A->left, B - A->val) ||
		hasPathSum(A->right, B - A->val);
}

vector<int> Tree::preOrderTraversal(TreeNode *node) {

	TreeNode *curr = nullptr;
	stack<TreeNode*> traversalstack;
	traversalstack.push(node);
	vector<int> out;
	while (!traversalstack.empty()) {
		curr = traversalstack.top();
		traversalstack.pop();
		out.push_back(curr->val);

		if (curr->right)
			traversalstack.push(curr->right);

		if (curr->left)
			traversalstack.push(curr->left);

	}

	return out;
}


TreeNode* lcaUtil(TreeNode* node, int A, int B, bool *bA, bool *bB) {

	if (node == nullptr)
		return nullptr;

	if (node->val == A) {
		*bA = true;
		return node;
	}

	if (node->val == B) {
		*bB = true;
		return node;
	}

	TreeNode *lca_left = lcaUtil(node->left, A, B, bA, bB);
	TreeNode *lca_right = lcaUtil(node->right, A, B, bA, bB);
	if (lca_left && lca_right) return node;
	return (lca_left ? lca_left : lca_right);
}

bool findEle(TreeNode *node, int val) {

	if (node == nullptr)
		return false;

	if (node->val == val)
		return true;

	return findEle(node->left, val) || findEle(node->right, val);
}

int Tree::lca(TreeNode* A, int B, int C) {
	bool bB = false;
	bool bC = false;
	TreeNode *res = lcaUtil(A, B, C, &bB, &bC);

	if (!res)
		return -1;

	if ((bB && bC) || (!bB && findEle(res, B)) || (!bC && findEle(res, C)))
		return res->val;

	return -1;
}

int Tree::isSameTree(TreeNode* A, TreeNode* B) {

	if (!A && !B)
		return 1;

	if ((A && !B) || (!A && B) || (A->val != B->val))
		return 0;

	return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

int isSymmetricUtil(TreeNode* A, TreeNode* B) {

	if (!A && !B)
		return 1;

	if ((A && !B) || (!A && B) || (A->val != B->val))
		return 0;

	return isSymmetricUtil(A->left, B->right) && isSymmetricUtil(A->right, B->left);
}

int Tree::isSymmetric(TreeNode* A) {

	if (A == nullptr)
		return 1;
	
	return isSymmetricUtil(A->left, A->right);
}

void fixLeftPointer(TreeNode *node) {

	static TreeNode *prev = nullptr;
	if (node) {
		fixLeftPointer(node->left);
		node->left = prev;
		prev = node;
		fixLeftPointer(node->right);
	}
}

/*
TreeNode* Tree::treeToLinkedList(TreeNode* node) {

	fixLeftPointer(node);
	for (; node->right; node = node->right) {};

	while (node->left) {
		node->left->right = node;
		node = node->left;
		
		node->right->left = nullptr; // for singly linked list set left of each node to nullptr
	}

	return node;
}
*/

TreeNode* Tree::treeToLinkedList(TreeNode* node) {

	stack<TreeNode*> nodeStack;
	TreeNode* prev = nullptr;
	nodeStack.push(node);
	while (!nodeStack.empty()) {
		TreeNode* top = nodeStack.top();
		nodeStack.pop();
		if (!prev)
			prev = top;
		else {
			prev->right = top;
			prev = top;
		}
		if (top->right)
			nodeStack.push(top->right);
		if (top->left)
			nodeStack.push(top->left);

		top->left = nullptr;
	}

	return node;
}

int Tree::t2Sum(TreeNode* A, int B) {

	stack<TreeNode*>inOrderLtoR;
	stack<TreeNode*>inOrderRtoL;
	TreeNode* curr = A;
	bool traLtoRComplete = false;
	bool traRtoLComplete = false;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;

	TreeNode* leftCurr = A;
	TreeNode* rightCurr = A;

	while (leftCurr) {
		inOrderLtoR.push(leftCurr);
		leftCurr = leftCurr->left;
	}

	while (rightCurr) {
		inOrderRtoL.push(rightCurr);
		rightCurr = rightCurr->right;
	}
	while (!traLtoRComplete || !traRtoLComplete)
	{
		while (!traLtoRComplete) {
			leftNode = inOrderLtoR.top();
			inOrderLtoR.pop();
			leftCurr = leftNode->right;
			traLtoRComplete = true;

			while (leftCurr) {
				inOrderLtoR.push(leftCurr);
				leftCurr = leftCurr->left;
			}
		}

		while (!traRtoLComplete) {
			rightNode = inOrderRtoL.top();
			inOrderRtoL.pop();
			rightCurr = rightNode->left;
			traRtoLComplete = true;

			while (rightCurr) {
				inOrderRtoL.push(rightCurr);
				rightCurr = rightCurr->right;
			}
		}

		if (!leftNode || !rightNode || leftNode == rightNode)
			return 0;

		int lVal = leftNode->val;
		int rVal = rightNode->val;
		if (lVal + rVal == B)
			return 1;
		else if (lVal + rVal < B && !inOrderLtoR.empty())
			traLtoRComplete = false;
		else if (lVal + rVal > B && !inOrderRtoL.empty())
			traRtoLComplete = false;
	}

	return 0;
}

int main_intBit100() {

	Tree tree;
	//level 1
	tree.root = new TreeNode(10);

	//level 2
	tree.root->left = new TreeNode(9);
	tree.root->right = new TreeNode(20);

	//level 3
	/*tree.root->left->left = new TreeNode(2);
	tree.root->left->right = new TreeNode(5);
	tree.root->right->left = new TreeNode(8);
	tree.root->right->right = new TreeNode(12);
	*/
	//vector<vector<int>> out = tree.zigzagLevelOrder(tree.root);

	/*for (auto vec : out) {
		for (auto node : vec) {
			cout << node << " ";
		}
		cout << "\n";
	}

	cout << tree.minDepth(tree.root);
	*/

	/*TreeNode* head = tree.treeToLinkedList(tree.root);
	TreeNode* curr = head;
	while (curr) {
		cout << curr->val << "->";
		curr = curr->right;
	}
	cout << "NULL";
	*/

	cout << tree.t2Sum(tree.root, 40);

	/*
	vector<int> out = tree.preOrderTraversal(tree.root);
	for (int i : out) {
		cout << i << " ";
	}
	cout << "\n";
	*/

	return 0;
}