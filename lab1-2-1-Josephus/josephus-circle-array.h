#pragma once
#include "interface-josephus-circle.h"
#define MAX_NUM 1000000
class JosephusCircleArray : public IJosephusCircle{
public:
	JosephusCircleArray(int n) { init(n); }
	// n为总人数
	virtual void IJosephusCircle::init(int n);
	// 获取长度
	int IJosephusCircle::getLength();
	// 设置当前的位置
	void IJosephusCircle::setNow(int s);
	// 找到下一个位置并删除，如果没有输出-1
	int IJosephusCircle::next(int m);
	// 是否已经结束
	bool IJosephusCircle::isEnd();
	// 输出当前的所有元素
	void IJosephusCircle::print();
private:
	int data[MAX_NUM];
	int now;
	int length;
};