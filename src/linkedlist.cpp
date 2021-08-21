#include "..\include\linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : HEAD(nullptr), TAIL(nullptr) {} //Default Constructor

LinkedList::~LinkedList()
{
    delete HEAD;
    delete TAIL;
}

bool LinkedList::isEmpty()
{
    return this->HEAD == nullptr && this->TAIL == nullptr;
}

void LinkedList::addToHead(int data)
{

    Node *newNode = new Node();
		
    newNode->next = this->HEAD;

    newNode->info = data;
	
    this->HEAD = newNode;

    if (this->TAIL == NULL)
    {
        this->TAIL = this->HEAD;
    }

}

void LinkedList::addToTail(int data)
{
    
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = nullptr;
    
    if(this->isEmpty())   //Can add to tail even if list is empty
    {
            this->TAIL=newNode;
            if(this->HEAD==NULL){
                this->HEAD=this->TAIL;
            }
    
    }
    else{

        this->TAIL->next = newNode;
        this->TAIL = this->TAIL->next;

    }
    
    
}

void LinkedList::add(int data, Node *predessecor)
{

    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = predessecor->next;
    predessecor->next = newNode;
}

int LinkedList::removeFromHead()
{

    if (!this->isEmpty())
    {
        Node *nodeToDelete = new Node();

        nodeToDelete = this->HEAD;

        int x = nodeToDelete->info;

        this->HEAD = nodeToDelete->next;

        delete nodeToDelete;

        if (this->HEAD == NULL)
        {

            this->TAIL = NULL;
        }
		 
        return x;
    }
    

    else
    {

        std::cout << "Empty..." << std::endl;
    }
}

int LinkedList::removeFromTail()
{

    if (!this->isEmpty())
    {

        Node *nodeToDelete = this->TAIL;

        int x = nodeToDelete->info;

        if (this->HEAD == this->TAIL)
        {
            this->HEAD = this->TAIL = NULL;
        }

        else
        {

            Node *predessecor = this->HEAD;
            while (predessecor->next != this->TAIL)
            {
                predessecor = predessecor->next;
            }
            this->TAIL = predessecor;
            predessecor->next = NULL;
        }

        delete nodeToDelete;

        return x;
    }

    else
    {

        std::cout << "Empty..." << std::endl;
    }
}

void LinkedList::remove(int data)   //Remove any data in the List
{

    if (!this->isEmpty())
    {
        if (this->HEAD->info == data)
        {
            
            this->removeFromHead();
        }

        else
        {
            Node *temp = this->HEAD->next;
            Node *prev = this->HEAD;
            while (temp != NULL)
            {
                if (temp->info == data)
                {

                    break;
                }

                else
                {

                    temp = temp->next;
                    prev = prev->next;
                }
            }

            if (temp != NULL)
            {

                prev->next = temp->next;
                temp->next = nullptr;
                delete temp;
                if (prev->next == NULL)
                {
                    this->TAIL = prev;
                }
            }
        }
    }

    else{

        std::cout << "Empty..." << std::endl;

    }
}

bool LinkedList::retrieve(int data, Node *&dataOutPtr)
{

    Node *temp = this->HEAD;
    while (temp != NULL && temp->info != data)
    {

        temp = temp->next;
    }

    if (temp == NULL)
    {

        return false;
    }

    else
    {

        dataOutPtr = temp;

        return true;
    }

    delete temp;
}

int LinkedList::traverse()
{

    Node *temp = this->HEAD;
	
	
	int count = 0;
    if (!this->isEmpty())
    {
        while (temp != NULL)
        {
            temp = temp->next;
			count++;
        }
       
    }

	return count;

    delete temp;
}

int LinkedList::search(int data)
{
    Node *temp = this->HEAD;
	
	int count = 0;
    while (temp != NULL && temp->info != data)
    {
		temp = temp->next;
    }

    if (temp == NULL)
    {
        return count;
    }

    else
    {
        return ++count;
    }

    delete temp;
}

Node *LinkedList::get_head() //getter to return HEAD pointer
{

    return HEAD;
}

Node *LinkedList::get_tail() //getter to return TAIL pointer
{

    return TAIL;
}
