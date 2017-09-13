#pragma once
#include "Graph.h"

class Prism
{
private:

	struct EdgeContainer
	{
		int key;//to store the current vertice
		int val;
		bool taken;
		int parent;
	};

	int noOfVertices,noOfEdges;
	Graph graph;
	EdgeContainer *map;
	int *set;
	int FindMin();
	void SetWeightInMap(int index, int weight,int parent);
public:
	Prism();
	Prism(int noOfVertices, int edges);
	~Prism();
	void InitialiseGraph(int noOfVertices, int edges);
	void CreateGraph();
	void PrintMinSpanTree();
	void ApplyPrismAlgo();
};