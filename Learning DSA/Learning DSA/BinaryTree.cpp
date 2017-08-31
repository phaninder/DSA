#include<iostream>
#include"BinaryTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::Node* BinarySearchTree::CreateNode(int val)
{
	Node *temp = new Node();
	temp->data = val;
	temp->leftChild = nullptr;
	temp->rightChild = nullptr;
	return temp;
}

void BinarySearchTree::AddNode(int val)
{
	root = AddToTree(root, val);
}

BinarySearchTree::Node* BinarySearchTree::AddToTree(Node* temp, int val)
{
	if (temp == nullptr)
	{
		temp = CreateNode(val);
		return temp;
	}

	if (val <= temp->data)
	{
		temp->leftChild = AddToTree(temp->leftChild, val);
	}
	else
	{
		temp->rightChild = AddToTree(temp->rightChild, val);
	}

	return temp;
}

void BinarySearchTree::Display()
{
	Node *temp = root;
	cout << temp->data;
	//while (temp != nullptr)
	//{
	//	cout << "Value at the node: " << temp->data << endl;
	//	temp = temp->leftChild;
	//}
}