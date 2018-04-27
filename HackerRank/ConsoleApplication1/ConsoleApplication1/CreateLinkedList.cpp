//#include <iostream>
//
//class linkedlist
//{
//public:
//	linkedlist();
//	~linkedlist();
//
//	class node
//	{
//	public:
//		int value;
//		node *next;
//	};
//
//	void insert(int value);
//	void delete(int value);
//	void print();
//	int length();
//	void reverse();
//	node* reverseinngroup(node *node, size_t n);
//	void rotate(int count);
//	node* gethead() { return head; }
//
//private:
//	node* getlastnode();
//	node *head;
//};
//
//linkedlist::node* linkedlist::getlastnode() {
//	node* next = head;
//	while (next && next->next) {
//		next = next->next;
//	}
//	return next;
//}
//
//void linkedlist::rotate(int count) {
//	node* last = getlastnode();
//	if (!head || !last)
//		return;
//
//	while (count--) {
//		last->next = head;
//		last = head;
//		head = head->next;
//		last->next = nullptr;
//	}
//}
//
//linkedlist::node* linkedlist::reverseinngroup(node *node, size_t n) {
//	node *next = node;
//	node *current = nullptr;
//	node *previous = nullptr;
//	int count = 0;
//
//	while (next != nullptr && count < n) {
//		current = next;
//		next = next->next;
//		current->next = previous;
//		previous = current;
//		count++;
//	}
//
//	if (next != nullptr) {
//		node->next = reverseinngroup(next, n);
//	}
//
//	if (node == head) {
//		head = current;
//	}
//
//	return previous;
//}
//
//void linkedlist::reverse() {
//	node *next = head;
//	node *previous = nullptr;
//	while (next != nullptr) {
//		node* reversenode = next;
//		next = next->next;
//		reversenode->next = previous;
//		previous = reversenode;
//	}
//
//	head = previous;
//}
//
//void linkedlist::delete(int value) {
//	node* next = head;
//	node *previous = nullptr;
//	while (next != nullptr && next->value != value) {
//		previous = next;
//		next = next->next;
//	}
//
//	if (next) {
//		if (next == head) {
//			head = next->next;
//		}
//		else
//			previous->next = next->next;
//
//		delete next;
//	}
//	else {
//		std::cout << "value not found in list";
//	}
//}
//
//int linkedlist::length() {
//	node* next = head;
//	int count = 0;
//	while (next != nullptr) {
//		count++;
//		next = next->next;
//	}
//	return count;
//}
//
//void linkedlist::print() {
//	node* begin = head;
//	while (begin != nullptr) {
//		begin != head ? std::cout << "--->" : std::cout << "";
//		std::cout << begin->value;
//		begin = begin->next;
//	}
//	std::cout << "\n";
//}
//
//void linkedlist::insert(int value) {
//	node *nodetoinsert = new node();
//	nodetoinsert->value = value;
//	nodetoinsert->next = nullptr;
//
//	if (head == nullptr) {
//		head = nodetoinsert;
//	}
//	else {
//		node*next, *previous;
//		next = head;
//		previous = nullptr;
//
//		while (next != nullptr) {
//			previous = next;
//			next = next->next;
//		}
//
//		previous->next = nodetoinsert;
//	}
//}
//
//linkedlist::linkedlist()
//{
//	head = nullptr;
//}
//
//linkedlist::~linkedlist()
//{
//	node* next = head;
//	while (next != nullptr) {
//		node *nodetodelete = next;
//		next = next->next;
//		delete nodetodelete;
//	}
//}
//
//int main_x_() {
//	linkedlist list;
//	list.insert(2);
//	list.insert(5);
//	list.insert(3);
//	list.insert(4);
//	list.print();
//	list.rotate(2);
//	std::cout << "length of list : " << list.length() << "\n";
//	list.print();
//
//	list.reverse();
//	list.print();
//	list.reverseinngroup(list.gethead(), 2);
//	list.print();
//
//	list.delete(5);
//	std::cout << "length of list : " << list.length() << "\n";
//	list.print();
//	list.delete(2);
//	std::cout << "length of list : " << list.length() << "\n";
//	list.print();
//
//	return 0;
//}