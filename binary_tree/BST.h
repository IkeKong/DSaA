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

	Value* search(Key key) {
		return search(root, key);
	}

	void preOrder() {
		return preOrder(root);
	}

	void seqTraversal() {
		return seqTraversal(root);
	}

	void removeMin() {
		if (root)
			root = removeMin(root);
	}

	void removeMax() {
		if (root)
			root = removeMax(root);
	}

	void remove(Key key) {
		root = remove(root, key);
		return;
	}

	Key minimum() {
		assert(count != 0);
		Node* minNode = minimun(root);
		return minNode->key;
	}

	Key maximum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
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

	Node* minimum(Node* node) {
		if (node->left == NULL)
			return node;
		else
			return minimum(node->left);
	}

	Node* maximum(Node* node) {
		if (node->right == NULL)
			return node;
		return maximum(node->right);
	}

	Node* removeMin(Node* node) {
		if (node->left == NULL) {
			Node* rightNode = node->right;
			delete node; 
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}

	Node* removeMax(Node* node) {
		if (node->right == NULL) {
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
		}
		node->right = removeMax(node->right);
		return node;
	}

	Node* remove(Node* node, Key key) {
		if (node == NULL)
			return NULL;
		if (key < node->key) {
			node->left = remove(node->left);
			return node;
		}
		if (key > node->key) {
			node->right = remove(node->right);
			return node;
		}
		
		if (node->left && node->right) {
			Node* s = minimum(node->right);
			Node* new_s = new Node(s->key, s->value);
			count++;

			Node* right = removeMin(node->right);
			new_s->left = node->left;
			new_s->right = right;
	
			delete node;
			count--;
			return new_s;
		}
		if (node->left == NULL) {
			Node* right = node->right;
			delete node;
			count--;
			return right;
		}
		if (node->right == NULL) {
			Node* left = node->left;
			delete node;
			count--;
			return left;
		}

	}

};