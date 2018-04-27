#include "bits_stdc.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Compare
{
public:
	bool operator() (vector<int> a, vector<int> b)
	{
		return a[0] > b[0];
	}
};

class CompareListNode
{
public:
	bool operator() (ListNode* a, ListNode* b)
	{
		return a->val > b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*> &A) {

	priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
	ListNode* head =  nullptr;
	ListNode* tail = nullptr;

	vector<ListNode*> ::iterator itr = A.begin();
	while (itr != A.end()) {
		pq.push(*itr);
		itr++;
	}

	while (!pq.empty())
	{
		ListNode *top = pq.top();
		pq.pop();

		if (!head) {
			head = top;
		}

		if (!tail)
			tail = top;
		else {
			tail->next = top;
			tail = tail->next;
		}

		if (top->next)
			pq.push(top->next);
	}

	return head;
}

vector<int> mergeKsortedList(vector<vector<int>> in) {
	
	priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
	vector<int> out;

	vector<vector<int>>::iterator itr = in.begin();
	while (itr != in.end()) {
		pq.push(*itr);
		itr++;
	}

	while (!pq.empty()) {

		vector<int> node = pq.top();
		pq.pop();

		out.push_back(node.front());
		node.erase(node.begin(), node.begin() + 1);
		if (!node.empty())
			pq.push(node);
	}

	return out;
}

int main_52() {

	/*vector<int> a = { 1,5,9 };
	vector<int> b = { 2,6,11 };
	vector<int> c = { 3, 8, 14 };
	vector<int> d = { 4,9, 13 };
	vector<vector<int>> vec = { a,b,c,d };
	vector<int> out = mergeKsortedList(vec);
	*/

	ListNode * a = new ListNode(3);
	a->next = new ListNode(5);
	a->next->next = new ListNode(6);

	ListNode * b = new ListNode(4);
	a->next = new ListNode(8);
	a->next->next = new ListNode(10);

	vector<ListNode*> vec = { a, b };
	ListNode * head = mergeKLists(vec);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}