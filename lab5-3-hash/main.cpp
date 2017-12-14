#include <iostream>
using namespace std;

#define HASH_MAX 12000

int hashStorage[HASH_MAX];

void generalHash() {
	for (int a = 0; a < HASH_MAX; a++)
		hashStorage[a] = -1;
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
	generalHash();
	int index;
	while (true)
	{
		cout << "������Ҫ���ҵı�ţ�";
		cin >> index;
		cout << "���Ϊ" << index << "��λ��Ϊ" << hashStorage[index] << endl;
	}
	return 0;
}