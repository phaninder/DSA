#include<iostream>
#include"Dijkstra.h"
#include "Stack.h"

using namespace std;

DijkstraAlgo::DijkstraAlgo()
{
	noOfVertices = 0;
	noOfEdges = 0;
}

DijkstraAlgo::DijkstraAlgo(int vert, int edges)
{
	noOfEdges = edges;
	noOfVertices = vert;

	map = new EdgeContainer[noOfVertices];
}

DijkstraAlgo::~DijkstraAlgo()
{
	delete(set);
	delete(map);
}

void DijkstraAlgo::InitialiseGraph(int vert, int edges)
{
	noOfEdges = edges;
	noOfVertices = vert;

	set = new int[noOfVertices];
	graph.InitialiseGraph(vert, edges);
	map = new EdgeContainer[noOfVertices];
}

void DijkstraAlgo::CreateGraph()
{
	int x, y, weight;
	cout << "Enter edges and there weights" << endl;

	for (int i = 0; i < noOfEdges; i++)
	{
		cin >> x >> y >> weight;
		graph.SetEdge(x, y, weight);
	}

	for (int i = 0; i < noOfVertices; i++)
	{
		map[i].key = i;
		map[i].parent = -1;
		map[i].taken = false;
		map[i].val = INT32_MAX;
	}
	map[0].val = 0;
	map[0].parent = 0;
}


void DijkstraAlgo::PrintShortestPath(int startVert,int endVert)
{
	Stack path;
	cout << "Shortest path to : "<<endVert<<" from start vert" << endl;
	path.Push(endVert);
	
	int parent = map[endVert].parent;
	while (parent != startVert)
	{
		path.Push(parent);
		parent = map[parent].parent;
	}
	path.Push(startVert);
	path.Display();
	//cout << "Total weight: " << totalWeight << endl;
}

int DijkstraAlgo::FindMin()
{
	int min = INT32_MAX, index = -1;
	for (int i = 0; i < noOfVertices; i++)
	{
		if (!map[i].taken && map[i].val < min)
		{
			min = map[i].val;
			index = i;
		}
	}
	return index;
}


void DijkstraAlgo::FindAllShortestPaths(int startVert)
{
	Graph::EdgeNode *temp = new Graph::EdgeNode;
	int currentVert = startVert;
	set[0] = currentVert;
	for (int i = 1; i < noOfVertices; i++)
	{
		map[currentVert].taken = true;
		temp = graph.GetChild(currentVert);
		while (temp != nullptr)
		{
			if (!map[temp->val].taken)
			{
				SetWeightInMap(temp->val, temp->weight, currentVert);
			}
			temp = temp->next;
		}
		int min = FindMin();

		if (min != -1)
		{
			currentVert = min;
			set[i] = currentVert;
		}
		else
		{
			currentVert = i;
		}
	}
}

void DijkstraAlgo::SetWeightInMap(int index, int weight, int parent)
{
	int totalWeight = (map[parent].val + weight);

	if (map[index].val > totalWeight)
	{
		map[index].val = totalWeight;
		map[index].parent = parent;
	}
}
