#pragma once

class BinarySearchTree
{
public :
	struct Node
	{
		int data;
		Node *leftChild;
		Node *rightChild;
	};
private:


	Node *root;
	int height;

	Node* AddToTree(Node *ptr, int val);
	int CalHeight(Node *temp);
	void LevelOrderHelper(Node* temp);
	void InorderHelper(Node *temp);
	void PreOrderHelper(Node *temp);
	void PostOrderHelper(Node*temp);
	bool BinaryTreeCheckHelper(Node *temp);//, int leftLimit, int rightLimit);
	bool IsLeftSubTreeLesser(Node *temp, int limit);
	bool IsRightSubTreeGreater(Node *temp, int limit);
	Node* DeleteNodeHelper(Node *root, int val);
public:

	BinarySearchTree();
	Node *CreateNode(int val);
	void AddNode(int val);
	void Display();
	void FindMin();
	Node*  FindMinVal(Node *temp);
	void FindMax();
	void FindHeight();
	void LevelOrderTraversal();
	void InorderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void CheckIfBinaryTree();
	void DeleteNode(int val);
};
