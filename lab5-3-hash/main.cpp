#include <iostream>
using namespace std;

#define HASH_MAX 12000

int hashStorage[HASH_MAX];

void generalHash(int seed) {
	for (int a = 0; a < HASH_MAX; a++)
		hashStorage[a] = -1;
	srand(seed);
	for (int a = 0; a < HASH_MAX; a++) {
		int num = rand() % HASH_MAX;
		int nowIndex = num / 2;
		while (hashStorage[nowIndex] >= 0) {
			nowIndex++;
			nowIndex %= HASH_MAX;
		}
		hashStorage[nowIndex] = num;
	}
}

int main() {
	int seed;
	cout << "请输入数据生成种子：";
	cin >> seed;
	generalHash(seed);
	int index;
	while (true)
	{
		cout << "请输入要查找的编号：";
		cin >> index;
		cout << "编号为" << index << "的位置为" << hashStorage[index] << endl;
	}
	return 0;
}