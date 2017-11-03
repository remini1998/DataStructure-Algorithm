#include <iostream>
#include <string.h>
#include "stack.h"
#define MAX 10000
using namespace std;
Stack<char> symbolStack;

//优先级越大越高
int getPriority(char a) {
	switch (a)
	{
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '%': return 2;
	case '^': return 3;
	case '(': return 10;
	case ')': return 10;
	default:
		throw "This is not a symbol!";
	}
}

//是否是字母和数字
bool isElement(char a) {
	if (a >= '0'&&a <= '9') return true;
	if (a >= 'a'&&a <= 'z') return true;
	if (a >= 'A'&&a <= 'Z') return true;
	return false;
}
char* trans(char* f) {
	char* out = new char[MAX];
	int lens = strlen(f);
	int outLens = 0, index = 0;
	// 防止空输入
	if (f[0] == 0) return "";
	do {
		// 空格
		if (f[index] == ' ') continue;
		// 数字，字母
		if (isElement(f[index])) {
			out[outLens++] = f[index];
			continue;
		}
		// 运算符
		if (symbolStack.getLength() > 0) {
			// 非空
			//特殊情况：)
			if (f[index] == ')') {
				while (true) {
					//空栈停止
					if (symbolStack.getLength() <= 0) break;
					//括号
					if (symbolStack.showLast() == '(') {
						symbolStack.pop();
						break;
					}
					out[outLens++] = symbolStack.pop();
				}
				continue;
			}
			//非)
			while (getPriority(f[index]) <= getPriority(symbolStack.showLast())){
				//括号
				if (symbolStack.showLast() == '(') break;
				out[outLens++] = symbolStack.pop();
				//空栈停止
				if (symbolStack.getLength() <= 0) break;
			}
			symbolStack.push(f[index]);
		}
		else {
			// 空栈
			symbolStack.push(f[index]);
		}
	} while (f[++index] != 0);
	while (symbolStack.getLength() > 0) {
		out[outLens++] = symbolStack.pop();
	}
	// 封顶
	out[outLens] = 0;
	return out;
}
int main() {
	char f[MAX];
	while (true) {
		cout << "Input:\t";
		cin >> f;
		cout << "Output:\t" << trans(f) << endl << endl;
	}
}