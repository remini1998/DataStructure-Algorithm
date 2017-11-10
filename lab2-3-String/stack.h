#pragma once
#define ARRAY_MAX 10000
template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	void clear();
	void push(T& input);
	T& pop();
	T& showLast();
	int getLength();

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
inline void Stack<T>::clear()
{
	nextIndex = 0;
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

template<class T>
inline T & Stack<T>::showLast()
{
	return *data[nextIndex - 1];
}

template<class T>
inline int Stack<T>::getLength()
{
	return nextIndex;
}

