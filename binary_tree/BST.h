#pragma once
#include <iostream>

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
};