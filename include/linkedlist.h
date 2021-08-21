#pragma once

class Node
{

public:
    int info;
    Node *next;
    Node():next(nullptr){}

};

class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void add(int, Node *);
    void addToHead(int);
    void addToTail(int);
    int traverse();
    int removeFromHead();
    int removeFromTail();
    void remove(int data);
    int search(int data);
    bool retrieve(int data, Node *&dataOutPtr);
    Node *get_head();
    Node *get_tail();

private:
    Node *HEAD;
    Node *TAIL;
};


