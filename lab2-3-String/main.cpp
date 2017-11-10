#include <iostream>
#include <string.h>
#include "stack.h"
bool judgement(char* input) {
	int a, n = strlen(input);
	Stack<char> s;
	for (a = 0; a < n / 2; a++)
		s.push(input[a]);
	if (n % 2 == 1) a++;
	for (; a < n; a++) 
		if (input[a] != s.pop())
			return false;
	return true;
}
int main() {
	char s[100000];
	while (true) {
		std::cout << "Input String:" << std::endl;
		std::cin >> s;
		std::cout << (judgement(s) ? "中心对称" : "并不对称") << std::endl;
	}
}