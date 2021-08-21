#include "..\include\graph.h"
#include <iostream>

int main()
{
	IGraph *g = new Graph(true);
	
	if(g->isEmpty())
	{
		 std::cout<<"Graph is Empty"<<std::endl;
	}
	
	else{
		std::cout<<"Graph has some vertices"<<std::endl;
	}

	//Adding Vertices

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
	
	// Adding Edges 
	
	std::cout<<"Number of Vertices:"<<g->numVertices()<<std::endl;
	
	g->addEdge(A,B);
	
	g->addEdge(B,C);
	
	g->addEdge(C,E);
	
	g->addEdge(C,D);
	
	g->addEdge(A,E);
	
	g->addEdge(A,D);
	
	g->addEdge(B,E);
	
	std::cout<<"Number of Edges:"<<g->numEdges()<<std::endl;
	
	g->removeEdge(A,B);
	
	g->removeVertex(E);
	
	std::cout<<"Number of Edges:"<<g->numEdges()<<std::endl;
	
	std::cout<<"Number of Vertices:"<<g->numVertices()<<std::endl;
	
	std::cout<<"Outdegree:"<<g->outdegree(C)<<std::endl;
	
	std::cout<<"Indegree:"<<g->indegree(D)<<std::endl;
	
	std::cout<<"Neighbours ?"<<g->neighbour(B,A)<<std::endl;
	
	g->neighbours(B);
	
	g->dfs(g,A);
	
	g->Init();
	
	g->bfs(g,A);

	delete g,A,B,C,D,E;
}
