#include <iostream>
#include "josephus-circle-array.h"

void JosephusCircleArray::init(int n)
{
	if (n <= 0) throw "INPUT CAN NOT LOWER THAN ZERO!";
	if (n >= MAX_NUM) throw "THE DATA IS TOO LARGE!";
	length = n;
	for (int i = 0; i < length; i++)
		data[i] = i;
	now = 0;
}

int JosephusCircleArray::getLength()
{
	return length;
}

void JosephusCircleArray::setNow(int s)
{
	if (s < 0) throw "INPUT CAN NOT LOWER THAN ONE!";
	s %= length;
	now = s;
}

int JosephusCircleArray::next(int m)
{
	m--;
	if (isEnd()) return -1;
	now += m;
	now %= length;
	if (now < 0) now += length;
	int v = data[now];
	for (int i = now; i < length - 1; i++)
		data[i] = data[i + 1];
	length--;
	return v;
}

bool JosephusCircleArray::isEnd()
{
	return getLength() <= 0;
}

void JosephusCircleArray::print()
{
	for (int i = 0; i < length; i++)
		std::cout << i << ":" << data[i] << " ";
	std::cout << std::endl;
}
