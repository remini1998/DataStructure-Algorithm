#pragma once
#include "map-node.h"
template <typename T>
class MapLink
{
public:
	MapNode<T>* dest;
	MapLink<T>* next;

private:

};