#include "bits_stdc.h"

class DLNode {
public:
	int key;
	int value;
	DLNode* next;
	DLNode* prev;
	DLNode(int k, int v) :key(k), value(v), next(nullptr), prev(nullptr) {};
};

class DoublyLinkedList {
	DLNode *head;
	DLNode *tail;
	int count;
public:
	DoublyLinkedList();
	void erase(DLNode*node);
	void push_front(int key, int value);
	DLNode* back();
	DLNode* front();
	void pop_back();
	int size() { return count; }
};

DoublyLinkedList::DoublyLinkedList() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

void DoublyLinkedList::erase(DLNode*node) {
	if (!node)
		return;

	if (node->prev)
		node->prev->next = node->next;
	else
		head = node->next;

	if (node->next)
		node->next->prev = node->prev;
	else
		tail = node->prev;

	count--;
	free(node);
}

void DoublyLinkedList::push_front(int key, int value) {
	DLNode *newNode = new DLNode(key, value);
	if (head)
		head->prev = newNode;
	newNode->next = head;
	head = newNode;
	if (tail == nullptr)
		tail = head;
	count++;
}

DLNode* DoublyLinkedList::back() {
	return tail;
}

DLNode* DoublyLinkedList::front() {
	return head;
}

void  DoublyLinkedList::pop_back() {

	if (!tail)
		return;

	else {
		DLNode* tmp = tail;
		if (tail->prev) {
			tail = tail->prev;
		}
		else {
			head = tail = nullptr;
		}
			
	}
}

class LRUCache {
	DoublyLinkedList dq;
	unordered_map<int, DLNode*> mp;
	int size;
public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value);

};

LRUCache::LRUCache(int capacity) {
	size = capacity;
	mp.clear();
}

int LRUCache::get(int key) {
	if (mp.find(key) != mp.end()) {
		DLNode* itr = mp[key];
		int value = itr->value;
		dq.erase(itr);
		dq.push_front(key, value);
		mp[key] = dq.front();
		return value;
	}

	return -1;
}

void LRUCache::set(int key, int value) {

	if (mp.find(key) != mp.end()) {
		DLNode* itr = mp[key];
		dq.erase(itr);
	}
	else {
		if (dq.size() == size) {
			//delete last entry
			DLNode* last = dq.back();
			dq.pop_back();
			mp.erase(last->key);
		}
	}

	//insert
	dq.push_front(key, value);
	mp[key] = dq.front();
}

int main_intBit91() {

	LRUCache lru(2);

	lru.set(2, 1);
	lru.set(1, 1);
	lru.set(2, 3);
	lru.set(4, 1);

	cout << lru.get(1) << "\n";        //returns 12
	cout << lru.get(2) << "\n";        //returns 10
	//cout << lru.get(10) << "\n";       //returns - 1
	
	//lru.set(6, 14);			   //this pushes out key = 5 as LRU is full.
	
	//cout << lru.get(5) << "\n";		   //returns - 1

	return 0;

}