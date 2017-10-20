#include <iostream>
#include "josephus-circle-chain.h"

JosephusCircleChain* JosephusCircleChain::frist = NULL;

void JosephusCircleChain::init(int n)
{
	if (n <= 0) throw "INPUT CAN NOT LOWER THAN ZERO!";
	this->id = 0;
	JosephusCircleChain* l = this;
	for (int a = 1; a < n; a++) {
		JosephusCircleChain* t = new JosephusCircleChain();
		t->id = a;
		l->nextNode = t;
		l = t;
	}
	l->nextNode = this;
	frist = this;
}

int JosephusCircleChain::getLength()
{
	if (nextNode == NULL) return 0;
	JosephusCircleChain* t = nextNode;
	int counter = 1;
	while (t != this) {
		counter++;
		t = t->nextNode;
	}
	return counter;
}

void JosephusCircleChain::setNow(int s)
{
	//throw "链表不支持直接使用setNow";
	//JosephusCircleChain* t;
	s--;
	if (s < 0) throw "INPUT CAN NOT LOWER THAN ONE!";
	while (s--) frist = frist->nextNode;
}

int JosephusCircleChain::next(int m)
{
	static bool sw = true;
	if (sw) {
		frist->next(m);
		sw = false;
	}
	if (isEnd()) {
		sw = true;
		return -1;
	}
	static JosephusCircleChain* last = NULL;
	if (m == 0) {
		//如果只剩下一个了
		if (this->nextNode == this) {
			this->nextNode = NULL;
			sw = true;
			return this->id;
		}
		if (last == NULL) {
			//删除当前，没有前位置
			JosephusCircleChain* tmp = this;
			while (tmp->nextNode != this)
				tmp = tmp->nextNode;
			tmp->nextNode = this->nextNode;
			int a = this->id;
			//if (this == frist)frist = this->nextNode;
			frist = this->nextNode;
			delete this;
			sw = true;
			last = NULL;
			return a;
		}
		else {
			last->nextNode = this->nextNode;
			int a = this->id;
			//if (this == frist)frist = this->nextNode;
			frist = this->nextNode;
			delete this;
			sw = true;
			last = NULL;
			sw = true;
			return a;
		}
	}
	last = this;
	return this->nextNode->next(--m);
}

bool JosephusCircleChain::isEnd()
{
	return getLength() <= 0;
}

void JosephusCircleChain::print()
{
	static JosephusCircleChain* first_n = NULL;
	static int counter = 1;
	if (first_n == NULL) {
		first_n = this;
	}
	else if (first_n->id == this->id || first_n == this) {
		first_n = NULL;
		counter = 0;
		return;
	}
	std::cout << counter++ << ":" << this->id << std::endl;
	if(nextNode!=NULL) nextNode->print();
}
JosephusCircleChain::JosephusCircleChain() {

}