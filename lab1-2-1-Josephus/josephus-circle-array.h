#pragma once
#include "interface-josephus-circle.h"
#define MAX_NUM 1000000
class JosephusCircleArray : public IJosephusCircle{
public:
	JosephusCircleArray(int n) { init(n); }
	// nΪ������
	virtual void IJosephusCircle::init(int n);
	// ��ȡ����
	int IJosephusCircle::getLength();
	// ���õ�ǰ��λ��
	void IJosephusCircle::setNow(int s);
	// �ҵ���һ��λ�ò�ɾ�������û�����-1
	int IJosephusCircle::next(int m);
	// �Ƿ��Ѿ�����
	bool IJosephusCircle::isEnd();
	// �����ǰ������Ԫ��
	void IJosephusCircle::print();
private:
	int data[MAX_NUM];
	int now;
	int length;
};