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
			road[a][b] = -1;
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

int cache[SITES_MAX];
int record[SITES_MAX];

bool isDijksraEnd(int end) {
	return record[end] >= 0;
}

void dijksra(int start, int end) {
	for (int a = 0; a < SITES_MAX; a++) {
		cache[a] = -1;
		record[a] = -1;
	}
		cache[start] = 0;
	while (!isDijksraEnd(end)) {
		int minStart = -1, minEnd = -1;
		for(int a = 0; a < sitesNum; a++)
			for (int b = 0; b < sitesNum; b++)
				if (cache[a] >= 0 && road[a][b] >= 0) {
					if (cache[b] < 0) {
						cache[b] = cache[a] + road[a][b];
						record[b] = a;
					}
					else if (cache[b] > cache[a] + road[minStart][minEnd]) {
						cache[b] = cache[a] + road[a][b];
						record[b] = a;
					}
				}
		// cout << "Add Way: " << minStart << " to " << minEnd << endl;
	}
	
	
}

void showWay(int start, int end) {
	while (end != start) {
		cout << "way back:(" << end << ")" << sites[end].name << " to " << "(" << record[end] << ")" << sites[record[end]].name << endl;
		end = record[end];
	}
}

void showSites() {
	for (int a = 0; a < sitesNum; a++) {
		cout << "id:" << a << "\t" << sites[a].name << "\t" << sites[a].intro << endl;
	}
}

int main() {
	fillTest();
	showSites();
	cout << "��������㡢�յ��ţ�";
	int start, end;
	cin >> start >> end;
	dijksra(start, end);
	showWay(start, end);
	return 0;
}