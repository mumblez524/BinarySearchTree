#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

using namespace std;

template <class T>
struct BSTNode {
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>() {
		right = nullptr;
		left = nullptr;
	}
};

template <class T>
class BSTree {
private:
	int mSize;
	BSTNode<T>* mRoot;

	void copy(const BSTNode<T>* node) {
		BSTNode<T>* nodePtr = node;
		if (nodePtr != nullptr) {
			insert(nodePtr);
			copy(nodePtr->left);
			copy(nodePtr->right);
		}
	}
	void deleteTree(BSTNode<T>* node) {
		if (node != nullptr) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
			mSize--;
		}
	}

	void preorderR(const BSTNode<T>* node) const {
		if (node != nullptr) {
			cout << node->data << " ";
			preorderR(node->left);
			preorderR(node->right);
		}
	}
	void postorderR(const BSTNode<T>* node) const {
		if (node != nullptr) {
			postorderR(node->left);
			postorderR(node->right);
			cout << node->data << " ";
		}
	}
	void inorderR(const BSTNode<T>* node) const {
		if (node != nullptr) {
			inorderR(node->left);
			cout << node->data << " ";
			inorderR(node->right);
		}
	}

public:
	BSTree() {
		mSize = 0;
	}
	BSTree(const BSTree<T>& tree) {
		mSize = tree.size();
		copy();
	}
	~BSTree() {
		clear();
	}
	BSTree& operator=(const BSTree<T>& tree) {
		if (this != &tree) {
			clear();
			copy(tree->mRoot);
		}
		return *this;
	}

	void clear() {
		deleteTree(mRoot);
	}

	int size() const {
		return mSize;
	}
	void insert(int item) {
		BSTNode<T>* prev = nullptr,
			* curr = mRoot,
			* leaf = new BSTNode<T>;
		leaf->data = item;
		while (curr != nullptr) {
			prev = curr;
			if (item < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (mRoot == nullptr)
			mRoot = leaf;
		else if (item < prev->data)
			prev->left = leaf;
		else
			prev->right = leaf;
		mSize++;
	}

	void preorder() const {
		preorderR(mRoot);
	}
	void postorder() const {
		postorderR(mRoot);
	}
	void inorder() const {
		inorderR(mRoot);
	}
};

#endif