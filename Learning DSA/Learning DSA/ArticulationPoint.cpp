#include<iostream>
#include "ArticulationPoint.h"
#include "Stack.h"

using namespace std;

ArticulationPoint::ArticulationPoint()
{
	noOfEdges = 0;
	noOfVertices = 0;
}
ArticulationPoint::~ArticulationPoint()
{
	delete(visited);
	delete(upTime);
	delete(lowTime);
	delete(parent);
	delete(childCount);
	delete(isArticulationPoint);
}

void ArticulationPoint::InitializeGraph(int vert, int edge)
{
	noOfEdges = edge;
	noOfVertices = vert;
	visited = new int[noOfVertices];
	upTime = new int[noOfVertices];
	lowTime = new int[noOfVertices];
	parent = new int[noOfVertices];
	childCount = new int[noOfVertices];
	isArticulationPoint = new bool[noOfVertices];

	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i]=0;
		upTime[i] = 0;
		lowTime[i] = 0;
		parent[i] = -1;
		childCount[i] = 0;
		isArticulationPoint[i] = false;
	}

	time = 0;
	graph.InitialiseGraph(vert, edge);
}

void ArticulationPoint::CreateGraph()
{
	int x, y;
	cout << "Enter edges and there weights" << endl;

	for (int i = 0; i < noOfEdges; i++)
	{
		cin >> x >> y;
		graph.SetEdge(x, y, 0, false);
	}
}

void ArticulationPoint::DepthFirstSearch()
{
	for (int i = 0; i < noOfVertices; i++)
		visited[i] = 0;//not visited
	DepthSearchHelper(0);

	for (int i = 0; i < noOfVertices; i++)
	{
		if (visited[i] == 0)
			DepthSearchHelper(i);
	}

	PrintArticualtionPoints();
}

void ArticulationPoint::DepthSearchHelper(int index)
{
	Graph::EdgeNode *tempNext, *tempCurrent = graph.GetChild(index);
	//if(temp->next!=nullptr)
	tempNext = tempCurrent;

	visited[index] = 1;

	upTime[index] = time;
	lowTime[index] = time;

	while (tempNext != nullptr)
	{
		int nextIndex = tempNext->val;
		if (visited[nextIndex] == 0)
		{
			//increase child count for index
			childCount[index]++;
			parent[nextIndex] = index;//set the parent of next index
			//Increase timer
			time++;
			DepthSearchHelper(nextIndex);
		}
		else
		{
			if (parent[index] != nextIndex)
			{
				if (lowTime[nextIndex] < lowTime[index])
					lowTime[index] = lowTime[nextIndex];
			}
		}
		tempNext = tempNext->next;
	}

	//gothrough adj vert again
	tempNext = tempCurrent;
	while (tempNext != nullptr)
	{
		int nextIndex = tempNext->val;
		if (upTime[index] <= lowTime[nextIndex])
		{
			isArticulationPoint[index] = true;
		}
		tempNext = tempNext->next;
	}	

	tempNext = nullptr;
	delete(tempNext);

	tempCurrent = nullptr;
	delete(tempCurrent);	
}

void ArticulationPoint::PrintArticualtionPoints()
{
	cout << "Articulation points are:" << endl;
	for (int i = 0; i < noOfVertices; i++) 
	{
		if ((parent[i] == -1 && childCount[i] >= 2) || (parent[i] != -1 && isArticulationPoint[i]))
		{
			cout << i << endl;
		}
	}
}