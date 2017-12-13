#include <iostream>
using namespace std;

int data_src[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
int num = 10;

void find(int x) {
	int begin = 0, end = num - 1;
	while (end - begin > 1) {
		int t = (begin + end) / 2;
		if (data_src[t] == x) {
			cout << "已找到" << x << "，位置是：" << t << endl;
			return;
		}
		else if (data_src[t] > x) {
			cout << "已搜索位置（大）：" << t << endl;
			end = t;
		}
		else if (data_src[t] < x) {
			cout << "已搜索位置（小）："  << t << endl;
			begin = t;
		}
	}
	cout << "未找到此数！" << endl;
}

int main() {
	int x;
	cin >> x;
	find(x);
	return 0;
}