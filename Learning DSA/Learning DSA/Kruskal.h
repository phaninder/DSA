#pragma once
#include "DisjointSet.h"

class Kruskal
{
private:
	struct WNode
	{
		int x, y;
		int weight;
	};

	int *weights;
	int noOfEdges;
	int currentEdge;
	WNode *graph;
	DisjointSet Set;
	void SetWeights();
	void SortWeights();
public:
	Kruskal();
	Kruskal(int noOfV);
	~Kruskal();
	void InitialiseVal(int noOfV);
	void SetValToArray(int val);
	void SetValToArray(int x, int y, int val);
	void PrintWeights();
	void FormMinimumSpanTree();
	void PrintMinSpanTree();
};