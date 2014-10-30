#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList()
{
	purge();
}

LinkedList::LinkedList(const LinkedList& other)
{
	head = NULL;
	tail = NULL;

	for (worker = other.head; worker != NULL; worker = worker->getNextNode())
		append(worker->getData());
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (&other != this)
	{
		purge();
		for (worker = other.head; worker != NULL; worker = worker->getNextNode())
			append(worker->getData());
	}

	return *this;
}

Node* LinkedList::getHead()
{
	return head;
}

Node* LinkedList::getTail()
{
	return tail;
}

Node* LinkedList::findNode(int data)
{
	Node* worker = head;

	while (worker != NULL && worker->getData() != data)
		worker = worker->getNextNode();

	if (worker == NULL)
	{
		cout << "Item not found!" << endl;
		return NULL;
	}
	
	return worker;
}

bool LinkedList::isEmpty()
{
	return head == NULL;
}

int LinkedList::size()
{
	return numberOfNodes;
}

int LinkedList::first()
{
	if (head == NULL)
	{
		cout << "The list is empty!" << endl;
		return NULL;
	}
	else
		return head->getData();
}

int LinkedList::last()
{
	if (tail == NULL)
	{
		cout << "The list is empty!" << endl;
		return NULL;
	}
	else
		return tail->getData();
}

void LinkedList::purge()
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

void LinkedList::prepend(int data)
{
	Node* link = new Node(data);

	if (head == NULL)
		tail = link;

	link->setNextNode(head);
	head = link;

	numberOfNodes++;
}

void LinkedList::append(int data)
{
	Node* link = new Node(data);

	if (head == NULL)
		head = link;
	else
		tail->setNextNode(link);
		
	tail = link;

	numberOfNodes++;
}

void LinkedList::extract(int data)
{
	Node* link = head;
	Node* previousLink = NULL;

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

void LinkedList::insertBefore(const Node* node, const int& data)
{
	worker = const_cast<Node*>(node);
	
	if (worker != NULL)
	{
		Node* temporary = new Node(data);
		if (head == worker)
		{
			temporary->setNextNode(head);
			head = temporary;
		}
		else
		{
			Node* previousNode = head;

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

void LinkedList::insertAfter(const Node* node, const int& data)
{
	worker = const_cast<Node*>(node);

	if (worker != NULL)
	{
		Node* temporary = new Node(data);
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

string LinkedList::toString()
{
	string output = "";
	int elementNumber = 0;

	if (head)
	{
		worker = head;
		elementNumber++;
		do
		{
			output += "Element #" + to_string(elementNumber) + ": ";
			output += to_string(worker->getData()) + "\n";
			elementNumber++;
		} while (worker = worker->getNextNode());
	}

	elementNumber = 0;
	return output;
}
