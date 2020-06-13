#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
BinarySearchTree::BinarySearchTree()
{
	root = 0;
}


BinarySearchTree::~BinarySearchTree()
{
}


void BinarySearchTree::printTree()
{
	cout << "printing tree..." << endl;
	printTreeHelper(root, 0);
	cout << endl << endl;
}

void BinarySearchTree::printTreeHelper(BSTNode * rootNode, int printOffset)
{
	if (rootNode == 0)
		return;
	
	printOffset += 5;

	printTreeHelper(rootNode->right, printOffset);
	
	cout << endl;
	for (int i = 0; i < printOffset; i++) cout << " ";
	cout << rootNode->value;

	printTreeHelper(rootNode->left, printOffset);
}
int BinarySearchTree::addNode(int val)
{
	BSTNode * newNode = new BSTNode;
	newNode->value = val;
	newNode->left = 0;
	newNode->right = 0;

	addNodeHelper(&root, newNode);
	return 1;
}

int BinarySearchTree::addNodeHelper(BSTNode **  rootNode, BSTNode * newNode)
{
	if (*rootNode == 0)
	{
		*rootNode = newNode;
		return 1;
	}
	else if ((*rootNode)->value > newNode->value)
	{
		if ((*rootNode)->left == 0) (*rootNode)->left = newNode;
		else addNodeHelper(&((*rootNode)->left), newNode);
	}
	else
	{
		if ((*rootNode)->right == 0) (*rootNode)->right = newNode;
		else addNodeHelper(&((*rootNode)->right), newNode);
	}
	return 0;
}

int BinarySearchTree::removeNode(int value)
{
	removeNodeHelper(root, value);
	return 0;
}
void BinarySearchTree::removeNodeHelper(BSTNode * rootNode, int value)
{

	if (rootNode == 0) return;
	if (rootNode->value == value)
	{
		BSTNode * removed = findInorderSuccessor(rootNode);
		delete removed;
	}
	else if (rootNode->value > value)
	{
		removeNodeHelper(rootNode->left, value);
	}
	else
	{
		removeNodeHelper(rootNode->right, value);
	}
	/*
	if (rootNode == 0) return;
	if (rootNode->value == value)
	{
		if (rootNode->right != 0)
		{

			root = rootNode->right;
		}
		else if (rootNode->left != 0) root = rootNode->left;
		else root = 0;
		delete rootNode;
	}
	else if (rootNode->value < value)
	{
		if (rootNode->right->value == value)
		{
			BSTNode * temp = rootNode->right;
			if (rootNode->right->left != 0) rootNode->right = rootNode->right->left;
			else if (rootNode->right->right != 0) rootNode->right = rootNode->right->right;
			else rootNode->right = 0; // does this set rootNode->right = 0??
			delete temp;

		}
		else removeNodeHelper(rootNode->right, value);
	}
	else
	{
		if (rootNode->left->value == value)
		{
			BSTNode * temp = rootNode->left;
			if (rootNode->left->left != 0) rootNode->left = rootNode->left->left;
			else if (rootNode->left->right != 0) rootNode->left = rootNode->left->right;
			else rootNode->left = 0;
			delete temp;
		}
		else removeNodeHelper(rootNode->left, value);
	}
	*/
}

void BinarySearchTree::remove(BSTNode * node)
{

}
void BinarySearchTree::swapVals(BSTNode * first, BSTNode * second)
{
	int temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void BinarySearchTree::bubbleDown(BSTNode * node)
{
	BSTNode * temp = node;
	BSTNode * returnNode = 0;
	while (temp->right || temp->left)
	{
		if (temp->right) // temp has 2 children
		{
			swapVals(temp, temp->right);
			if (!temp->right->right && !temp->right->left) // right node has no children -- we are finished
			{
				returnNode = temp->right;
				temp->right = 0;
				return;// returnNode;
			}
			else
			{
				temp = temp->right;
			}
		}
		else if (temp->left)
		{
			swapVals(temp, temp->left);
			if (!temp->left->right && !temp->left->left)
			{
				returnNode = temp->left;
				temp->left = 0;
				return;// returnNode;
			}
			else
			{
				temp = temp->left;
			}
		}
		else // shouldnt get here I think
		{
			return;// returnNode;
		}
	}
	return;// returnNode;
}

int BinarySearchTree::balanceTree()
{
	return 0;
}

/*
Goal:	Keep swapping rootNode with it's inorder successor. 
		If the inorder successor is a leaf, detach it from its parent and return it to be removed in the parent function
*/
BinarySearchTree::BSTNode * BinarySearchTree::findInorderSuccessor(BSTNode * rootNode)
{
	if (!rootNode) return rootNode;

	BSTNode * temp = rootNode;
	BSTNode * tempPrev = 0;
	int goingLeft = 0;

	if (temp->right) // if right leaf exists
	{	
		tempPrev = temp;
		temp = temp->right;
	}
	else
	{
		return rootNode;
	}
	
	while (temp->left) // start going down left subtree to find inorder successor
	{
		goingLeft = 1;
		tempPrev = temp;
		temp = temp->left;
	}
	swapVals(rootNode, temp);
	if (isLeaf(temp)) {
		if (goingLeft)
		{
			tempPrev->left = 0;
		}
		else
		{
			tempPrev->right = 0;
		}
		return temp;
	}
	else return findInorderSuccessor(temp); //if the inorder successor isn't a leaf, swap again
	return temp;
}

int BinarySearchTree::isLeaf(BSTNode * node)
{
	return (!(node->left || node->right));
}