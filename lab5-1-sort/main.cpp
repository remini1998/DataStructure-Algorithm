#include <iostream>
using namespace std;

int data_src[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
int num = 10;

void find(int x) {
	int begin = 0, end = num - 1;
	while (end - begin > 1) {
		int t = (begin + end) / 2;
		if (data_src[t] == x) {
			cout << "���ҵ�" << x << "��λ���ǣ�" << t << endl;
			return;
		}
		else if (data_src[t] > x) {
			cout << "������λ�ã��󣩣�" << t << endl;
			end = t;
		}
		else if (data_src[t] < x) {
			cout << "������λ�ã�С����"  << t << endl;
			begin = t;
		}
	}
	cout << "δ�ҵ�������" << endl;
}

int main() {
	int x;
	cin >> x;
	find(x);
	return 0;
}