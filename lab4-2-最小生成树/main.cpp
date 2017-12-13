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

bool isPrimEnd() {
	for (int a = 0; a < sitesNum; a++) 
		if(cache[a] == -1) return false;
	return true;
}

void prim(int index = 0) {
	for (int a = 0; a < SITES_MAX; a++) {
		cache[a] = -1;
	}
		cache[index] = 0;
	while (!isPrimEnd()) {
		int minStart = -1, minEnd = -1;
		for(int a = 0; a < sitesNum; a++)
			for (int b = 0; b < sitesNum; b++)
				if (cache[a] >= 0 && cache[b] < 0 && road[a][b] >= 0) {
					if (minStart < 0 || minEnd < 0 || road[a][b] < road[minStart][minEnd]) {
						minStart = a;
						minEnd = b;
					}
				}
		cout << "Add Way: " << minStart << " to " << minEnd << endl;
		cache[minEnd] = cache[minStart] + road[minStart][minEnd];
	}
	
	
}

int main() {
	fillTest();
	prim();
	return 0;
}