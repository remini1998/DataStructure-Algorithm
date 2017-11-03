#pragma once
template<class T>
class Node {
public:
	T* data;
	Node<T>* previous;
	Node<T>* next;
	Node(T& data);
	void ChangeNext(Node<T>& next);
	void DeleteNext();
};

template<class T>
inline Node<T>::Node(T & data)
{
	this->data = &data;
	next = nullptr;
	previous = nullptr;
}

template<class T>
inline void Node<T>::ChangeNext(Node<T>& next)
{
	if (this->next != nullptr) DeleteNext();
	this->next = &next;
	next.previous = this;
}

template<class T>
inline void Node<T>::DeleteNext()
{
	if (this->next == nullptr) throw "THIS NODE HAVE NO NEXT NODE!";
	next->previous = nullptr;
	next = nullptr;
}
