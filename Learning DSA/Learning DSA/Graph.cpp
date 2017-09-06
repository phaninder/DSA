
#include <iostream>
#include "Graph.h"
#include<queue>

using namespace std;

Graph::Graph()
{
	isDirected = false;
	graph.noOfEdges = 0;
	graph.noOfVertices = 0;

	for (int i = 0; i < MAXVERTICES; i++)
	{
		graph.degree[i] = 0;
		graph.edgeNode[i] = NULL;
	}
}

Graph::Graph(bool directed)
{
	isDirected = directed;
	graph.noOfEdges = 0;
	graph.noOfVertices = 0;

	for (int i = 0; i < MAXVERTICES; i++)
	{
		graph.degree[i] = 0;
		graph.edgeNode[i] = NULL;	
		visited[i] = -1;
		parent[i] = -1;
	}
}

Graph::~Graph()
{
	/*for (int i = 0; i < graph.noOfEdges; i++)
	{
		delete(graph.edgeNode[i]);
		graph.edgeNode[i] = nullptr;
	}
	delete(graph.edgeNode);*/
}

void Graph::Free()
{
	for (int i = 0; i < graph.noOfEdges; i++)
	{
		delete(graph.edgeNode[i]);
		graph.edgeNode[i] = nullptr;
	}
	//delete(graph.edgeNode);
}

void Graph::ReadGraph()
{
	int x, y;
	int noOfVertices, noOfEdge;

	cout << "Enter no of vertices in the graph:" << endl;
	cin >> noOfVertices;
	graph.noOfVertices = noOfVertices;


	for (int i = 0; i < noOfVertices; i++)
	{
		color[i] = None;
		graph.degree[i] = 0;
	}

	cout << "Enter no of Edges in the graph:" << endl;
	cin >> noOfEdge;

	//graph.edgeNode = new EdgeNode*[noOfEdge];
	for (int i = 0; i < noOfEdge; i++)
	{
		graph.edgeNode[i] = new EdgeNode;
		graph.edgeNode[i]->val = i;
		graph.edgeNode[i]->next = nullptr;
	}

	cout << "Enter pair of Edge";
	for (int i = 0; i < noOfEdge; i++)
	{
		cin >> x;
		cin >> y;

		InsertEdge(x, y, 0, isDirected);
	}
}

void Graph::InsertEdge(int x, int y, int weight, bool directed)
{
	EdgeNode *temp = new EdgeNode;
	temp->weight = weight;
	temp->val = y;
	temp->next = graph.edgeNode[x]->next;//set the node of x array index 

	graph.edgeNode[x]->next = temp;//assign the temp node to the array list of nodes
	graph.degree[x]++;//increase degree og the node index

	if (!directed)
	{
		InsertEdge(y, x, 0, true); // pass true for directed to stop recurrsion
	}
	else
	{
		graph.noOfEdges++;
	}

	//delete(temp);
	temp = nullptr;
	delete(temp);
}

void Graph::PrintGraph()
{
	EdgeNode *temp;
	cout << "No of Vertices : " << graph.noOfVertices << endl;
	cout << "No of Edges in the graph: " << graph.noOfEdges << endl;

	for (int i = 0; i < graph.noOfVertices; i++)
	{
		temp = graph.edgeNode[i];
		cout << "No of Edges for vertices " << temp->val << " : " << graph.degree[i] << "\n" << i << "--";
		temp = temp->next;
		while (temp != NULL)
		{
			cout << temp->val;
			temp = temp->next;
		}
		cout << endl;
	}

	temp = nullptr;
	delete(temp);
}

void Graph::BreadthFirstSearch()
{
	int noOfVertices = graph.noOfVertices;

	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i] = 0;
		parent[i] = -1;
	}

	color[0] = White;
	BreadthFirstSearchHelper(0, parent);

	// Check if all the vertices have been visited
	for (int i = 0; i < noOfVertices; i++)
	{
		if (visited[i] == 0)
		{
			color[i] = White;
			BreadthFirstSearchHelper(i, parent);
		}
	}

	//print parent
	cout << "Parent" << endl;
	for (int i = 0; i < noOfVertices; i++)
	{
		cout << " " << parent[i] << endl;
	}

	//print color
	PrintColor();
}

void Graph::PrintColor()
{
	for (int i = 0; i < graph.noOfVertices; i++)
	{
		cout << "Color of " << i << ":" << color[i] << endl;
	}

}

void Graph::CheckColor(int x, int y)
{
	if (color[x] == color[y])
	{
		cout << x << " " << y << " both are of same color" << endl;
	}

	if (color[x] == White)
		color[y] = Black;
	else
	{
		color[y] = White;
	}
}

std::queue<int> queueMem;
void Graph::BreadthFirstSearchHelper(int startIndex, int *parent)
{
	queueMem.push(startIndex);
	EdgeNode *temp = new EdgeNode;// = graph.edgeNode[startIndex];

	while (!queueMem.empty())
	{
		int tempIndex = queueMem.front();
		cout << tempIndex << endl;
		//cout << " " << temp->val << endl;
		queueMem.pop();
		temp = graph.edgeNode[tempIndex];
		visited[tempIndex] = 1;
		//color[tempIndex] = White;  
		while (temp != NULL)
		{
			if (visited[temp->val] == 0)
			{
				visited[temp->val] = 1;
				parent[temp->val] = tempIndex;
				CheckColor(tempIndex, temp->val);
				//cout << " " << temp->val << endl;
				queueMem.push(temp->val);
			}
			temp = temp->next;
		}
	}
	//delete(temp);
	temp = nullptr;
	delete(temp);

}

void Graph::DepthFirstSearch()
{
	int noOfVertices = graph.noOfVertices;

	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i] = 0;
	}

	color[0] = White;
	DepthFirstSearchHelper(0);

	// Check if all the vertices have been visited
	for (int i = 0; i < noOfVertices; i++)
	{
		if (visited[i] == 0)
		{
			color[i] = White;
			DepthFirstSearchHelper(0);
		}
	}

	PrintColor();

	//delete(visited);
}

void Graph::DepthFirstSearchHelper(int startIndex)
{
	EdgeNode *temp = graph.edgeNode[startIndex];
	cout << temp->val << endl;
	visited[temp->val] = 1;
	//if(temp->next!=nullptr)
	temp = temp->next;
	while (temp != nullptr)
	{
		startIndex = temp->val;
		if (visited[startIndex] == 0)
		{
			DepthFirstSearchHelper(startIndex);
		}
		//else if(visited[startIndex]==1)
			//return;
		temp = temp->next;
	}

	temp = nullptr;
	delete(temp);

	//delete(visited);
}
