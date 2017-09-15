#pragma once
#include "Graph.h"

class ArticulationPoint
{
private:
	Graph graph;
	int *visited, noOfVertices, noOfEdges;
	Graph::EdgeNode *node;
	void DepthSearchHelper(int index);
	int *upTime, *lowTime,*parent,*childCount;
	bool *isArticulationPoint;
	int time;
	void PrintArticualtionPoints();
public:
	ArticulationPoint();
	~ArticulationPoint();
	void InitializeGraph(int vert, int edge);
	void CreateGraph();
	void DepthFirstSearch();
};
