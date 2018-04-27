#include "bits_stdc.h"

class TreeLinkNode {
public:
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int v) :val(v), left(nullptr), right(nullptr), next(nullptr) { };
};


void nextRightPointer(TreeLinkNode* A) {

	queue<TreeLinkNode*> levelNodes;
	levelNodes.push(A);
	while (!levelNodes.empty()) {
		int size = levelNodes.size();
		for (int i = 0; i < size; i++) {
			TreeLinkNode* nextNode = levelNodes.front();
			levelNodes.pop();
			if (i != size - 1)
				nextNode->next = levelNodes.front();

			if (nextNode->left)
				levelNodes.push(nextNode->left);
			if(nextNode->right)
				levelNodes.push(nextNode->right);
		}
	}
}

int main_intBit96() {

	return 0;
}