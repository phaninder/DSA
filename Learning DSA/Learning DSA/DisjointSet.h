#pragma once

class DisjointSet
{
private:
	struct Node
	{
		int data;
		int rank;
		int parent;
	};
	Node *Set;
	int NoOfVertices;
public:
	DisjointSet();
	DisjointSet(int noOfEle);
	void CreateSet(int noOfEle);
	void MakeSet(int val);
	void Union(int x, int y);
	Node FindSet(Node x);
	bool HasCycle(int x,int y);
	void PrintSet();
	void PrintSet(Node *set,int noOfVert);
};