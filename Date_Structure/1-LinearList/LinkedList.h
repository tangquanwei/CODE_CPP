#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H__

template <class T>
class Node {
public:
	T val;
	Node* next;
	Node() = default;
	Node(const T& t, Node* nxt = nullptr) : val(t), next(nxt) {}
};
template <class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned size;

public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) {}
	void insertHead(const T& t) {
		Node<T>* node = new Node<T>(t);
		if (head == nullptr) {
			head = node;
			tail = head;
		}
		else {
			node->next = head;
			head = node;
		}
		++size;
	}
	void insertTail(const T& t) {
		Node<T>* node = new Node<T>(t);
		if (tail == nullptr) {
			tail = node;
			head = tail;
		}
		else {
			tail = tail->next = node;
		}
		++size;
	}
	T removeHead() {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		--size;
		Node<T>* p = head;
		T ret = std::move(p->val);
		head = head->next;
		delete p;
		return ret;
	}
	T removeTail() {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		--size;
		Node<T>* p = head;
		for (Node<T>* i = head; i->next != nullptr; i = i->next)
			p = i;
		if (p == head) { // 第一个
			T t = head->val;
			delete head;
			head = nullptr;
			tail = nullptr;
			return t;
		}
		Node<T>* node = p->next;
		T ret = std::move(node->val);
		p->next = nullptr;
		tail = p;
		delete node;
		return ret;
	}
	bool remove(const T& t) {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		Node<T>* p = head;
		Node<T>* i = head;
		// 要删的前一个
		for (; i != nullptr && i->val != t; i = i->next) {
			p = i;
		}
		if (i == nullptr) { // 没有
			return false;
		}
		if (p == head) { // 第一个
			removeHead();
			return true;
		}

		Node<T>* node = p->next;
		p->next = node->next;
		delete node;
		--size;
		return true;
	}

	bool empty() {
		return size == 0 ? true : false;
	}
	unsigned length() {
		return size;
	}
	void reverse() {
		Node<T>*p = head->next, *pre = head;
		tail = head;
		size = 1;
		while (p != nullptr) {
			Node<T>* node = p;
			p = p->next;
			insertHead(node->val);
			delete node;
			// pre->next = nullptr; // 被删的须置空
			pre->next = p; // 主要是把head后面的置空
		}
	}
	~LinkedList() {
		while (head != nullptr) {
			Node<T> p = head;
			head = head->next;
			delete p;
		}
		tail = nullptr;
	}
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& l) {
		if (l.head != nullptr)
			for (Node<T>* i = l.head; i != nullptr; i = i->next) {
				os << i->val << " ";
			}
		else
			os << "null ";
		return os;
	}
};
#endif