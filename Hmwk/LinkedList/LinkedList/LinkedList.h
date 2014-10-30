/*
* Jose Sandoval
* CIS-17C: C++ Programming
* September 24, 2014
* Homework #4: Linked List
* Description: Extended Linked List data structure
*/

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

// Libraries
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

class LinkedList 
{
private:
	Node* head;
	Node* tail;
	Node* worker;
	int numberOfNodes;

public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator =(const LinkedList&);
	Node* getHead();
	Node* getTail();
	Node* findNode(int);
	bool isEmpty();
	int size();
	int first();
	int last();
	void purge();
	void prepend(int);
	void append(int);
	void extract(int);
	void insertBefore(const Node*, const int&);
	void insertAfter(const Node*, const int&);
	string toString();
};

#endif	//LINKEDLIST_H