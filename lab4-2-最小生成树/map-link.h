#pragma once
template <typename T>
class MapNode;
template <typename T>
class MapLink
{
public:
	MapNode<T>* dest;
	MapLink<T>* next;
	float weight = 0;
	MapLink() : MapLink(0) {

	}
	MapLink(float weight) {
		this->weight = weight;
	}
private:

};