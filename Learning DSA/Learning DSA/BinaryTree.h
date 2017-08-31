#pragma once

class BinarySearchTree
{
private:
	struct Node
	{
		int data;
		Node *leftChild;
		Node *rightChild;
	};

	Node *root;
	Node* AddToTree(Node *ptr, int val);
public:
	BinarySearchTree();
	Node *CreateNode(int val);
	void AddNode(int val);
	void Display();
};
