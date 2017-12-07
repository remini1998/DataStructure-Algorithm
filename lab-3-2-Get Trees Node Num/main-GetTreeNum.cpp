#include <iostream>
#include "tree-node.h"
using namespace std;

template<typename T>
int Count(TreeNode<T>* tree) {
	if (!tree) return 0;
	return 1 + Count<T>(tree->leftChild) + Count<T>(tree->rightChild);
}


TreeNode<int>* BuildTree() {

	cout << "Test Tree:" << endl;
	cout << "    1" << endl;
	cout << "   / \\ " << endl;
	cout << "  2  3" << endl;
	cout << " /  / \\ " << endl;
	cout << "4  5  6" << endl;
	cout << "    \\ " << endl;
	cout << "    7" << endl;

	TreeNode<int>* head = new TreeNode<int>(1);
	head->leftChild = new TreeNode<int>(2);
	head->rightChild = new TreeNode<int>(3);
	head->leftChild->leftChild = new TreeNode<int>(4);
	head->rightChild->leftChild = new TreeNode<int>(5);
	head->rightChild->rightChild = new TreeNode<int>(6);
	head->rightChild->leftChild->rightChild = new TreeNode<int>(7);

	return head;

}


int main() {
	TreeNode<int>* root = BuildTree();
	cout << "总结点数为" << Count<int>(root) << endl;
}