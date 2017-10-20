#pragma once
#include "interface-josephus-circle.h"
class JosephusCircleChain : public IJosephusCircle {
public:
	JosephusCircleChain(int n) { init(n); }
	// n为总人数
	virtual void IJosephusCircle::init(int n);
	// 获取长度
	virtual int IJosephusCircle::getLength();
	// 设置当前的位置
	virtual void IJosephusCircle::setNow(int s);
	// 找到下一个位置并删除，如果没有输出-1
	virtual int IJosephusCircle::next(int m);
	// 是否已经结束
	virtual bool IJosephusCircle::isEnd();
	// 输出当前的所有元素
	virtual void IJosephusCircle::print();

	static JosephusCircleChain* frist;

	JosephusCircleChain* nextNode;
private:
	int id;
	JosephusCircleChain();
};
