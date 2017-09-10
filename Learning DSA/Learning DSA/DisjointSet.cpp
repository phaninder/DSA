
#include <iostream>
#include "DisjointSet.h"


DisjointSet::DisjointSet()
{
	NoOfVertices = 0;
}

DisjointSet::DisjointSet(int noOfVertices)
{
	Set = new Node[noOfVertices];
	NoOfVertices = 0;
}

void DisjointSet::CreateSet(int noOfVertices)
{
	Set = new Node[noOfVertices];
	NoOfVertices = 0;
}

// Make a set
void DisjointSet::MakeSet(int val)
{
	Node temp;
	temp.data = val;
	temp.rank = 0;
	temp.parent = val;
	Set[NoOfVertices] = temp;
	NoOfVertices++;//increase value
}

void DisjointSet::Union(int x, int y)
{
	Node temp1, temp2;
	temp1 = FindSet(Set[x]);
	temp2 = FindSet(Set[y]);
	
	//both have same parent
	if (temp1.parent == temp2.parent)
	{
		return;
	}

	if (temp1.rank > temp2.rank)
	{
		Set[temp2.data].parent = temp1.parent;
		Set[y].parent = temp1.parent;
	}
	else if (temp1.rank < temp2.rank)
	{
		Set[temp1.data].parent = temp2.parent;
		Set[x].parent = temp2.parent;
	}
	else
	{
		Set[temp1.data].rank++;
		Set[x].rank++;
		Set[temp2.data].parent = temp1.parent;
		Set[y].parent = temp1.parent;
	}


}

DisjointSet::Node DisjointSet::FindSet(Node x)
{
	if (x.parent == x.data)
		return x;
	x.parent = FindSet(Set[x.parent]).data;
	return Set[x.parent];
}

bool DisjointSet::HasCycle(int x,int y)
{
	Node temp1, temp2;
	temp1 = FindSet(Set[x]);
	temp2 = FindSet(Set[y]);

	//both have same parent
	if (temp1.parent == temp2.parent)
	{
		return true;
	}

	return false;
}

void DisjointSet::PrintSet()
{
	std::cout << "Set:" << std::endl;
	for (int i = 0; i < NoOfVertices; i++)
	{
		std::cout << Set[i].data << "-" << Set[i].parent << std::endl;
	}
}

void DisjointSet::PrintSet(Node *set, int val)
{
	std::cout << "Set:" << std::endl;
	for (int i = 0; i < val; i++)
	{
		std::cout <<set[i].data << "-" << set[i].parent << std::endl;
	}

}