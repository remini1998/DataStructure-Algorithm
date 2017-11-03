#pragma once
template<class T>
class Node {
public:
	T* data;
	Node<T>* previous;
	Node<T>* next;
	Node(T& data);
	void ChangeNext(Node<T>& next);
	void AddNext(Node<T>& next);
	void DeleteNext();
	void OnlyDeleteNext();
};

template<class T>
inline Node<T>::Node(T & data)
{
	this->data = &data;
	next = nullptr;
	previous = nullptr;
}
//������������е�
template<class T>
inline void Node<T>::ChangeNext(Node<T>& next)
{
	if (this->next != nullptr) DeleteNext();
	this->next = &next;
	next.previous = this;
}
//�ں������һ��������ԭ������ƴ��
template<class T>
inline void Node<T>::AddNext(Node<T>& next)
{
	this->next->previous = &next;
	next.next = this->next;
	next.previous = this;
	this->next = &next;
	
}

//ɾ����������е�
template<class T>
inline void Node<T>::DeleteNext()
{
	if (this->next == nullptr) throw "THIS NODE HAVE NO NEXT NODE!";
	next->previous = nullptr;
	next = nullptr;
}
//ֻɾ�������һ�������Ѻ���ƴ��
template<class T>
inline void Node<T>::OnlyDeleteNext()
{
	if (this->next == nullptr) throw "THIS NODE HAVE NO NEXT NODE!";
	next->previous = nullptr;
	next->next->previous = this;
	next = next->next;
}
