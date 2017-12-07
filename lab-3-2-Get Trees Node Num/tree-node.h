#pragma once
template<typename T>
class TreeNode {
public:
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
	T data;
	TreeNode(T data) {
		leftChild = nullptr;
		rightChild = nullptr;
		this->data = data;
	}
};