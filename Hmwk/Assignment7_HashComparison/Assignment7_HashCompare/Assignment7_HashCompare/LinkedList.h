/*
* Jose Sandoval
* CIS-17C: C++ Programming
* October 7, 2014
* Assignment #5: Extended Linked List
* Description: Linked List data structure with added functions.
*/

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

// Libraries
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* worker;
	int numberOfNodes;

public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	Node<T>* getHead();
	Node<T>* getTail();
	Node<T>* findNode(T);
	bool isEmpty();
	int size();
	T first();
	T last();
	bool contains(T);
	void purge();
	void prepend(T);
	void append(T);
	void extract(T);
	void insertBefore(const Node<T>*, const T&);
	void insertAfter(const Node<T>*, const T&);
	void toString();
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	purge();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	head = NULL;
	tail = NULL;

	for (worker = other.head; worker != NULL; worker = worker->getNextNode())
		append(worker->getData());
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (&other != this)
	{
		purge();
		for (worker = other.head; worker != NULL; worker = worker->getNextNode())
			append(worker->getData());
	}

	return *this;
}

template <class T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}

template <class T>
Node<T>* LinkedList<T>::getTail()
{
	return tail;
}

template <class T>
Node<T>* LinkedList<T>::findNode(T data)
{
	worker = head;

	while (worker != NULL && worker->getData() != data)
		worker = worker->getNextNode();

	if (worker == NULL)
		return NULL;

	return worker;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}

template <class T>
int LinkedList<T>::size()
{
	return numberOfNodes;
}

template <class T>
T LinkedList<T>::first()
{
	if (head == NULL)
	{
		cout << "The list is empty!" << endl;
		return NULL;
	}
	else
		return head->getData();
}

template <class T>
T LinkedList<T>::last()
{
	if (tail == NULL)
	{
		cout << "The list is empty!" << endl;
		return NULL;
	}
	else
		return tail->getData();
}

template <class T>
bool LinkedList<T>::contains(T data)
{
	if (findNode(data) == NULL)
		return false;
	else
		return true;
}

template <class T>
void LinkedList<T>::purge()
{
	if (head != NULL)
	{
		worker = head;
		head = head->getNextNode();
		delete worker;
		numberOfNodes--;
	}

	tail = NULL;
}

template <class T>
void LinkedList<T>::prepend(T data)
{
	Node<T>* link = new Node<T>(data);

	if (head == NULL)
		tail = link;

	link->setNextNode(head);
	head = link;

	numberOfNodes++;
}

template <class T>
void LinkedList<T>::append(T data)
{
	Node<T>* link = new Node<T>(data);

	if (head == NULL)
		head = link;
	else
		tail->setNextNode(link);

	tail = link;

	numberOfNodes++;
}

template <class T>
void LinkedList<T>::extract(T data)
{
	Node<T>* link = head;
	Node<T>* previousLink = NULL;

	while (link != NULL && link->getData() != data)
	{
		previousLink = link;
		link = link->getNextNode();
	}

	if (link == NULL)
		cout << "Item not found" << endl;
	else
	{
		if (link == head)
			head = link->getNextNode();
		else
			previousLink->setNextNode(link->getNextNode());

		if (link == tail)
			tail = previousLink;

		delete link;

		numberOfNodes--;
	}
}

template <class T>
void LinkedList<T>::insertBefore(const Node<T>* node, const T& data)
{
	worker = const_cast<Node<T>*>(node);

	if (worker != NULL)
	{
		Node<T>* temporary = new Node<T>(data);
		if (head == worker)
		{
			temporary->setNextNode(head);
			head = temporary;
		}
		else
		{
			Node<T>* previousNode = head;

			while (previousNode != NULL && previousNode->getNextNode() != worker)
				previousNode = previousNode->getNextNode();

			temporary->setNextNode(worker);
			previousNode->setNextNode(temporary);
			numberOfNodes++;
		}
	}
	else
		cout << "Invalid position!" << endl;
}

template <class T>
void LinkedList<T>::insertAfter(const Node<T>* node, const T& data)
{
	worker = const_cast<Node<T>*>(node);

	if (worker != NULL)
	{
		Node<T>* temporary = new Node<T>(data);
		temporary->setNextNode(worker->getNextNode());
		worker->setNextNode(temporary);
		if (tail == worker)
		{
			tail = temporary;
		}

		numberOfNodes++;
	}
	else
		cout << "Invalid position!" << endl;
}

template <class T>
void LinkedList<T>::toString()
{
	int elementNumber = 0;

	if (head)
	{
		worker = head;
		elementNumber++;
		do
		{
			cout << "Element #" << elementNumber << ": "
				<< worker->getData() << "\n";
			elementNumber++;
		} while (worker = worker->getNextNode());
	}

	elementNumber = 0;
}

#endif	//LINKEDLIST_H