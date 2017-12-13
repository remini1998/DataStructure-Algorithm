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

	setInfo(0, "第二食堂（在拆）", "麻辣香锅，再也没有了QAQ");
	setInfo(1, "新天天餐厅（竣工）", "新的天天餐厅，超赞！");
	setInfo(2, "北门小卖部（在拆）", "彩钢房都要拆！统统的！");
	setInfo(3, "13号宿舍楼（竣工）", "新的宿舍楼，看上去好高大上呢~");
	setInfo(4, "游泳馆前小卖部（在拆）", "从此以后，早饭tan90");
	setInfo(5, "停车场（竣工）", "现代化停车场，完美配合国家电动车方案！");
	setInfo(6, "临时工地办公室及住房", "北京的建设者们应该也要有个家吧。");
	setInfo(7, "逸夫图书馆（在建）", "听说等我们毕了业，这里就能修好了……");
	setInfo(8, "月亮坑（没水）", "平日都没水，有水也是冰。");

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