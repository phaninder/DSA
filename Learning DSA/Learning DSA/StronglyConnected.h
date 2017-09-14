#pragma once

#include "Graph.h"

class KosarajuAlgo
{
private:
	Graph graph;
	int *visited,noOfVertices,noOfEdges;
	Graph::EdgeNode *node;
	void DepthSearchHelper(int index);
public:
	KosarajuAlgo();
	KosarajuAlgo(int vert,int edge);
	void InitializeGraph(int vert, int edge);
	void CreateGraph();
	void DepthFirstSearch();
	void ReverseGraph();
	void DFSTwo();
};