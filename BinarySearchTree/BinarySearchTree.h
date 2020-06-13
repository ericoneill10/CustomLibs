#pragma once
class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	void printTree();
	int addNode(int value);
	int removeNode(int value);
	int balanceTree();
private:
	struct BSTNode {
		int value;
		struct BSTNode * left;
		struct BSTNode * right;
	};

	BSTNode * root;

	int addNodeHelper(BSTNode ** rootNode, BSTNode * node);
	void printTreeHelper(BSTNode * rootNode, int printOffset);
	void removeNodeHelper(BSTNode * rootNode, int value);
	void swapVals(BSTNode * first, BSTNode * second);
	void bubbleDown(BSTNode * node); 
	void remove(BSTNode * node);
	BSTNode * findInorderSuccessor(BSTNode * rootNode);
	int isLeaf(BSTNode * node);



};

