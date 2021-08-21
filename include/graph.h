/* 
Implement graph data structure. Use your implementation to create some graphs, and then
perform depth-first search (DFS) and breadth-first search (BFS) on them.
Your report must contain visual representation of the graphs used in your program along with
the results of DFS and BFS traversals.
*/

#pragma once
#include "linkedlist.h"

struct Vertex{
	
	int key;
	bool marked;
	Vertex *next;
	LinkedList *neighbours;
	Vertex():next(nullptr),neighbours(new LinkedList()){}	
	Vertex(int k):key(k),marked(false),next(nullptr),neighbours(new LinkedList()){}	
	~Vertex(){
		delete neighbours;
		delete next;
	}
};

class IGraph{
	
	public:
		virtual ~IGraph(){}
		virtual void Init() = 0;
		virtual bool isEmpty() = 0;
		virtual int numVertices() = 0;
		virtual void addVertex(Vertex *newVertex) = 0;
		virtual void addEdge(Vertex *vertex1, Vertex *vertex2) = 0;
		virtual int numEdges() = 0;
		virtual void removeVertex(Vertex *vertexToRemove) = 0;
		virtual void removeEdge(Vertex *vertex1,Vertex *vertex2) = 0;
		virtual int indegree(Vertex *vertex) = 0;
		virtual int outdegree(Vertex *vertex) = 0;
		virtual int degree(Vertex *vertex) = 0;
		virtual void neighbours(Vertex *vertex) = 0;
		virtual bool neighbour(Vertex *vertex1, Vertex *vertex2) = 0;
		virtual void dfs(IGraph *g , Vertex *s) = 0;
		virtual void bfs(IGraph *g , Vertex *s) = 0;
	
};

class Graph : public IGraph{
	
	private:
		Vertex *VHEAD;
		bool isdirected; 
	public:
		~Graph();
		Graph(bool);
		void Init();
		bool isEmpty();
		int numVertices();
		void addVertex(Vertex *newVertex);
		void addEdge(Vertex *vertex1, Vertex *vertex2);
		int numEdges();
		void removeVertex(Vertex *vertexToRemove);
		void removeEdge(Vertex *vertex1, Vertex *vertex2);
		int indegree(Vertex *vertex);
		int outdegree(Vertex *vertex);
		int degree(Vertex *vertex);
		void neighbours(Vertex *vertex);
		bool neighbour(Vertex *vertex1, Vertex *vertex2);
		void dfs(IGraph *g , Vertex *s);
		void bfs(IGraph *g , Vertex *s);
		
};