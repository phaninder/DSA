#include<iostream>
#include"Prism.h"

using namespace std;

Prism::Prism()
{
	noOfVertices = 0;
	noOfEdges = 0;
}

Prism::Prism(int vert, int edges)
{
	noOfEdges = edges;
	noOfVertices = vert;

	map = new EdgeContainer[noOfVertices];
}

Prism::~Prism()
{
	delete(set);
	delete(map);
}

void Prism::InitialiseGraph(int vert, int edges)
{
	noOfEdges = edges;
	noOfVertices = vert;

	set = new int[noOfVertices];
	graph.InitialiseGraph(vert, edges);
	map = new EdgeContainer[noOfVertices];
}

void Prism::CreateGraph()
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

void Prism::PrintMinSpanTree()
{
	cout << "Min spanning tree:" << endl;
	int totalWeight=0;
	for (int i = 0; i < noOfVertices; i++)
	{
		//cout << set[i] << endl;
		cout << map[set[i]].parent << "--" << set[i] << "-" << map[set[i]].val << endl;
		totalWeight += map[set[i]].val;
	}
	cout << "Total weight: " << totalWeight << endl;
}

int Prism::FindMin()
{
	int min = INT32_MAX, index=0;
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


void Prism::ApplyPrismAlgo()
{
	Graph::EdgeNode *temp = new Graph::EdgeNode;
	int currentVert=0;
	set[0] = currentVert;
	for (int i = 1; i < noOfVertices; i++)
	{
		map[currentVert].taken = true;
		temp = graph.GetChild(currentVert);
		while (temp != nullptr)
		{
			if(!map[temp->val].taken)
				SetWeightInMap(temp->val, temp->weight,currentVert);
			temp = temp->next;
		}
		currentVert = FindMin();
		set[i] = currentVert;
	}
}

void Prism::SetWeightInMap(int index, int weight,int parent)
{
	if (map[index].val > weight)
	{
		map[index].val = weight;
		map[index].parent = parent;
	}
}
