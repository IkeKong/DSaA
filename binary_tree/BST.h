#pragma once
#include <iostream>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right

		Node(Key key, Value value) {
			key = key;
			value = value;
			left = NULL;
			right = NULL;
		}
	};

	Node* root;
	int count;

public:
	BST() {
		root = NULL;
		count = 0;
	}

	~BST() {
		destroy(root);
	}

	int size(){
		return count;
	}

	int isEmpty() {
		return count == NULL;
	}

	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	Node* search(Key key) {
		return search(root, key);
	}

	void preOrder() {
		return preOrder(root);
	}

	void seqTraversal() {

	}

private:
	Node* insert(Node* node, Key key, Value value) {
		
		if (node == NULL) {
			Node* tem = new Node(key, value);
			node = tem;
			count++;
		}

		if (node->key == key) {
			node->value = value;
		}
		else if (node->key > key) {
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}

		return node;
	}

	bool contain(Node* node, Key key) {
		if (node == NULL)
			return false;
		if (node->key == key)
			return true;
		if (node->key > key)
			return contain(node->left, key, value);
		else
			return contain(node->right, key, value);
	}

	Value* search(Node* node, Key key) {
		if (node == NULL)
			return NULL;
		if (node->key == key)
			return &(node->value);
		if (node->key > key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	void preOrder(Node* node) {
		if (node == NULL)
			return;
		cout << "key:" << node->key << " value:" << value;
		preOrder(node->left);
		preOrder(node->right);
		return;
	}

	void inOrder(Node* node) {
		if (node == NULL)
			return;
		inOrder(node->left);
		cout << "key:" << node->key << " value:" << value;
		inOrder(node->right);
		return;
	}

	void postOrder(Node* node) {
		if (node == NULL)
			return;
		postOrder(node->left);
		postOrder(node->right);
		cout << node->key << value;
		return;
	}

	void seqTraversal(Node* node) {
		if (node == NULL)
			return;

		queue<Node*> nodeQueue;
		nodeQueue.push(node);
		
		while (!nodeQueue.empty()) {
			Node* tem = nodeQueue.front();
			nodeQueue.pop();
			cout << tem->key << " ";
			if (tem->left)
				nodeQueue.push(tem->left);
			if (tem->right)
				nodeQueue.push(tem->right);
		}

		cout << endl;
		return;
	}

	void destroy(Node* node) {
		if (node == NULL)
			return;
		destroy(node->left);
		destroy(node->right);
		delete node;
		count--;
	}
};