#include <iostream>
#include <string.h>
bool judgement(char* input) {
	int n = strlen(input);
	for (int a = 0; a < n / 2; a++)
		if (input[a] != input[n - 1 - a])
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