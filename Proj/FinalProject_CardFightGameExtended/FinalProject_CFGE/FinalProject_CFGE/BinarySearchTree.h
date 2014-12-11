/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 11, 2014
* Project #2: Card Fight Game Extended
* Description: A fighting game that uses cards.
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// System Libraries
#include <string>

#include "BinaryNode.h"

using namespace std;

template <class T>
class BinarySearchTree
{
private:
	BinaryNode<T>* root;
	BinaryNode<T>* insert(BinaryNode<T>*, T);
	BinaryNode<T>* remove(BinaryNode<T>*, T);
	void traverseInOrder(BinaryNode<T>*);
	void print(BinaryNode<T>*, int);
	T findMin(BinaryNode<T>*);
	T findSibling(BinaryNode<T>*);
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(T);
	void remove(T);
	bool isEmpty();
	void traverseInOrder();
	void print();
	T findMin();
	T findSibling();
	vector<T>* getPlayers();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template <class T>
void BinarySearchTree<T>::insert(T element)
{
	if (isEmpty())
		root = new BinaryNode<T>(NULL, element);
	else
		root = insert(root, element);
}

template <class T>
void BinarySearchTree<T>::remove(T element)
{
	root = remove(root, element);
}

template <class T>
bool BinarySearchTree<T>::isEmpty()
{
	return root == NULL;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::insert(BinaryNode<T>* root, T element)
{
	// Left child case.
	if (element->getOrder() < root->getElement()->getOrder())
	{
		if (root->getLeftChild() != NULL)
			insert(root->getLeftChild(), element);
		else
			root->setLeftChild(new BinaryNode<T>(root, element));
	}

	// Right child case.
	else if (element->getOrder() > root->getElement()->getOrder())
	{
		if (root->getRightChild() != NULL)
			insert(root->getRightChild(), element);
		else
			root->setRightChild(new BinaryNode<T>(root, element));
	}

	return root;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::remove(BinaryNode<T>* root, T element)
{
	//if (root != null)
	//{
	//	int comparison = element.compareTo(root.getElement());

	//	// Left child case.
	//	if (comparison < 0)
	//		root.setLeftChild(remove(root.getLeftChild(), element));

	//	// Right child case.
	//	else if (comparison > 0)
	//		root.setRightChild(remove(root.getRightChild(), element));

	//	// Two children case.
	//	else if (root.getLeftChild() != null && root.getRightChild() != null)
	//	{
	//		root.setElement(findMin(root.getRightChild()).getElement());
	//		root.setRightChild(removeMin(root.getRightChild()));
	//	}

	//	// Node found case.
	//	else
	//	{
	//		root = (root.getLeftChild() != null)
	//			? root.getLeftChild() : root.getRightChild();
	//	}
	//}
	//else
	//	System.out.println("ERROR: Element was not found.");

	return root;
}

template <class T>
void BinarySearchTree<T>::traverseInOrder()
{
	traverseInOrder(root);
}

template <class T>
void BinarySearchTree<T>::traverseInOrder(BinaryNode<T>* root)
{
	if (root != NULL)
	{
		cout << "Name: " << root->getElement()->getCharacter()->getName() << endl;
		traverseInOrder(root->getLeftChild());
		traverseInOrder(root->getRightChild());
	}
}

template <class T>
void BinarySearchTree<T>::print()
{
	print(root, 0);
}

template<class T>
void BinarySearchTree<T>::print(BinaryNode<T>* root, int indent)
{
	if (root != NULL)
	{
		string indentation = "";

		for (int i = 0; i < indent; i++)
			indentation += " ";

		cout << indentation << root->getElement()->getCharacter()->getName() << endl;

		indent += 5;

		print(root->getLeftChild(), indent);
		print(root->getRightChild(), indent);
	}
}

template <class T>
T BinarySearchTree<T>::findMin()
{
	return NULL;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* root)
{
	if (root != NULL)
	{
		while (root->getLeftChild() != NULL)
			root = root->getLeftChild();
	}

	return root;
}

template <class T>
T BinarySearchTree<T>::findSibling()
{
	return findSibling(root);
}

template <class T>
T BinarySearchTree<T>::findSibling(BinaryNode<T>* root)
{
	if (root != NULL)
	{
		if (root->getParent()->getLeftChild == root)
			return root->getParent()->getRightChild();
		else
			return root->getParent()->getLeftChild();
	}
}

template <class T>
vector<T>* BinarySearchTree<T>::getPlayers()
{
	vector<T>* players = new vector<T>();

	players->push_back(findMin(root)->getElement());
	players->push_back(findSibling(findMin(root)->getElement());
}

#endif // BINARYSEARCHTREE_H