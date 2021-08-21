//Stack Header File
#include <iostream>

template <typename T>
class IStack	
{

public:
	virtual ~IStack() {}
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual T top() = 0;
};

//Generic Class Stack
template <typename T>
class Stack : public IStack<T>
{

public:
	~Stack();
	Stack(int);
	virtual bool isEmpty();
	virtual bool isFull();
	virtual void push(T);
	virtual T pop();
	virtual T top();

private:
	T *Array;	//Array to store stacked elements
	int index;
	int MaxStackSize;
};

template <typename T>
Stack<T>::~Stack()
{
	delete Array;
}

template <typename T>
Stack<T>::Stack(int MaxStackSize) : MaxStackSize(MaxStackSize), Array(new T[MaxStackSize]), index(0) {}//Parameterized Constructor

template <typename T>
void Stack<T>::push(T element)
{

	if (!this->isFull())
	{

		this->Array[this->index++] = element;
	}

	else
	{
		std::cout << "Stack is Full" << std::endl;
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{

	if (this->index == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

template <typename T>
T Stack<T>::pop()
{

	if (this->isEmpty())
	{

		std::cout << "Empty Stack" << std::endl;
	}
	else
	{

		T element = this->Array[--this->index];
		return element;
	}
}

template <typename T>
bool Stack<T>::isFull()
{

	if (this->index == this->MaxStackSize)
	{
		return true;
	}

	else
	{
		return false;
	}
}

template <typename T>
T Stack<T>::top()
{
	T element;
	if (this->isEmpty())
	{
		std::cout << "Empty Stack" << std::endl;
	}

	else
	{
		element = this->Array[--this->index];
		this->index++;
	}
	return element;
}
