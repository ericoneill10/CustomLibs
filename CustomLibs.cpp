// CustomLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BinarySearchTree/BinarySearchTree.h"
using namespace std;

int testBST()
{
	cout << "Binary Search Tree Test" << endl;
	BinarySearchTree bst;
	bst.addNode(50);
	bst.addNode(30); 
	bst.addNode(70);
	bst.addNode(10);
	bst.addNode(0);
	bst.addNode(20);
	bst.addNode(60);
	bst.addNode(65);
	bst.addNode(75);
	bst.printTree();

	bst.removeNode(50);
	bst.printTree();

	return 1;
}

int main()
{
	int errorCode;
	std::cout << "Starting Tests..." << endl;
	if ((errorCode = testBST()) != 1)
	{
		cout << "BST error " << errorCode << endl;
	}

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
