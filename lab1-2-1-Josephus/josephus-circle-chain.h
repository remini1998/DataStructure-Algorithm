#pragma once
#include "interface-josephus-circle.h"
class JosephusCircleChain : public IJosephusCircle {
public:
	JosephusCircleChain(int n) { init(n); }
	// nΪ������
	virtual void IJosephusCircle::init(int n);
	// ��ȡ����
	virtual int IJosephusCircle::getLength();
	// ���õ�ǰ��λ��
	virtual void IJosephusCircle::setNow(int s);
	// �ҵ���һ��λ�ò�ɾ�������û�����-1
	virtual int IJosephusCircle::next(int m);
	// �Ƿ��Ѿ�����
	virtual bool IJosephusCircle::isEnd();
	// �����ǰ������Ԫ��
	virtual void IJosephusCircle::print();

	static JosephusCircleChain* frist;

	JosephusCircleChain* nextNode;
private:
	int id;
	JosephusCircleChain();
};
