#pragma once
template<typename T>
class TreeNode {
public:
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
	T data;
	TreeNode() {
		leftChild = nullptr;
		rightChild = nullptr;
	}
	TreeNode(T data) {
		leftChild = nullptr;
		rightChild = nullptr;
		this->data = data;
	}
};