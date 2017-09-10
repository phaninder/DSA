#include<iostream>
#include "Kruskal.h"
#include "Sort.h"

using namespace std;

Kruskal::Kruskal()
{
	noOfEdges = 0;
	currentEdge = 0;
	graph = nullptr;
}

Kruskal::Kruskal(int val)
{
	noOfEdges = val;
	weights = new int[noOfEdges];
	currentEdge = 0;
	graph = new WNode[noOfEdges];
	//initialise disjoint set
	Set.CreateSet(noOfEdges);
}
Kruskal::~Kruskal()
{
	delete(weights);
	delete(graph);
}

void Kruskal::InitialiseVal(int noOfV)
{
	noOfEdges= noOfV;
	weights = new int[noOfEdges];
	currentEdge = 0;
	graph = new WNode[noOfEdges];
	//initialise disjoint set
	Set.CreateSet(noOfEdges);
	for (int i = 0; i < noOfEdges; i++)
	{
		graph[i].x = -1;
		graph[i].y = -1;
		graph[i].weight = -1;
		Set.MakeSet(i);//make individual sets
	}
}
void Kruskal::SetValToArray(int x,int y,int val)
{
	graph[currentEdge].x = x;
	graph[currentEdge].y = y;
	graph[currentEdge].weight = val;
	weights[currentEdge] = val;
	currentEdge++;
}


void Kruskal::SetValToArray(int val)
{
	weights[currentEdge] = val;
	currentEdge++;
}

void Kruskal::SortWeights()
{
	Sort sortAl;
	sortAl.MergeSort(weights, noOfEdges);
}

void Kruskal::SetWeights()
{
	int *temp= new int[noOfEdges];
	int i = 0;
	while (i < noOfEdges)
	{
		temp[i] = -1;
		i++;
	}
	WNode *tempGraph = new WNode[noOfEdges];

	for (i = 0; i < noOfEdges; i++)
	{
		for (int j = 0; j < noOfEdges; j++)
		{
			if (graph[i].weight == weights[j] && temp[j]==-1)
			{
				tempGraph[j].x = graph[i].x;
				tempGraph[j].y = graph[i].y;
				tempGraph[j].weight = graph[i].weight;
				temp[j] = 0;
			}
		}
	}
	//reallocate array
	delete(graph);
	graph = nullptr;

	graph = tempGraph;
	tempGraph = nullptr;

	delete(tempGraph);
	temp = nullptr;
	delete(temp);
}

void Kruskal::PrintWeights()
{
	for (int i = 0; i < currentEdge; i++)
	{
		cout << "" << weights[i] << endl;
	}
}

void Kruskal::FormMinimumSpanTree()
{
	//First Sort weights 
	SortWeights();
	//Then set weights in current graph in increasing order
	SetWeights();
	int x, y;
	for (int i = 0; i < currentEdge; i++)
	{
		x = graph[i].x;
		y = graph[i].y;
		if (Set.HasCycle(x, y))
		{
			//cout << "Adding Edge from : " << x << " and " << y << " forms a cycle in graph" << endl;
		}
		else
		{
			cout << "Adding Edge from : " << x << " and " << y << " to graph" << endl;
			Set.Union(x, y);
		}
	}
}

void Kruskal::PrintMinSpanTree()
{
	Set.PrintSet();
}