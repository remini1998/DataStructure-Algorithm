#include <iostream>
using namespace std;
template<typename T>
class SearchTree {
public:
	T data;
	static SearchTree<T>* root;
	SearchTree<T>* lChild = NULL;
	SearchTree<T>* rChild = NULL;
	SearchTree(T data) {
		this->data = data;
	}
	static bool AddNum(T data) {
		SearchTree<T>* d = new SearchTree<T>(data);
		if (!root) {
			root = d;
			return true;
		}
		SearchTree<T>* next = root;
		while (true) {
			if (next->data == data) return false;
			if (next->data > data) {
				if (next->lChild) {
					next = next->lChild;
				}
				else
				{
					next->lChild = d;
					return true;
				}
			}
			else if (next->data < data) {
				if (next->rChild) {
					next = next->rChild;
				}
				else
				{
					next->rChild = d;
					return true;
				}
			}
		}
	}
	static bool FindNum(T data) {
		if (!root) {
			cout << "No Data Here!" << endl;
			return false;
		}
		SearchTree<T>* next = root;
		while (true) {
			if (next->data == data) {
				cout << "Find Data " << data << "!" << endl;
				return true;
			}
			if (next->data > data) {
				if (next->lChild) {
					next = next->lChild;
				}
				else
				{
					cout << "Data Not Found!" << endl;
					return false;
				}
			}
			else if (next->data < data) {
				if (next->rChild) {
					next = next->rChild;
				}
				else
				{
					cout << "Data Not Found!" << endl;
					return false;
				}
			}
		}
	}
	static bool DelNum(T data) {
		if (!root) {
			cout << "No Data Here!" << endl;
			return false;
		}
		SearchTree<T>* next = root, *pre = NULL;
		while (true) {
			if (next->data == data) {
				if (!next->lChild) {
					if (pre) pre->rChild = next->rChild;
					else root = next->rChild;
					delete next;
				}
				else if (!next->rChild) {
					if (pre) pre->lChild = next->lChild;
					else root = next->lChild;
					delete next;
				}
				else
				{
					// 找到右子树的最左节点
					SearchTree<T>* t = next->rChild, *rt;
					if (t->lChild) {
						while (t->lChild->lChild) t = t->lChild;
						T dt = next->data;
						next->data = t->lChild->data;
						t->lChild->data = dt;
						rt = t->lChild->rChild;
						delete t->lChild;
						t->lChild = rt;
					}
					else
					{
						T dt = next->data;
						next->data = t->data;
						t->data = dt;
						rt = t->rChild;
						delete next->lChild;
						next->lChild = rt;
					}
				}
				cout << "删除成功" << endl;
				return true;
			}
			if (next->data > data) {
				if (next->lChild) {
					pre = next;
					next = next->lChild;
				}
				else
				{
					cout << "Data Not Found!" << endl;
					return false;
				}
			}
			else if (next->data < data) {
				if (next->rChild) {
					pre = next;
					next = next->rChild;
				}
				else
				{
					cout << "Data Not Found!" << endl;
					return false;
				}
			}
		}
	}
};

SearchTree<int>* SearchTree<int>::root = NULL;


int main() {
	cout << "建立搜索树，输入0停止：" << endl;
	int input;
	while (cin >> input) {
		if (!input) break;
		SearchTree<int>::AddNum(input);
	} 

SearchTag:
	while (true)
	{
		cout << "输入您要搜索的数（输入0切换到删除）：" << endl;
		cin >> input;
		if (!input) goto DelTag;
		SearchTree<int>::FindNum(input);
	}

DelTag:
	while (true)
	{
		cout << "输入您要删除的数（输入0切换到搜索）：" << endl;
		cin >> input;
		if (!input) goto SearchTag;
		SearchTree<int>::DelNum(input);
	}

	return 0;
}