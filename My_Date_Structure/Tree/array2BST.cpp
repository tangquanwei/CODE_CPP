// C++ program to print BST in given range
#include <bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class TNode {
public:
	int data;
	TNode* left;
	TNode* right;
	TNode(int data) : data(data) {
		left = right = nullptr;
	}
};

/* A function that constructs Balanced
Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[], int start, int end) {
	/* Base Case */
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	TNode* root = new TNode(arr[mid]);

	/* Recursively construct the left subtree
	and make it left child of root */
	root->left = sortedArrayToBST(arr, start,
		mid - 1);

	/* Recursively construct the right subtree
	and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}
void inOrder(TNode* node) {
	if (node == NULL)
		return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}
void levelOrder(TNode* node) {
	if (!node)
		return;
	queue<TNode*> q;
	q.push(node);
	while (!q.empty()) {
		TNode* temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

// Driver Code
int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	sort(arr, arr + 10);
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	TNode* root = sortedArrayToBST(arr, 0, n - 1);
	cout << "PreOrder Traversal of constructed BST:\n";
	preOrder(root);
	cout << '\n';
	cout << "InOrder Traversal of constructed BST: \n";
	inOrder(root);
	cout << '\n';
	cout << "LevelOrder Traversal of constructed BST: \n";
	levelOrder(root);
	cout << '\n';

	return 0;
}

// This code is contributed by rathbhupendra
