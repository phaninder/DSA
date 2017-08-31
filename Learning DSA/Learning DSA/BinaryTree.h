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
	int height;

	Node* AddToTree(Node *ptr, int val);
	int CalHeight(Node *temp);
	
public:
	BinarySearchTree();
	Node *CreateNode(int val);
	void AddNode(int val);
	void Display();
	void FindMin();
	void FindMax();
	void FindHeight();
};
