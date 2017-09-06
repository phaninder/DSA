#pragma once

#define MAXVERTICES 100



class Graph
{
private:
	enum ColorCode
	{
		None = -1,
		Black = 0,
		White = 1
	};

	struct EdgeNode
	{
		int val;
		int weight;
		EdgeNode *next;
	};

	struct GraphNode
	{
		int noOfVertices;
		int noOfEdges;
		int *degree;
		EdgeNode **edgeNode;
	};

	GraphNode graph;
	//EdgeNode * temp;
	bool isDirected;
	ColorCode *color;
	void InsertEdge(int x, int y, int weight, bool isDirected);
	void BreadthFirstSearchHelper(int *visited, int startIndex,int *parents);
	void DepthFirstSearchHelper(int *visited, int startIndex);
	void CheckColor(int x, int y);
	void PrintColor();
public:
	Graph();
	Graph(bool directed);
	~Graph();
	void Free();
	void ReadGraph();
	void PrintGraph();
	void BreadthFirstSearch();
	void DepthFirstSearch();
};
