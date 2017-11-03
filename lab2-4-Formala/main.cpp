#include <iostream>
#include <string.h>
#include "stack.h"
#define MAX 10000
using namespace std;
Stack<char> symbolStack;

//���ȼ�Խ��Խ��
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

//�Ƿ�����ĸ������
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
	// ��ֹ������
	if (f[0] == 0) return "";
	do {
		// �ո�
		if (f[index] == ' ') continue;
		// ���֣���ĸ
		if (isElement(f[index])) {
			out[outLens++] = f[index];
			continue;
		}
		// �����
		if (symbolStack.getLength() > 0) {
			// �ǿ�
			//���������)
			if (f[index] == ')') {
				while (true) {
					//��ջֹͣ
					if (symbolStack.getLength() <= 0) break;
					//����
					if (symbolStack.showLast() == '(') {
						symbolStack.pop();
						break;
					}
					out[outLens++] = symbolStack.pop();
				}
				continue;
			}
			//��)
			while (getPriority(f[index]) <= getPriority(symbolStack.showLast())){
				//����
				if (symbolStack.showLast() == '(') break;
				out[outLens++] = symbolStack.pop();
				//��ջֹͣ
				if (symbolStack.getLength() <= 0) break;
			}
			symbolStack.push(f[index]);
		}
		else {
			// ��ջ
			symbolStack.push(f[index]);
		}
	} while (f[++index] != 0);
	while (symbolStack.getLength() > 0) {
		out[outLens++] = symbolStack.pop();
	}
	// �ⶥ
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