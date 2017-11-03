#include <iostream>
#include "IStack.h"
#include "StackArrayImplement.h"
#include "StackChainImplement.h"
using namespace std;

void Tester(IStack<int>& stack) {
	int a1 = 1, a2 = 3, a3 = 5, a4 = 7, a5 = 9;
	cout << "Input:" << a1 << endl;
	stack.push(a1);
	cout << "Input:" << a2 << endl;
	stack.push(a2);
	cout << "Input:" << a3 << endl;
	stack.push(a3);
	cout << "Output:" << stack.pop() << endl;
	cout << "Input:" << a4 << endl;
	stack.push(a4);
	cout << "Output:" << stack.pop() << endl;
	cout << "Output:" << stack.pop() << endl;
	cout << "Input:" << a5 << endl;
	stack.push(a5);
	cout << "Output:" << stack.pop() << endl;
	cout << "Output:" << stack.pop() << endl;
	cout << "Test Exception:" << endl;
	try {
		cout << "Output:" << stack.pop() << endl;
	}
	catch(char* e){
		cout << "Exception:" << e << endl;
	}
}

int main() {
	cout << "Test Stack Implement by Array:" << endl;
	Tester(*(new Stack<int>()));
	cout << endl << endl << "Test Stack Implement by Chain:" << endl;
	Tester(*(new StackChainImplement<int>()));
	system("pause");
	return 0;
}
