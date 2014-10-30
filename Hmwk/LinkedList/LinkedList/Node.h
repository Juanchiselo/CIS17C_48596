/*
* Jose Sandoval
* CIS-17C: C++ Programming
* October 1st, 2014
* Homework #5: Linked List Extended
* Description: Linked list data structure with added functions.
*/

#ifndef NODE_H
#define	NODE_H

class Node
{
private:
	int data;
	Node* next;

public:
	Node(int);
	~Node();
	void setData(int);
	int getData();
	void setNextNode(Node* next);
	Node* getNextNode();
};

#endif //NODE_H


