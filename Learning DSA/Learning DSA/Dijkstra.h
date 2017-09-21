#pragma once

#include "Graph.h"

class DijkstraAlgo
{
private:

	struct EdgeContainer
	{
		int key;//to store the current vertice
		int val;
		bool taken;
		int parent;
	};

	int noOfVertices, noOfEdges;
	Graph graph;
	EdgeContainer *map;
	int *set;
	int FindMin();
	void SetWeightInMap(int index, int weight, int parent);
public:
	DijkstraAlgo();
	DijkstraAlgo(int noOfVertices, int edges);
	~DijkstraAlgo();
	void InitialiseGraph(int noOfVertices, int edges);
	void CreateGraph();
	void PrintShortestPath(int start,int endVert);
	void FindAllShortestPaths(int startVert);
};