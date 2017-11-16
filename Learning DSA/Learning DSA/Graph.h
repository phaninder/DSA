#pragma once

#define MAXVERTICES 100



class Graph
{
	public :
	struct EdgeNode
	{
		int val;
		int weight;
		EdgeNode *next;
	};
private:
	struct TravellerNode
	{
		int val;
		int parent;
		int totalWeight;
		TravellerNode *next;
	};

	enum ColorCode
	{
		None = -1,
		Black = 0,
		White = 1
	};

	

	struct GraphNode
	{
		int noOfVertices;
		int noOfEdges;
		int degree[MAXVERTICES];
		EdgeNode *edgeNode[MAXVERTICES];
	};

	GraphNode graph;
	TravellerNode *traveller;
	int visited[MAXVERTICES] ;
	int parent[MAXVERTICES];
	//EdgeNode * temp;
	bool isDirected;
	ColorCode color[MAXVERTICES];
	void InsertEdge(int x, int y, int weight, bool isDirected);
	void BreadthFirstSearchHelper( int startIndex,int *parents);
	void DepthFirstSearchHelper( int startIndex);
	void CheckColor(int x, int y);
	void PrintColor();
	void TopologicalSortHelper(int startIndex);
	TravellerNode TravelHelper(int index,int verLeft,int prevWeight,int parent);
	TravellerNode helper;
	void setVerTaken();
public:	
	Graph();
	Graph(bool directed);
	~Graph();
	void Free();
	void InitialiseGraph(int vert, int edge);
	void SetEdge(int x, int y, int w);
	void SetEdge(int x, int y, int w,bool directed);
	void ReadGraph();
	void PrintGraph();
	void BreadthFirstSearch();
	void DepthFirstSearch();
	void TopologicalSort(int i);
	EdgeNode *GetChild(int index);
	void TravelingSalesman(int startIndex);
	void PrintTravell();
};
