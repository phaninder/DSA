#include<iostream>
#include"BinaryTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	height = -1;
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

void BinarySearchTree::FindMin()
{
	Node *temp = root;

	if (temp == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}

	while (temp->leftChild != nullptr)
	{
		temp = temp->leftChild;
	}
	cout << "Min value of the tree:" << temp->data << endl;
}

void BinarySearchTree::FindMax()
{
	Node *temp = root;

	if (temp == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}

	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild;
	}
	cout << "Min value of the tree:" << temp->data << endl;
}

void BinarySearchTree::FindHeight()
{
	Node *temp = root;

	if (temp == nullptr)
	{
		cout << "Tree is empty, Height is :" <<height<< endl;
		return;
	}

	height = CalHeight(temp);
	cout << "Height of tree: " << height<< endl;
}

int BinarySearchTree::CalHeight(Node *temp)
{
	if (temp == nullptr)
		return -1;
	int leftHeight = CalHeight(temp->leftChild);
	int rightHeight = CalHeight(temp->rightChild);

	int height = (leftHeight > rightHeight) ? leftHeight : rightHeight;

	return (height + 1);
}