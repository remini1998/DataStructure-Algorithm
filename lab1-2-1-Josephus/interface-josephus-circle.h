#pragma once
// 接口
class IJosephusCircle {
public:
	// n为总人数
	virtual void init(int n) = 0;
	// 获取长度
	virtual int getLength() = 0;
	// 设置当前的位置
	virtual void setNow(int s) = 0;
	// 找到下一个位置并删除，如果没有输出-1
	virtual int next(int m) = 0;
	// 是否已经结束
	virtual bool isEnd() = 0;
	// 输出当前的所有元素
	virtual void print() = 0;
};