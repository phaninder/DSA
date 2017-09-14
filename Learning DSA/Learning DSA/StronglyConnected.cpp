#include <iostream>
#include "StronglyConnected.h"
#include "Stack.h"

using namespace std;

KosarajuAlgo::KosarajuAlgo()
{
	noOfEdges = 0;
	noOfVertices = 0;
}

KosarajuAlgo::KosarajuAlgo(int vert, int edge)
{
	noOfEdges = edge;
	noOfVertices = vert;
	visited = new int[noOfVertices];
	graph.InitialiseGraph(vert, edge);
}

void KosarajuAlgo::InitializeGraph(int vert, int edge)
{
	noOfEdges = edge;
	noOfVertices = vert;
	visited = new int[noOfVertices];
	graph.InitialiseGraph(vert, edge);
}

void KosarajuAlgo::CreateGraph()
{
	int x, y;
	cout << "Enter edges and there weights" << endl;

	for (int i = 0; i < noOfEdges; i++)
	{
		cin >> x >> y;
		graph.SetEdge(x, y, 0,true);
	}
}
Stack stackObj;
void KosarajuAlgo::DepthFirstSearch()
{
	for (int i = 0; i < noOfVertices; i++)
		visited[i] = 0;//not visited
	DepthSearchHelper(0);

	for (int i = 0; i < noOfVertices; i++)
	{
		if (visited[i] == 0)
			DepthSearchHelper(i);
	}
}

void KosarajuAlgo::DepthSearchHelper(int index)
{
	Graph::EdgeNode *tempNext, *tempCurrent = graph.GetChild(index);
	//if(temp->next!=nullptr)
	tempNext = tempCurrent;
	
	visited[index] = 1;

	while (tempNext != nullptr)
	{
		int nextIndex = tempNext->val;
		if (visited[nextIndex] == 0)
		{
			DepthSearchHelper(nextIndex);
		}
		tempNext = tempNext->next;
	}
	stackObj.Push(index);

	tempNext = nullptr;
	delete(tempNext);

	tempCurrent = nullptr;
	delete(tempCurrent);

	stackObj.Display();
}

void KosarajuAlgo::ReverseGraph()
{
	Graph tempGraph;
	Graph::EdgeNode *tempNode;
	tempGraph.InitialiseGraph(noOfVertices, noOfEdges);

	for (int i = 0; i < noOfVertices; i++)
	{
		tempNode = graph.GetChild(i);
		while (tempNode != nullptr)
		{
			tempGraph.SetEdge(tempNode->val, i, 0, true);
			tempNode = tempNode->next;
		}
	}
	graph = tempGraph;

	tempNode = nullptr;
	delete(tempNode);
	DFSTwo();
}

void KosarajuAlgo::DFSTwo()
{

	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i] = 0;
	}


	while (!stackObj.IsEmpty())
	{
		int index = stackObj.GetTop();
		if (index != -1)
		{
			stackObj.Pop();
			DepthSearchHelperTwo(index);
		}
	}

	for (int i = 0; i < noOfVertices; i++)
	{
		if (visited[i] == 0)
		{
			cout << "Visiting node:" << i << endl;
			DepthSearchHelperTwo(i);

		}
	}
}

void KosarajuAlgo::DepthSearchHelperTwo(int index)
{
	Graph::EdgeNode *tempNext, *tempCurrent = graph.GetChild(index);
	//if(temp->next!=nullptr)
	tempNext = tempCurrent;

	visited[index] = 1;

	while (tempNext != nullptr)
	{
		int nextIndex = tempNext->val;
		if (visited[nextIndex] == 0)
		{
			DepthSearchHelper(nextIndex);
		}
		tempNext = tempNext->next;
	}
	cout << "" << index << endl;

	tempNext = nullptr;
	delete(tempNext);

	tempCurrent = nullptr;
	delete(tempCurrent);
}