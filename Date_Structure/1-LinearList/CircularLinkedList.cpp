#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node {
public:
	T val;
	Node* next;
	Node() = default;
	Node(const T& t, Node* nxt = nullptr) : val(t), next(nxt) {}
};
template <typename T>
class CircularLinkedList {
private:
	Node<T>* head;
	size_t size;
public:
	CircularLinkedList() : size{ 0 }, head{ nullptr } {
	}
	~CircularLinkedList() {
		while (head != nullptr) {
			Node<T> p = head;
			head = head->next;
			delete p;
		}
	}
	/* 头插 */
	void insert(const T& t) {
		Node<T>* node = new Node<T>(t);
		if (head == nullptr) {
			head = node;
			head->next = head;
		}
		else {
			node->next = head->next;
			head->next = node;
		}
		++size;
	}
	bool remove(const T& t) {
		if (size == 0)
			throw "Exception : Remove form an empty List :(";
		Node<T>* p = head;
		Node<T>* i = head->next;

		// 要删的前一个
		for (; i->val != t && i != head; i = i->next) {
			p = i;
		}
		if (i == nullptr) { // 没有
			return false;
		}
		--size;
		if (size == 0) { // 只有一个
			delete head;
			head = nullptr;
		}
		else {
			Node<T>* node = p->next;
			p->next = node->next;
			head = p;
			delete node;
		}
		return true;
	}
	bool empty() {
		return size == 0 ? true : false;
	}
	unsigned length() {
		return size;
	}
	friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList& l) {
		if (l.head != nullptr) {
			for (Node<T>* i = l.head->next; i != l.head; i = i->next) {
				os << i->val << " ";
			}
			os << l.head->val;
		}
		else
			os << "null ";
		return os;
	}
};

int main(int argc, char const* argv[]) {
	CircularLinkedList<string>* cl = new CircularLinkedList<string>();
	cl->insert("sda");
	cl->insert("sda1");
	cl->insert("sd2");
	cl->insert("sda3");
	cl->insert("sda4");
	cl->remove("sda");
	cout << *cl;
	return 0;
}