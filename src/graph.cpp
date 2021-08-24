#include "..\include\graph.h"
#include "..\include\stack.h"
#include "..\include\Queue.h"
#include<iostream>

Graph::Graph(bool value){
	
	this->VHEAD = nullptr;
	this->isdirected = value;
	
}

Graph::~Graph(){
	
	delete VHEAD;
	
}

int Graph::numVertices(){
	
	Vertex *temp = new Vertex();
	temp = this->VHEAD;
	int count = 0;
	while(temp!=NULL)
	{

		temp=temp->next;
		count++;
	}
	delete temp;
	return count;
	
}

bool Graph::isEmpty(){
	
	if(this->numVertices()==0){
		
		return true;
		
	}
	else{
	
		return false;
	
	}
	
}

void Graph::addVertex(Vertex *newVertex){
	
	newVertex->next = this->VHEAD;
	this->VHEAD = newVertex;	
}



void Graph::addEdge(Vertex *vertex1, Vertex *vertex2)
{
	
	if(!this->isdirected)
	{
		vertex1->neighbours->addToHead(vertex2->key);
		vertex2->neighbours->addToHead(vertex1->key);
	}
	
	else{
		vertex1->neighbours->addToHead(vertex2->key);
	}
	
}

void Graph::removeEdge(Vertex *vertex1, Vertex *vertex2){
	
	if(!this->isdirected)
	{
		vertex1->neighbours->remove(vertex2->key);
		vertex2->neighbours->remove(vertex1->key);
	}
	
	else{
		vertex1->neighbours->remove(vertex2->key);		
	}

}

void Graph::removeVertex(Vertex *vertexToRemove){
	
	Vertex *temp = new Vertex();
	temp = this->VHEAD;
	Node *nodeToDelete = new Node();
	
	// Remove all incoming edges to the vertex
	while(temp!=NULL)
	{	
		nodeToDelete = temp->neighbours->get_head();
		
		while(nodeToDelete!=NULL)
		{	
			if(nodeToDelete->info == vertexToRemove->key){
				nodeToDelete = NULL;
				temp->neighbours->remove(vertexToRemove->key);
			}
			else{
				nodeToDelete = nodeToDelete->next;
			}
		}
		
		temp = temp->next;
	}	
	
	delete temp;
	 
	 
	//Removes all outgoing edges from the vertexToRemove and the vertex itself
	Vertex *newtemp = new Vertex();
	newtemp = this->VHEAD;
	
	// If the vertex to be deleted is the vertex at VHEAD
	if(this->VHEAD->key == vertexToRemove->key){
		
		this->VHEAD = newtemp->next;
		newtemp->neighbours = NULL;	
		newtemp->next = NULL;
		delete newtemp;	
	}
	
	else{
		newtemp = this->VHEAD->next;
		Vertex *prev = new Vertex();
		prev = this->VHEAD;
		while(newtemp!=NULL)
		{
			nodeToDelete = newtemp->neighbours->get_head();
			if(newtemp->key == vertexToRemove->key)
			{
				while(nodeToDelete!=NULL)
				{
					newtemp->neighbours->removeFromHead();
					nodeToDelete = newtemp->neighbours->get_head();
				}
				if(nodeToDelete == NULL)
				{
					
					prev->next = newtemp->next;
					newtemp->neighbours = NULL;	
					newtemp->next = NULL;
					delete newtemp;	
				}
			}
			
			prev = newtemp;
			newtemp = newtemp->next;
		}
		delete nodeToDelete;
		delete prev;
	}
}


int Graph::numEdges(){
	
	int temp = 0;
	Vertex *vtemp = new Vertex();
	vtemp = this->VHEAD;
	
	while(vtemp!=NULL)
	{
		temp += vtemp->neighbours->traverse();
		
		vtemp = vtemp->next;
	}

	
	if(!this->isdirected)
	{
		return temp/2; 
	}
	else
	{
		return temp;
	}
	
	delete vtemp;
}

// Count all the incoming edges to the given vertex
int Graph::indegree(Vertex *vertex){
	
	int temp = 0;
	Vertex *vtemp = new Vertex();
	vtemp = this->VHEAD;
	int search_key = vertex->key;
	
	while(vtemp!=NULL)
	{
		
		temp += vtemp->neighbours->search(search_key);
		vtemp = vtemp->next;
		
		
	}
	delete vtemp;
	return temp;
		
}

// Count all the outgoing edges to the given vertex
int Graph::outdegree(Vertex *vertex){
	
	int temp = 0;
	
	temp = vertex->neighbours->traverse();
	
	return temp;
		
}

//Sum of incoming edges and outgoing edges(for directed graph)
int Graph::degree(Vertex *vertex){
	
	if(!this->isdirected){
		return (this->outdegree(vertex)+this->indegree(vertex))/2;
	}
	else{
		return (this->outdegree(vertex)+this->indegree(vertex));
	}
		
}

//Vertices that are associated with a edge of length 1
void Graph::neighbours(Vertex *vertex){
	
	Vertex * a = new Vertex();
	Node * b = new Node();
	a = this->VHEAD;
	
	while(a!=NULL){
		
		b = a->neighbours->get_head();
		while(b!=NULL){
			
			if(vertex->key == b->info)
				std::cout<<a->key<<",";
			
			else if(vertex->key == a->key)
				std::cout<<b->info<<",";

			b = b->next;	
		}
		a = a->next;
		
	}
	std::cout<<"\n";
	
	delete b,a;	
}

//Check if two vertex are neighbours or not
bool Graph::neighbour(Vertex *vertex1, Vertex *vertex2){
	
	int result_1 = vertex1->neighbours->search(vertex2->key);  
	int result_2 = vertex2->neighbours->search(vertex1->key);
	if(result_1!= 0 || result_2!=0)
	{
		return true;
	}
	else{
		return false;
	}
	
	
}

//Mark the visited vertices to false
void Graph::Init()
{
	Vertex *temp = new Vertex();
	temp = this->VHEAD;
	while(temp!=NULL)
	{
		temp->marked = false;
		temp = temp->next;	
	}
	delete temp;
	
}

// Depth First Search
void Graph::dfs(IGraph *g,Vertex *s){
	
	Vertex *u = new Vertex();
	Vertex *v = new Vertex();
	
	int *m = new int[this->numVertices()];
	IStack<Vertex *>*L = new Stack<Vertex *>(10);
	
	
	L->push(s);
	s->marked = true;
	m[0] = s->key; int i = 0;

	while(!L->isEmpty())
	{
		v = this->VHEAD;
		u = L->top();
		
		while(v!=NULL)
		{
			if(g->neighbour(u,v)) //Check if u and v are neighbours
				if(v->marked == false) //Check if v is visited 
					break;
				
			v = v->next;
		}
		
		if(v==NULL){
			L->pop();
		}
		else{
			v->marked = true;
			i++; m[i] = v->key; 
			L->push(v);
		}
		
			
	}

	//Displays all the marked vertices
	
	for(int i=0;i<this->numVertices();i++)
	{

		std::cout<<"-->"<<m[i];
		
	}
	std::cout<<"\n";

	
	delete[] m,u,v,L;
	
} 

// Breadth First Search
void Graph::bfs(IGraph *g,Vertex *s){
	
	Vertex *u = new Vertex();
	Vertex *v = new Vertex();
	
	int *m = new int[this->numVertices()];
	IQueue<Vertex *>*Q = new CircularQueue<Vertex *>(10);

	Q->enqueue(s);
	s->marked = true;
	m[0] = s->key; int i = 0;

	while(!Q->isEmpty())
	{
		v = this->VHEAD;
		u = Q->front();
		
		while(v!=NULL)
		{	
			if(g->neighbour(u,v))
				if(v->marked == false)
					break;
				
			v = v->next;
		}
		
		if(v==NULL){
			
			Q->dequeue();
		}
		else{
			v->marked = true;
			i++; m[i] = v->key;
			Q->enqueue(v);
		}
			
	}
	
	//Displays all the marked vertices 
	
	for(int i=0;i<this->numVertices();i++)
	{
		std::cout<<"-->"<<m[i];
	}
	std::cout<<"\n";
	
	delete[] m,u,v,Q;
	
} 
