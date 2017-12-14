#include <iostream>
using namespace std;
template<typename T>
class ChainNode {
public:
	T data;
	static ChainNode<T>* head;
	static ChainNode<T>* last;

	template<typename T>
	static void ChainFactory(T data) {
		if (!head) {
			last = head = new ChainNode<T>(data);
		}
		else {
			last->next = new ChainNode<T>(data);
			last = last->next;
		}
	}
	ChainNode* next;
	ChainNode<T>::ChainNode(T data) {
		this->data = data;
		this->next = NULL;
	}
};

ChainNode<int>* ChainNode<int>::head = NULL;
ChainNode<int>* ChainNode<int>::last = NULL;

int main() {
	ChainNode<int>::ChainFactory(1);
	ChainNode<int>::ChainFactory(2);
	ChainNode<int>::ChainFactory(3);
	ChainNode<int>::ChainFactory(5);
	ChainNode<int>::ChainFactory(7);
	ChainNode<int>::ChainFactory(9);
	ChainNode<int>::ChainFactory(10);
	int x;
	bool showNotFound = true;
	cout << "Input the Num you found:";
	cin >> x;
	ChainNode<int>* h = ChainNode<int>::head;
	while (h = h->next)
	{
		cout << "Come to " << h->data << endl;
		if (h->data == x) {
			showNotFound = false;
			cout << "FOUND! ID = " << h->data << endl;
			break;
		}
		if (h->data > x) {
			cout << "NOT FOUND AND EXIT! " << endl;
			showNotFound = false;
			break;
		}
	}
	if (showNotFound) {
		cout << "NOT FOUND! " << endl;
	}
	return 0;
}