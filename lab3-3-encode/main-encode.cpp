#include <iostream>
#include "tree-node.h"

#define MAX_STRING 10000

using namespace std;

typedef struct {
	char letter;
	int val;
	bool isRootNode;
	bool isLeafNode;
} CharVal;

TreeNode<CharVal>* tree;

int* CountString(char* string) {
	int i = 0;
	int* r = new int[256];
	for (int a = 0; a < 256; a++) {
		r[a] = 0;
	}
	while (string[i++]) 
		r[string[i]]++;
	return r;
}

TreeNode<CharVal>** Trans2Nodes(int* timesData, int* num){
	int n = 0;
	TreeNode<CharVal>** nodes = new TreeNode<CharVal>*[512];
	for (int a = 1; a < 256; a++) {
		if (!timesData[a]) continue;
		CharVal cv;
		cv.letter = (char)a;
		cv.val = timesData[a];
		cv.isLeafNode = true;
		cv.isRootNode = true;
		TreeNode<CharVal>* node = new TreeNode<CharVal>(cv);
		nodes[n++] = node;
	}
	*num = n;
	return nodes;
}

TreeNode<CharVal>* BuildTree(TreeNode<CharVal>* nodes[], int num) {
	if (num == 0)return NULL;
	if (num == 1)return *nodes;
	int rest = num;
	while (true) {
		// 找到最小的
		TreeNode<CharVal> *min1 = NULL, *min2 = NULL;
		for (int now = 0; now < num; now++) {
			if (nodes[now] && nodes[now]->data.isRootNode) {
				if (!min1) min1 = nodes[now];
				else if (!min2) {
					if (min1->data.val <= nodes[now]->data.val)
						min2 = nodes[now];
					else {
						min2 = min1;
						min1 = nodes[now];
					}
				}
				else if (min1->data.val > nodes[now]->data.val) {
					min2 = min1;
					min1 = nodes[now];
				}
				else if (min2->data.val > nodes[now]->data.val)
					min2 = nodes[now];
			}
		}

		// 拼接两个最小的
		min1->data.isRootNode = false;
		min2->data.isRootNode = false;
		CharVal cv;
		cv.letter = 0;
		cv.isLeafNode = false;
		cv.isRootNode = true;
		cv.val = min1->data.val + min2->data.val;
		TreeNode<CharVal>* newNode = new TreeNode<CharVal>(cv);
		newNode->leftChild = min1;
		newNode->rightChild = min2;

		// 加入队列
		nodes[num++] = newNode;

		rest--;

		//检测是否跳出
		if (rest <= 1)
			return newNode;
	}
}

char* TransByTree(TreeNode<CharVal>* tree, char* encode) {
	int index = 0, lens = 0;
	char* s = new char[MAX_STRING];
	TreeNode<CharVal>* now = tree;
	while (encode[index]) {
		if (now->data.isLeafNode) {
			s[lens++] = now->data.letter;
			now = tree;
		}
		if (encode[index] == '0') {
			now = now->leftChild;
		}
		else if (encode[index] == '1') {
			now = now->rightChild;
		}
		index++;
	}
	s[lens] = 0;
	return s;
}

int main() {
	char input[MAX_STRING], encode[MAX_STRING];
	cout << "请输入欲分析字符串（例：CASTCASTSATATATASA）：" << endl;
	cin >> input;
	int* times = CountString(input);
	int num;
	TreeNode<CharVal>** nodes;
	nodes = Trans2Nodes(times, &num);
	cout << "结点序列化完成" << endl;
	TreeNode<CharVal>* tree = BuildTree(nodes, num);
	cout << "霍夫曼树构建完成" << endl;
	while(true){
		cout << endl << "请输入01编码（例：111011001110110011001001001001100）：" << endl;
		cin >> encode;
		char* s = TransByTree(tree, encode);
		cout << "解析完成：" << endl << s << endl;
	}
}