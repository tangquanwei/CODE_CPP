#ifndef __DOUBLE_LINKED_LIST__
#define __DOUBLE_LINKED_LIST__

template <class T>
class DNode {
private:
	DNode<T>* left;
	DNode<T>* right;

public:
	T data;
	DNode() { left = right = this; }
	DNode(const T& t) {
		left = right = this;
		data = t;
	}

	void insert_left(DNode<T>* p) {
		//connect p to rihgt
		p->right = right;
		right->left = p;
		//connect this to p lift
		p->left = this;
		right = p;
	}
	void insert_right(DNode<T>* p) {
		p->left = left;
		left->right = p;
		p->right = this;
		left = p;
	}
	DNode<T>* delete_node() {
		left->right = right;
		right->left = left;
		return this;
	}

	DNode<T>* next_left() const {
		return right;
	}
	DNode<T>* next_right() const {
		return left;
	}
};




#endif // !__DOUBLE_LINKED_LIST__