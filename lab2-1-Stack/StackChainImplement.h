#pragma once
#include "IStack.h"
#include "Node.h"
template<class T>
class StackChainImplement : public IStack<T> {
public:
	void push(T& input);
	T& pop();
private:
	Node<T>* now;
};

template<class T>
inline void StackChainImplement<T>::push(T & input)
{
	Node<T>* newNode = new Node<T>(input);
	if (now == nullptr) {
		now = newNode;
	}
	else {
		now->ChangeNext(*newNode);
		now = now->next;
	}
}

template<class T>
inline T & StackChainImplement<T>::pop()
{
	if (now == nullptr) throw "NO DATA INSIDE!";
	if (now->previous == nullptr) {
		T* d = now->data;
		delete now;
		now = nullptr;
		return *d;
	}
	Node<T>* del = now;
	T* d = del->data;
	now = now->previous;
	now->DeleteNext();
	delete del;
	return *d;
}
