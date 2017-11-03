#pragma once
#include "IStack.h"
#define ARRAY_MAX 10000
template<class T>
class Stack : public IStack<T>
{
public:
	Stack();
	~Stack();
	void push(T& input);
	T& pop();

private:
	T* data[ARRAY_MAX];
	int nextIndex = 0;
};

template<class T>
inline Stack<T>::Stack()
{
}

template<class T>
inline Stack<T>::~Stack()
{
}

template<class T>
inline void Stack<T>::push(T& input)
{
	if (nextIndex >= ARRAY_MAX) throw "NO SPACE!";
	data[nextIndex++] = &input;
}

template<class T>
inline T & Stack<T>::pop()
{
	if (nextIndex <= 0) throw "NO DATA INSIDE!";
	return *data[--nextIndex];
}

