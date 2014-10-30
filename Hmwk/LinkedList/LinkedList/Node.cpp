#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

Node::~Node()
{

}

void Node::setData(int data)
{
	this->data = data;
}

int Node::getData()
{
	return data;
}

void Node::setNextNode(Node* next)
{
	this->next = next;
}

Node* Node::getNextNode()
{
	return next;
}
