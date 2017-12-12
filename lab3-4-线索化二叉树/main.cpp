// Thanks to http://blog.csdn.net/my_heart_/article/details/52086321


#define _CRT_SECURE_NO_WARNINGS 1  
#include<iostream>  
using namespace std;
#include<assert.h>  

//����������   
typedef enum
{
	Link,
	Thread
} PointTag;

typedef struct  BinaryTreeNode
{
	BinaryTreeNode(const char data)
		:_data(data)
		, pLeft(NULL)
		, pRight(NULL)
		, Ltag(Link)
		, Rtag(Link)
	{}
	char _data;
	struct  BinaryTreeNode *pLeft, *pRight;
	PointTag  Ltag, Rtag;
}BiTreeNode;

class Thread_BiTree
{
public:
	//���� --������  
	Thread_BiTree(const char* arr, size_t Size)
		:_pRoot(NULL)
		, Prev(NULL)
	{
		size_t index = 0;
		_CreatTree(_pRoot, arr, Size, index);//����������  
	}
protected:
	void  _CreatTree(BiTreeNode*& Root, const char* arr, size_t size, size_t& index)
	{
		if (arr == NULL || size == 0)
		{
			cout << "�������� " << endl;
			return;
		}
		if (index < size && arr[index] != '#')
		{
			Root = new BiTreeNode(arr[index]);
			_CreatTree(Root->pLeft, arr, size, ++index);
			_CreatTree(Root->pRight, arr, size, ++index);
		}
	}
public:
	//����--������������  
	void PreOrderThreading()
	{
		_PreOrderThreading(this->_pRoot);
	}
	//����--���� ����������  
	void PreOrder()
	{
		_PreOrder(this->_pRoot);
	}
protected:
	//����--������������--C    
	//˼·���ȿ��������� ����һ���ڵ��ʱ���ڼ����һ���ڵ���ҽڵ�  
	void _PreOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		if (Root->pLeft == NULL) //û��������  
		{
			Root->pLeft = Prev;   //ǰ��  
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL) // ��һ���ڵ���û��  ������  
		{  //Prev��һ�ν��� Ϊ��    
			Prev->pRight = Root;   //���  
			Prev->Rtag = Thread;
		}
		Prev = Root;//ǰ��  �� ÿ�μ�ס�ϴεĽڵ�  

					//�ж�Root�Ƿ������Һ���  
		if (Root->Ltag == Link)
			_PreOrderThreading(Root->pLeft);
		if (Root->Rtag == Link)
			_PreOrderThreading(Root->pRight);
	}
	//����--���� ����������--C  
	void _PreOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur != NULL)
		{
			while (pCur->pLeft != NULL && pCur->Ltag == Link)//�ҵ�����ߵĽڵ�,����һֱΪLink  
			{
				cout << pCur->_data << ' ';
				pCur = pCur->pLeft;
			}
			//����������ߵĵĽڵ㻹û�з���  
			cout << pCur->_data << ' ';

			if (pCur->Ltag == Thread)//�������� �Ϳ��ҽڵ�  
			{
				pCur = pCur->pRight;
			}
			while (pCur != NULL)//ѭ���ҽڵ�  
			{
				if (pCur->pLeft != NULL && pCur->Ltag == Link)//������ڵ���� �� �����  
				{
					break;
				}
				cout << pCur->_data << ' ';
				pCur = pCur->pRight;
			}
		}
	}

public:
	//����--������������  
	void InOrderThreading()
	{
		_InOrderThreading(_pRoot);
	}
	//����--��������������  
	void InOrder()
	{
		_InOrder(this->_pRoot);
	}
protected:
	//����--������������--C  
	//˼·:�� ��-��-�ҵ�˳��   ���ҵ�����ߵĽڵ�-> ����������һ�� ,��������������ִ�е���һ���ڵ��ڿ��ϴνڵ�������� -> ������  
	void _InOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_InOrderThreading(Root->pLeft);    // ��  

		if (Root->pLeft == NULL) //��  
		{
			Root->Ltag = Thread;
			Root->pLeft = Prev;
		}
		if (Prev != NULL && Prev->pRight == NULL)
		{
			Prev->pRight = Root;
			Prev->Rtag = Thread;
		}
		Prev = Root;
		_InOrderThreading(Root->pRight);   //��  
	}
	//����--����������--C  
	//˼·���ҵ�����ʼ�Ľڵ㣨����ߵĽڵ㣩-> (��� )���ĸ��ڵ㣬��û�������ҽڵ�  
	void _InOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur)
		{
			while (pCur->Ltag == Link) //������ߵĽڵ�  
			{
				pCur = pCur->pLeft;
			}
			cout << pCur->_data << ' ';

			while (pCur && pCur->Rtag == Thread)//�������̽ڵ�  
			{
				pCur = pCur->pRight;
				cout << pCur->_data << ' ';
			}
			//û�к�̣���������     
			pCur = pCur->pRight;
		}
	}
public:
	//����--����������  
	void PostOrderThreading()
	{
		_PostOrderThreading(_pRoot);
	}
protected:
	//����--����������--C  
	//˼·����-��-��  ��ǰ���һ��  
	void _PostOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_PostOrderThreading(Root->pLeft);
		_PostOrderThreading(Root->pRight);

		if (Root->pLeft == NULL)
		{
			Root->pLeft = Prev;
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL)
		{
			Prev->pRight = Root;
			Prev->Rtag = Thread;
		}
		Prev = Root;
	}
private:
	BiTreeNode* _pRoot;
	BiTreeNode* Prev;  //��¼  
};

int main()
{
	//char * arr = "013##4##25##6##";  
	//char * arr = "012##3##4##";
	//Thread_BiTree tree(arr, strlen(arr));

	//tree.PreOrderThreading();            //����������  
	//tree.PreOrder();                   //������������������  
	//cout << endl << "------------------------" << endl;

	char * arr1 = "013##4##25##6##";
	Thread_BiTree tree1(arr1, strlen(arr1));
	tree1.InOrderThreading();          //����������  
	tree1.InOrder();                //������������������  
	cout << endl << "------------------------" << endl;

	//char * arr2 = "013##4##25##6##";
	//Thread_BiTree tree2(arr2, strlen(arr2));
	//tree2.PostOrderThreading();
	////tree2.PostOrder();
	//cout << endl << "------------------------" << endl;
	return 0;
}