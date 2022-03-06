#ifndef __DOUBLELINKEDLIST_H_
#define __DOUBLELINKEDLIST_H__
template <class T>
class Node {
public:
	T val;
	Node<T>*proir, *next;
	Node() : val(0), proir(nullptr), next(nullptr) {}
	Node(T v, Node<T>* p = nullptr, Node<T>* n = nullptr) : val(v), proir(p), next(n) {}
	~Node() {
		proir = nullptr;
		next = nullptr;
	}
};
template <class T>
class DoubleLinkedList {
private:
	size_t size;
	Node<T>*head, *tail;

public:
	DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
	~DoubleLinkedList() {
		while (head != nullptr) {
			Node<T> p = head;
			head = head->next;
			delete p;
		}
		tail = nullptr;
	}
	size_t length() {
		return size;
	}
	void insertHead(const T& t) {
		Node<T>* node = new Node<T>(t);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head->proir = node;
			node->proir = nullptr;
			head = node;
		}
		++size;
	}
	void insertTail(const T& t) {
		Node<T>* node = new Node<T>(t);
		if (tail == nullptr) {
			tail = node;
			head = node;
		}
		else {
			tail->next = node;
			node->proir = tail;
			node->next = nullptr;
			tail = node;
		}
		++size;
	}
	T removeHead() {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		--size;
		Node<T>* p = head;
		head = head->next;
		if (head != nullptr)
			head->proir = nullptr;
		else { // 最后一个
			tail = nullptr;
		}
		T ret = std::move(p->val);
		delete p;

		return ret;
	}
	T removeTail() {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		--size;
		if (size == 0) { // 只有一个
			T t = head->val;
			delete head;
			head = nullptr;
			tail = nullptr;
			return t;
		}
		Node<T>* p = head;
		for (Node<T>* i = head; i->next != nullptr; i = i->next)
			p = i;
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
		--size;
		if (size == 0) { // 最后一个
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		Node<T>* node = p->next;
		p->next = node->next;
		node->next->proir = p;
		delete node;
		return true;
	}
	bool empty() {
		return size == 0 ? true : false;
	}
	friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& l) {
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