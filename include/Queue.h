#pragma once
#include <iostream>
using namespace std;

template <typename Q>
class IQueue
{

public:
  virtual ~IQueue() {}
  virtual void enqueue(Q) = 0;
  virtual Q dequeue() = 0;
  virtual Q front() = 0;
  virtual Q back() = 0;
  virtual bool isEmpty() = 0;
  virtual bool isFull() = 0;
};

template <typename Q>
class CircularQueue : public IQueue<Q>
{

public:
  ~CircularQueue() { delete q; }
  CircularQueue() : q(new Q[MAXINDEXSIZE]), f(-1), r(-1), MAXINDEXSIZE(10) {}
  CircularQueue(int MAXINDEXSIZE):q(new Q[MAXINDEXSIZE]), f(-1), r(-1),MAXINDEXSIZE(MAXINDEXSIZE){}
  virtual void enqueue(Q);
  virtual Q dequeue();
  virtual Q front();
  virtual Q back();
  virtual bool isEmpty();
  virtual bool isFull();

private:
  int MAXINDEXSIZE;
  int f, r;
  Q *q;
};

template <typename Q>
void CircularQueue<Q>::enqueue(Q element)
{

  if (!this->isFull())
  {
	if( this->f ==-1 )
	{
		this->f = 0;
	}
	this->r = (this->r + 1) % this->MAXINDEXSIZE;
    q[this->r] = element;
	
  }

  else
  {

    cout << "Queue OverFlow" << endl;
  }
}

template <typename Q>
Q CircularQueue<Q>::dequeue()
{

  if (!this->isEmpty())
  { 
	Q result;
	if(this->f == this->r){
		result = this->q[this->f];
		this->f=this->r=-1;
		
	}
	else{
		result = this->q[this->f];
		this->f = (this->f + 1) % this->MAXINDEXSIZE;
	
	}
	return result;
  }

  else
  {

    cout << "Queue UnderFlow" << endl;
  }
}

template <typename Q>
bool CircularQueue<Q>::isEmpty()
{

  if (this->r == -1 && this->f == -1)
  {

    return true;
  }

  else
  {

    return false;
  }
}

template <typename Q>
bool CircularQueue<Q>::isFull()
{

  if (this->f == (this->r + 1) % this->MAXINDEXSIZE)
  {
    return true;
  }

  else
  {

    return false;
  }
}

template <typename Q>
Q CircularQueue<Q>::front()
{

  return this->q[this->f];
}

template <typename Q>
Q CircularQueue<Q>::back()
{

  return this->q[this->r];
}