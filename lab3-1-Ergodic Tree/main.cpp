#include <iostream>
#include "inorder-traversal-binary-tree.h"
#include "tree-node.h"
using namespace std;

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

void output(TreeNode<int>* node) {
	cout << node->data;
}


int main() {
	TreeNode<int>* tree = BuildTree();
	cout << "µÝ¹éÖÐÐò±éÀú£º";
	TraversalWithRecursive<int>(tree, &output);
	cout << endl;
	cout << "·ÇµÝ¹éÖÐÐò±éÀú£º";
	Traversal<int>(tree, &output);
	cout << endl;
	return 0;
}