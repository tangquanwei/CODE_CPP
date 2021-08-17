#include <bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) : data(data) {
		left = right = nullptr;
	}
};
typedef node* tree;

// A utility function to create a node
node* newNode(int data) {
	node* temp = new node(data);
	return temp;
}

node* creatNode(tree& root, int data) {
	if (!root)
		root = new node(data);
	if (data > root->data)
		root->right = creatNode(root->right, data);
	if (data < root->data)
		root->left = creatNode(root->left, data);
	return root;
}

void inOrder(node* root) {
	if (!root)
		return;
	if (root->left)
		inOrder(root->left);
	cout << root->data << " ";
	if (root->right)
		inOrder(root->right);
}
void levelOrder(tree root) {
	if (!root)
		return;
	queue<tree> q;
	q.push(root);
	while (!q.empty()) {
		tree temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max) {
	/* an empty tree is BST */
	if (node == NULL)
		return 1;

	/* false if this node violates
	the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
		   isBSTUtil(node->right, node->data + 1, max);	 // Allow only distinct values
}
/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(node* node) {
	return (isBSTUtil(node, INT_MIN, INT_MAX));
}
// Returns true if given tree is BST.
bool isBST_V2(node* root, node* l=NULL, node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != NULL and root->data <= l->data)
        return false;
 
    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != NULL and root->data >= r->data)
        return false;
 
    // check recursively for every node.
    return isBST_V2(root->left, l, root) &&
           isBST_V2(root->right, root, r);
}
bool isBST_V3(node* root)
{
    static node *prev = NULL;
     
    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!isBST_V3(root->left))
        return false;
 
        // Allows only distinct valued nodes
        if (prev != NULL &&
            root->data <= prev->data)
        return false;
 
        prev = root;
 
        return isBST_V3(root->right);
    }
 
    return true;
}
/* Driver code*/
int main() {
	node* root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);

	if (isBST(root))
		cout << "Is a BST\n";
	else
		cout << "Not a BST\n";

	int a[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	node* r = nullptr;
	for (int i = 0; i < 10; ++i) {
		creatNode(r, a[i]);
	}
	inOrder(r);
	cout << "\n";
	levelOrder(r);
	cout << "\n";

	if (isBST(r))
		cout << "Is a BST\n";
	else
		cout << "Not a BST\n";
	return 0;
}
