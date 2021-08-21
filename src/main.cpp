#include "..\include\graph.h"
#include <iostream>

int main()
{
	
	IGraph *g = new Graph(false); //undirected Graph, if false then directed graph is made

	//Add Vertices

	Vertex *A = new Vertex(10);

	g->addVertex(A);
	
	Vertex *B = new Vertex(11);
	
	g->addVertex(B);
	
	Vertex *C = new Vertex(18);
	
	g->addVertex(C);
	
	Vertex *D = new Vertex(15);
	
	g->addVertex(D);
	
	Vertex *E = new Vertex(20);
	
	g->addVertex(E);
	
	// Add Edges 
	
	std::cout<<"Number of Vertices = "<<g->numVertices()<<std::endl;
	
	g->addEdge(A,B);
	
	g->addEdge(B,C);
	
	g->addEdge(C,E);
	
	g->addEdge(C,D);
	
	//g->removeEdge(A,B);
	
	g->addEdge(A,E);
	
	g->addEdge(A,D);
	
	g->addEdge(B,E);
	
	//g->neighbours(A);
	
	//g->removeVertex(E);
	
	//std::cout<<"Are A and B neighbours? ";g->neighbour(A,B)?std::cout<<"Yes"<<std::endl:std::cout<<"No"<<std::endl;
	
	std::cout<<"Number of Edges = "<<g->numEdges()<<std::endl;

	
	std::cout<<"Depth First Search starting from 10 = ";g->dfs(g,A);
	
	g->Init();
	
	std::cout<<"Breadth First Search starting from 10 = ";g->bfs(g,A);

	delete g,A,B,C,D,E;
	
	// Graph 2(Please comment out one before you run another)
	/*
	IGraph *g = new Graph(true); //undirected Graph, if false then directed graph is made

	//Add Vertices

	Vertex *A = new Vertex(10);

	g->addVertex(A);
	
	Vertex *B = new Vertex(11);
	
	g->addVertex(B);
	
	Vertex *C = new Vertex(18);
	
	g->addVertex(C);
	
	Vertex *D = new Vertex(15);
	
	g->addVertex(D);
	
	Vertex *E = new Vertex(20);
	
	g->addVertex(E);
	
	Vertex *F = new Vertex(35);
	
	g->addVertex(F);
	
	// Add Edges 
	
	std::cout<<"Number of Vertices = "<<g->numVertices()<<std::endl;
	
	g->addEdge(A,B);
	
	g->addEdge(A,D);
	
	g->addEdge(B,D);
	
	g->addEdge(B,E);
	
	g->addEdge(B,F);
	
	g->addEdge(C,A);
	
	g->addEdge(C,B);
	
	g->addEdge(C,D);
	
	g->addEdge(D,F);
	
	g->addEdge(E,D);
	
	g->addEdge(F,E);
	
	std::cout<<"Number of Edges = "<<g->numEdges()<<std::endl;
	
	std::cout<<"Depth First Search starting from 35 = ";g->dfs(g,F);
	
	g->Init();
	
	std::cout<<"Breadth First Search starting from 35 = ";g->bfs(g,F);

	delete g,A,B,C,D,E,F;
	*/

}
