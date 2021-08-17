/*
AVL tree is a self-balancing Binary Search Tree (BST)
where the difference between heights of left 
and right subtrees cannot be more than one for all nodes.

The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree
*/
#include <bits/stdc++.h>
using namespace std;
// An AVL tree node
class Node {
public:
	int data;
	Node* left;
	Node* right;
	int height;
	Node() : height(0) {}
	Node(int data)
		: data(data), left(nullptr), right(nullptr), height(1) {}
	void operator=(Node& n) {
		this->data = n.data;
		this->height = n.height;
		this->left = n.left;
		this->right = n.right;
	}
};

// A utility function to get the
// height of the tree
int height(Node* N) {
	if (N == NULL)
		return 0;
	return N->height;
}
// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node* rightRotate(Node* y) {
	// Perform rotation
	Node* x = y->left;
	y->left = x->right;
	x->right = y;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with z
// See the diagram given above.
Node* leftRotate(Node* z) {
	Node* y = z->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = z;
	z->right = T2;

	// Update heights
	z->height = max(height(z->left),
					height(z->right)) +
				1;
	y->height = max(height(y->left),
					height(y->right)) +
				1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node* N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a data
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int data) {
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (new Node(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
Node* minValueNode(Node* node) {
	while (node->left)
		node = node->left;
	return node;
}

// Recursive function to delete a node
// with given data from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, int data) {

	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)//the node to be delete is not exist
		return root;

	// If the data to be deleted is smaller
	// than the root's data, then it lies
	// in left subtree
	if (data < root->data)
		root->left = deleteNode(root->left, data);

	// If the data to be deleted is greater
	// than the root's data, then it lies
	// in right subtree
	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	else { // This is the node to be deleted
		// node with only one child or no child
		if ((root->left == NULL) || (root->right == NULL)) {
			Node* temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else			   // One child case
				*root = *temp; // Copy the contents of
							   // the non-empty child
			free(temp);
		}
		else {
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			Node* temp = minValueNode(root->right);

			// Copy the inorder successor's
			// data to this node
			root->data = temp->data;

			// Delete the inorder successor
			root->right = deleteNode(root->right,
				temp->data);
		}
	}

	// If the tree had only one node
	// then return
	if (root == NULL)
		return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left), height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS NODE (to check whether this
	// node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 &&
		getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 &&
		getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}
// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node* root) {
	if (root != NULL) {
		preOrder(root->left);
		cout << root->data << '(' << root->height << ')' << " ";
		preOrder(root->right);
	}
}
void levelOrder(Node* root) {
	if (!root)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* t = q.front();
		q.pop();
		cout << t->data << '(' << t->height << ')' << ' ';
		if (t->left)
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
}

// Driver Code
int main() {
	Node* root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);


	cout << "Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);
	cout << "\nLevel order traversal of the constructed AVL tree is \n";
	levelOrder(root);
	deleteNode(root, 30);
	cout << "\nAfter delete:\n";
	cout << "Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);
	cout << "\nLevel order traversal of the constructed AVL tree is \n";
	levelOrder(root);

	return 0;
}
