#include <iostream>
#include "josephus-circle-chain.h"

JosephusCircleChain* JosephusCircleChain::frist = NULL;
JosephusCircleChain* JosephusCircleChain::now = NULL;

JosephusCircleChain::JosephusCircleChain()
{
}
void JosephusCircleChain::init(int n) {
	if (n <= 0) throw "INPUT CAN NOT LOWER THAN ZERO!";
	frist = this;
	now = this;
	JosephusCircleChain* last = this;
	int counter = 1;
	this->id = 0;
	while (--n) {
		last->nextNode = new JosephusCircleChain();
		last->nextNode->id = counter++;
		last = last->nextNode;
	}
	last->nextNode = this;
}

int JosephusCircleChain::getLength() {
	if (nextNode == NULL) return 0;
	if (nextNode == this) return 1;
	int counter = 1;
	JosephusCircleChain* tmp = this;
	while (tmp->nextNode != this) {
		counter++;
		tmp = tmp->nextNode;
	}
	return counter;
}

void JosephusCircleChain::setNow(int s) {
	s--;
	while (s--) now = now->nextNode;
}

int JosephusCircleChain::next(int m) {
	if (isEnd()) return -1;
	m--;
	while (m--) now = now->nextNode;
	int num = now->nextNode->id;
	if (now->nextNode != now) {
		if (frist == now->nextNode) frist = frist->nextNode;
		now->nextNode = now->nextNode->nextNode;
	}
	else
		now->nextNode = NULL;
	return num;
}
bool JosephusCircleChain::isEnd() {
	return getLength() <= 0;
}
void JosephusCircleChain::print() {
	JosephusCircleChain* t = frist;
	if (this->nextNode == NULL) return;
	int counter = 0;
	do {
		std::cout << counter++ << ":" << t->id << std::endl;
		t = t->nextNode;
	} while (t != frist);
	std::cout << std::endl;
}