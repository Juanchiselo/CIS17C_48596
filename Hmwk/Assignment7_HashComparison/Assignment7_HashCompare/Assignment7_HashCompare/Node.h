/*
* Jose Sandoval
* CIS-17C: C++ Programming
* October 7, 2014
* Assignment #5: Extended Linked List
* Description: Linked list data structure with added functions.
*/

#ifndef NODE_H
#define	NODE_H

template <class T>
class Node
{
private:
	T data;
	Node* next;

public:
	Node(T);
	~Node();
	void setData(T);
	T getData();
	void setNextNode(Node* next);
	Node* getNextNode();
};

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next = nullptr;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
void Node<T>::setData(T data)
{
	this->data = data;
}

template <class T>
T Node<T>::getData()
{
	return data;
}

template <class T>
void Node<T>::setNextNode(Node<T>* next)
{
	this->next = next;
}

template <class T>
Node<T>* Node<T>::getNextNode()
{
	return next;
}

#endif //NODE_H


