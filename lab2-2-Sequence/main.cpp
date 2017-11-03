#include <iostream>
#include "Seqence.h"
using namespace std;
int main() {
	int a0 = 0, a1 = 1, a2 = 2, a3 = 3, a4 = 4;
	Seqence<int>* s = new Seqence<int>();
	cout << "Push Last:" << a1 << endl;
	s->pushLast(a1);
	cout << "Push Last:" << a2 << endl;
	s->pushLast(a2);
	cout << "Push Last:" << a3 << endl;
	s->pushLast(a3);
	cout << "Pop:" << s->pop() << endl;
	cout << "Push Last:" << a4 << endl;
	s->pushLast(a4);
	cout << "Push Head:" << a0 << endl;
	s->pushHead(a0);
	cout << "Pop:" << s->pop() << endl;
	cout << "Pop:" << s->pop() << endl;
	cout << "Pop:" << s->pop() << endl;
	cout << "Pop:" << s->pop() << endl;
	system("pause");
	return 0;
}