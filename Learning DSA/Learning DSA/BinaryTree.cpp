#include<iostream>
#include"BinaryTree.h"
#include <queue>

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

queue<BinarySearchTree::Node *>nodeQueue;
void BinarySearchTree::LevelOrderTraversal()
{
	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	nodeQueue = queue<BinarySearchTree::Node*>();
	nodeQueue.push(root);
	LevelOrderHelper(root);

}


void BinarySearchTree::LevelOrderHelper(Node* temp1)
{
	/*if (temp == nullptr)
	{
		return;
	}*/
	//queue<Node*> nodeQueue;
	
	if (!nodeQueue.empty())
	{
		Node *next = nodeQueue.front();
		cout << " " << next->data;
		if (next->leftChild != nullptr)
			nodeQueue.push(next->leftChild);
		if (next->rightChild != nullptr)
			nodeQueue.push(next->rightChild);
		nodeQueue.pop();
		LevelOrderHelper(next);
	}
	else
	{
		return;
	}
}

void BinarySearchTree::InorderTraversal()
{
	InorderHelper(root);
}

void BinarySearchTree::InorderHelper(Node *temp)
{
	if (temp == nullptr)
		return;
	InorderHelper(temp->leftChild);
	cout << " " << temp->data;
	InorderHelper(temp->rightChild);
}

void BinarySearchTree::PreOrderTraversal()
{
	PreOrderHelper(root);
}

void BinarySearchTree::PreOrderHelper(Node *temp)
{
	if (temp == nullptr)
		return;
	cout << " " << temp->data;
	PreOrderHelper(temp->leftChild);
	PreOrderHelper(temp->rightChild);
}

void BinarySearchTree::PostOrderTraversal()
{
	PostOrderHelper(root);
}

void BinarySearchTree::PostOrderHelper(Node *temp)
{
	if (temp == nullptr)
		return;
	PostOrderHelper(temp->leftChild);
	PostOrderHelper(temp->rightChild);
	cout << " " << temp->data;
}

void BinarySearchTree::CheckIfBinaryTree()
{
	int leftLimit = INT32_MIN;
	int rightLimit = INT32_MAX;
	cout << "Binary tree validity : " << BinaryTreeCheckHelper(root);
}

bool BinarySearchTree::BinaryTreeCheckHelper(Node *temp)
{
	if (temp == nullptr)
		return true;
	
	if ((temp->leftChild, temp->data) && (temp->rightChild, temp->data) && BinaryTreeCheckHelper(temp->leftChild)
		&& BinaryTreeCheckHelper(temp->rightChild))
	{
		return true;
	}
	else
		return false;
}

bool BinarySearchTree::IsLeftSubTreeLesser(Node *temp, int limit)
{
	if (temp == nullptr)
		return true;
	if (temp->data <= limit)
		return true;
	else
		return false;
}

bool BinarySearchTree::IsRightSubTreeGreater(Node *temp, int limit)
{
	if (temp == nullptr)
		return true;
	if (temp->data > limit)
		return true;
	else
		return false;
}
void BinarySearchTree::DeleteNode( int val)
{
	root = DeleteNodeHelper(root, val);
}

BinarySearchTree::Node* BinarySearchTree::DeleteNodeHelper(Node *temp, int val)
{
	if (temp == nullptr)
	{
		cout << "Didn't found element" << endl;
		return nullptr;
	}

	if (temp->data > val)
		temp->leftChild = DeleteNodeHelper(temp->leftChild, val);
	else if (temp->data < val)
		temp->rightChild = DeleteNodeHelper(temp->rightChild, val);
	else
	{
		if (temp->leftChild == nullptr && temp->rightChild == nullptr)
		{
			delete(temp);
			temp = nullptr;
			return temp;
		}
		else if (temp->leftChild != nullptr && temp->rightChild == nullptr)
		{
			Node *temp2 = temp;
			temp = temp->leftChild;
			delete(temp2);
			temp2 = nullptr;
			return temp;
		}
		else if (temp->leftChild == nullptr && temp->rightChild != nullptr)
		{
			Node *temp2 = temp;
			temp = temp->rightChild;
			delete(temp2);
			temp2 = nullptr;
			return temp;
		}
		else if (temp->leftChild != nullptr && temp->rightChild != nullptr)
		{
			Node *min = FindMinVal(temp->rightChild);
			temp->data = min->data;
			temp->rightChild = DeleteNodeHelper(temp->rightChild, min->data);
			return temp;
		}
	}
	return temp;
}

BinarySearchTree::Node * BinarySearchTree::FindMinVal(Node *temp)
{
	if (temp == nullptr)
	{
		cout << "Tree is empty" << endl;
		return nullptr;
	}

	while (temp->leftChild != nullptr)
	{
		temp = temp->leftChild;
	}
	return temp;
}