// Thanks to http://blog.csdn.net/my_heart_/article/details/52086321


#define _CRT_SECURE_NO_WARNINGS 1  
#include<iostream>  
using namespace std;
#include<assert.h>  

//线索二叉树   
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
	//先序 --创建树  
	Thread_BiTree(const char* arr, size_t Size)
		:_pRoot(NULL)
		, Prev(NULL)
	{
		size_t index = 0;
		_CreatTree(_pRoot, arr, Size, index);//创建二叉树  
	}
protected:
	void  _CreatTree(BiTreeNode*& Root, const char* arr, size_t size, size_t& index)
	{
		if (arr == NULL || size == 0)
		{
			cout << "输入有误 " << endl;
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
	//先序--线索化二叉树  
	void PreOrderThreading()
	{
		_PreOrderThreading(this->_pRoot);
	}
	//先序--遍历 线索二叉树  
	void PreOrder()
	{
		_PreOrder(this->_pRoot);
	}
protected:
	//先序--线索化二叉树--C    
	//思路：先看左子树， 找下一个节点的时候，在检测上一个节点的右节点  
	void _PreOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		if (Root->pLeft == NULL) //没有左子树  
		{
			Root->pLeft = Prev;   //前驱  
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL) // 上一个节点有没有  右子树  
		{  //Prev第一次进来 为空    
			Prev->pRight = Root;   //后继  
			Prev->Rtag = Thread;
		}
		Prev = Root;//前驱  ， 每次记住上次的节点  

					//判断Root是否有左右孩子  
		if (Root->Ltag == Link)
			_PreOrderThreading(Root->pLeft);
		if (Root->Rtag == Link)
			_PreOrderThreading(Root->pRight);
	}
	//先序--遍历 线索二叉树--C  
	void _PreOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur != NULL)
		{
			while (pCur->pLeft != NULL && pCur->Ltag == Link)//找到最左边的节点,左标记一直为Link  
			{
				cout << pCur->_data << ' ';
				pCur = pCur->pLeft;
			}
			//到这来，左边的的节点还没有访问  
			cout << pCur->_data << ' ';

			if (pCur->Ltag == Thread)//遇到线索 就看右节点  
			{
				pCur = pCur->pRight;
			}
			while (pCur != NULL)//循环右节点  
			{
				if (pCur->pLeft != NULL && pCur->Ltag == Link)//遇到左节点存在 ， 则访问  
				{
					break;
				}
				cout << pCur->_data << ' ';
				pCur = pCur->pRight;
			}
		}
	}

public:
	//中序--线索化二叉树  
	void InOrderThreading()
	{
		_InOrderThreading(_pRoot);
	}
	//中序--遍历线索二叉树  
	void InOrder()
	{
		_InOrder(this->_pRoot);
	}
protected:
	//中序--线索化二叉树--C  
	//思路:按 左-根-右的顺序   先找到最左边的节点-> 和先序线索一样 ,先链接左子树，执行到下一个节点在看上次节点的右子树 -> 右子树  
	void _InOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_InOrderThreading(Root->pLeft);    // 左  

		if (Root->pLeft == NULL) //根  
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
		_InOrderThreading(Root->pRight);   //右  
	}
	//中序--遍历二叉树--C  
	//思路：找到中序开始的节点（最左边的节点）-> (后继 )它的根节点，若没有则找右节点  
	void _InOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur)
		{
			while (pCur->Ltag == Link) //找最左边的节点  
			{
				pCur = pCur->pLeft;
			}
			cout << pCur->_data << ' ';

			while (pCur && pCur->Rtag == Thread)//找中序后继节点  
			{
				pCur = pCur->pRight;
				cout << pCur->_data << ' ';
			}
			//没有后继，有右子树     
			pCur = pCur->pRight;
		}
	}
public:
	//后序--线索二叉树  
	void PostOrderThreading()
	{
		_PostOrderThreading(_pRoot);
	}
protected:
	//后序--线索二叉数--C  
	//思路：左-右-根  和前面的一样  
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
	BiTreeNode* Prev;  //记录  
};

int main()
{
	//char * arr = "013##4##25##6##";  
	//char * arr = "012##3##4##";
	//Thread_BiTree tree(arr, strlen(arr));

	//tree.PreOrderThreading();            //先序线索化  
	//tree.PreOrder();                   //遍历先序线索二叉树  
	//cout << endl << "------------------------" << endl;

	char * arr1 = "013##4##25##6##";
	Thread_BiTree tree1(arr1, strlen(arr1));
	tree1.InOrderThreading();          //中序线索化  
	tree1.InOrder();                //遍历中序线索二叉树  
	cout << endl << "------------------------" << endl;

	//char * arr2 = "013##4##25##6##";
	//Thread_BiTree tree2(arr2, strlen(arr2));
	//tree2.PostOrderThreading();
	////tree2.PostOrder();
	//cout << endl << "------------------------" << endl;
	return 0;
}