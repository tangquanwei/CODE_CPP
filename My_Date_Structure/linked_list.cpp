#include <iostream>
using namespace std;
template <typename T>
class Link {
public:
	T data;
	Link<T>* next;
	Link(const T data, const Link<T>* next = nullptr)
		: data(data), next(next) {}
	Link(const Link<T>* next) : next(const_cast<Link<T>*>(next)) {}
};
template <typename T>
class LinkList : public Link<T> {
private:
	int len;
	Link<T>*head, *tail;
	Link<T>* setPos(const int); //第i个元素指针
public:
	LinkList(); // default
	~LinkList();
	bool isEmpty();
	void clear();
	int length();
	LinkList<T>& append(const T data);
	bool insert(const int i, const T data);
	bool remove(const int pos);
	T& getValue(const int pos);
	int getPos(const T& data); //get the former
};
template <typename T>
Link<T>* LinkList<T>::setPos(const int i) {
	// return element pinter according to i
	if (i == -1)
		return head;
	int cnt = 0;
	Link<T>* p = head->next;
	while (p != nullptr && cnt < i) {
		p = p->next;
		++cnt;
	}
	return p;
}
template <typename T>
LinkList<T>::LinkList() {
	head->next = tail;
	tail->next = nullptr;
	len = 0;
}
template <typename T>
LinkList<T>::~LinkList() { clear(); }
template <typename T>
bool LinkList<T>::isEmpty() { return static_cast<bool>(len); }
template <typename T>
void LinkList<T>::clear() { //todo clear
}
template <typename T>
int LinkList<T>::length() { return len; }
template <typename T>
LinkList<T>& LinkList<T>::append(const T data) {
	tail = new Link<T>(data, nullptr);
	tail = tail->next; //move behind
	return *this;
}
template <typename T>
bool LinkList<T>::insert(const int i, const T data) {
	Link<T>*p, *q;
	if (p = setPos(i - 1) == nullptr) { //p before i
		cout << "invalid insert" << endl;
		return false;
	}
	q = new Link<T>(data, p->next); //q->i
	p->next = q;
	if (p == tail)
		tail = q;
	++len;
	return true;
}
template <typename T>
bool LinkList<T>::remove(const int i) {
	Link<T>*p, *q;
	if (p = setPos(i - 1) == nullptr) { //p isnot exsit
		cout << "invalid remove point" << endl;
		return false;
	}
	q = p->next; //q is waiting for delete
	if (q == tail) {
		tail = p;
		p->next = nullptr;
	}
	else
		p->next = q->next;
	delete q;
	--len;
	return true;
}
template <typename T>
T& LinkList<T>::getValue(const int pos) {
	return *setPos(pos + 1);
}
template <typename T>
int LinkList<T>::getPos(const T& data) {
	int cnt = 0;
	for (Link<T>* i = head->next; i != tail; i = i->next) {
		if (i->data == data)
			return cnt;
		++cnt;
	}
	return -1;
}
int main() {
	LinkList<int> ls;
	ls.append(12).append(15);
	// cout<<ls.getPos(12);



	return 0;
}
