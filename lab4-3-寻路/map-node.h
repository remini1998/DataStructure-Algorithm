#pragma once
#include "map-link.h"

template <typename T>
class MapNode {
public:
	T data;
	MapLink<T>* road = nullptr;
	MapNode() {

	}
	MapNode(T data) {

		this->data = data;
	}
};