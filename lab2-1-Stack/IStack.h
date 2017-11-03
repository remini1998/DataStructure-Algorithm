#pragma once
template<class T>
class IStack
{
public:
	virtual void push(T& input) = 0;
	virtual T& pop() = 0;
};
