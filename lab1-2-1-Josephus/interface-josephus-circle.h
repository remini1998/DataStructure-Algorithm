#pragma once
// �ӿ�
class IJosephusCircle {
public:
	// nΪ������
	virtual void init(int n) = 0;
	// ��ȡ����
	virtual int getLength() = 0;
	// ���õ�ǰ��λ��
	virtual void setNow(int s) = 0;
	// �ҵ���һ��λ�ò�ɾ�������û�����-1
	virtual int next(int m) = 0;
	// �Ƿ��Ѿ�����
	virtual bool isEnd() = 0;
	// �����ǰ������Ԫ��
	virtual void print() = 0;
};