#pragma once

typedef enum
{
	Link,
	Thread
} PointTag;

template<typename T>
class TreeNode {
public:
	TreeNode<T>* leftChild
	TreeNode<T>* rightChild;
	PointTag leftTag;
	PointTag rightTag;
	T data;
	TreeNode() {
		leftChild = nullptr;
		rightChild = nullptr;
		leftTag = Link;
		rightTag = Link;
	}
	TreeNode(T data) {
		leftChild = nullptr;
		rightChild = nullptr;
		leftTag = Link;
		rightTag = Link;
		this->data = data;
	}
};