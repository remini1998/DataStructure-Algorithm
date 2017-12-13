#include <iostream>
#include <string.h>
#include <queue>
#include "map-node.h"

using namespace std;

#define SITES_MAX 100
#define STRING_MAX 10000

typedef struct {
	char name[STRING_MAX];
	char intro[STRING_MAX];
} Site;

int road[SITES_MAX][SITES_MAX];
bool hasPassed[SITES_MAX];
Site sites[SITES_MAX];
int sitesNum = 0;

void setInfo(int index, char* name, char* intro) {
	strcpy_s(sites[index].name, name);
	strcpy_s(sites[index].intro, intro);
}

void resetPassed() {
	for (int a = 0; a < SITES_MAX; a++)
		hasPassed[a] = false;
}

void resetRoad() {
	for (int a = 0; a < SITES_MAX; a++)
		for (int b = 0; b < SITES_MAX; b++)
			road[a][b] = 0;
}

void setRoad(int beginIndex, int endIndex, int lens) {
	road[beginIndex][endIndex] = lens;
	road[endIndex][beginIndex] = lens;
}

void fillTest() {
	resetPassed();
	resetRoad();

	sitesNum = 9;

	setInfo(0, "�ڶ�ʳ�ã��ڲ�", "�����������Ҳû����QAQ");
	setInfo(1, "�����������������", "�µ�������������ޣ�");
	setInfo(2, "����С�������ڲ�", "�ʸַ���Ҫ��ͳͳ�ģ�");
	setInfo(3, "13������¥��������", "�µ�����¥������ȥ�øߴ�����~");
	setInfo(4, "��Ӿ��ǰС�������ڲ�", "�Ӵ��Ժ��緹tan90");
	setInfo(5, "ͣ������������", "�ִ���ͣ������������Ϲ��ҵ綯��������");
	setInfo(6, "��ʱ���ذ칫�Ҽ�ס��", "�����Ľ�������Ӧ��ҲҪ�и��Ұɡ�");
	setInfo(7, "�ݷ�ͼ��ݣ��ڽ���", "��˵�����Ǳ���ҵ����������޺��ˡ���");
	setInfo(8, "�����ӣ�ûˮ��", "ƽ�ն�ûˮ����ˮҲ�Ǳ���");

	setRoad(0, 1, 800);
	setRoad(1, 2, 200);
	setRoad(2, 3, 400);
	setRoad(3, 5, 1200);
	setRoad(5, 8, 900);
	setRoad(7, 8, 900);
	setRoad(6, 7, 900);
	setRoad(0, 6, 1800);

	setRoad(4, 1, 500);
	setRoad(4, 2, 600);
	setRoad(4, 5, 700);
	setRoad(4, 7, 300);

}

void dfs(int index, void (*func)(int)) {
	hasPassed[index] = true;
	func(index);
	for (int a = 0; a < sitesNum; a++)
		if (road[index][a] > 0 && !hasPassed[a])
			dfs(a, func);
}



void bfs(int index, void(*func)(int)) {
	if (hasPassed[index]) return;
	static queue<int> q;
	hasPassed[index] = true;
	func(index);
	for (int a = 0; a < sitesNum; a++)
		if (road[index][a] > 0 && !hasPassed[a])
			q.push(a);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		bfs(a, func);
	}

}


void show(int index) {
	cout << "�Ѿ���" << sites[index].name << endl;
}

int main() {
	fillTest();
	cout << "DFS��" << endl;
	dfs(0, show);
	resetPassed();
	cout << "BFS��" << endl;
	bfs(0, show);
	return 0;
}