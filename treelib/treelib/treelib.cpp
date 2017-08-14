// treelib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

template <class V>
class TreeNode {
	public:
		TreeNode(V* data);
		V* data;
		TreeNode<V>* left;
		TreeNode<V>* right;
};

template<class V>
TreeNode<V>::TreeNode(V * data)
{
	self->data = data;
	self->left = nullptr;
	self->right = nullptr;
}

template <class T>
class BinSearchTree {
	public: 
		TreeNode<T>* root;
		TreeNode<T>* initializeBSTFromVector(vector<T>& sortedVector, int left, int right);
		BinSearchTree<T>(vector<T>& sortedVector);
};

int main()
{
	std::cout << "Hello world!" << std::endl;
}

template<class T>
BinSearchTree<T>::BinSearchTree(vector<T>& sortedVector) {
	self->root = initializeBSTFromVector(sortedVector, 0, sortedVector.size() - 1);
}

template<class T>
TreeNode<T>* BinSearchTree<T>::initializeBSTFromVector(vector<T>& sortedVector, int left, int right)
{
	if (left == right) {
		TreeNode<T>* val = new TreeNode<T>(sortedVector[left]);
		return val;
	}

	if ((right - left) == 1) {
		TreeNode<T>* upperVal = new TreeNode<T>(sortedVector[left]);
		TreeNode<T>* lowerVal = new TreeNode<T>(sortedVector[right]);
		upperVal->right = lowerVal;

		return upperVal;
	}

	int mid = (left + right) / 2;

	TreeNode<T>* rootNode = new TreeNode<T>(sortedVector[mid]);

	TreeNode<T>* rightSubtree = initializeBSTFromVector(sortedVector, mid + 1, right);
	TreeNode<T>* leftSubtree = initializeBSTFromVector(sortedVector, left, mid - 1);

	rootNode->left = leftSubtree;
	rootNode->right = rightSubtree;

	return rootNode;
}

template<class T>
void printInorder(TreeNode<T>* root) {
	if (root == nullptr)
		return;
	printInorder(root->left);
	cout << " " << root->data << " ";
	printInorder(root->right)
}