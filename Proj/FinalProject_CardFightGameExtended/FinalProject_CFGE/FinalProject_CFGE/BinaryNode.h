/*
* Jose Sandoval
* CIS-17C: C++ Programming
* December 10, 2014
* Project #2: Card Fight Game Extended
* Description: A fighting game that uses cards.
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

// System Libraries
#include <string>

using namespace std;

template <class T>
class BinaryNode
{
private:
	T element;
	BinaryNode<T>* leftChild;
	BinaryNode<T>* rightChild;
	BinaryNode<T>* parent;
public:
	BinaryNode(BinaryNode<T>*, T);
	~BinaryNode();
	void setElement(T);
	void setLeftChild(BinaryNode<T>*);
	void setRightChild(BinaryNode<T>*);
	T getElement();
	BinaryNode<T>* getLeftChild();
	BinaryNode<T>* getRightChild();
	BinaryNode<T>* getParent();
};

template <class T>
BinaryNode<T>::BinaryNode(BinaryNode<T>* parent, T element)
{
	this->parent = parent;
	this->element = element;
}

template <class T>
BinaryNode<T>::~BinaryNode()
{
}

template <class T>
void BinaryNode<T>::setElement(T element)
{
	this->element = element;
}

template <class T>
void BinaryNode<T>::setLeftChild(BinaryNode<T>* leftChild)
{
	this->leftChild = leftChild;
}

template <class T>
void BinaryNode<T>::setRightChild(BinaryNode<T>* rightChild)
{
	this->rightChild = rightChild;
}

template <class T>
T BinaryNode<T>::getElement()
{
	return element;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getLeftChild()
{
	return leftChild;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getRightChild()
{
	return rightChild;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getParent()
{
	return parent;
}

#endif // BINARYNODE_H