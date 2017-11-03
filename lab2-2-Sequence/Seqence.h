#pragma once
#include "Node.h"
template<class T>
class Seqence {
public:
	void pushHead(T& input);
	void pushLast(T& input);
	T& pop();
	void Clear();
private: 
	Node<T>* now = nullptr;
};

template<class T>
inline void Seqence<T>::pushHead(T & input)
{
	if (now == nullptr) {
		Node<T>* n = new Node<T>(input);
		n->ChangeNext(*n);
	}
	else {
		Node<T>* n = new Node<T>(input);
		now->AddNext(*n);
	}
}

template<class T>
inline void Seqence<T>::pushLast(T & input)
{
	if (now == nullptr) {
		Node<T>* n = new Node<T>(input);
		n->ChangeNext(*n);
		now = n;
	}
	else {
		Node<T>* n = new Node<T>(input);
		now->AddNext(*n);
		now = now->next;
	}
}

template<class T>
inline T & Seqence<T>::pop()
{
	if (now == nullptr) throw "NO DATA INSIDE!";
	if (now->next == now) {
		T* d = now->data;
		now = nullptr;
		return *d;
	}
	T* d = now->next->data;
	now->OnlyDeleteNext();
	return *d;
}

template<class T>
inline void Seqence<T>::Clear()
{
	now = nullptr;
}
