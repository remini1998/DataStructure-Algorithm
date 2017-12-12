#pragma once
#include "tree-node.h"
#include <stack>


//template<class T>
//typedef typename TreeNode<T> arg2_type;
//
//template<class T>
//typedef void (*fun_ptr)(TreeNode<T>);

template <typename T>
void Traversal(TreeNode<T>* head, void(*fun)(TreeNode<T>*)) {
	if (!head) return;
	std::stack<TreeNode<T>*> s;
	TreeNode<T>* now = head;
	while (now || !s.empty()) {
		while (now) {
			s.push(now);
			now = now->leftChild;
		}
		now = s.top();
		s.pop();
		fun(now);
		now = now->rightChild;
	}
}

template <typename T>
void TraversalWithRecursive(TreeNode<T>* head, void(*fun)(TreeNode<T>*)) {
	if (head->leftChild) 
		TraversalWithRecursive(head->leftChild, fun);
	fun(head);
	if (head->rightChild) 
		TraversalWithRecursive(head->rightChild, fun);
}

