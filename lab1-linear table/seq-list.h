#pragma once
#define MAX_LENS 100000
template <class T>
class SeqList {
public:
	//用最大长度初始化
	SeqList(unsigned int maxLens = MAX_LENS);
	//用数据初始化
	SeqList(T data[], unsigned int dataLens, unsigned int maxLens = MAX_LENS);
	~SeqList();
	//获取表长度
	int getLens();
	T& get(unsigned int index);
	void set(unsigned int index, T& input);
	void update(T& older, T& newer);
	void add(T& input);
	void add(unsigned int index, T& input);
	void remove(T& input);
	void removeAt(unsigned int index);
	int findIndex(T& input);

private:
	T* data;
	int lens = 0;
	void testOverflowByException(unsigned int index);
	void testSpaceByException();
};

template<class T>
inline SeqList<T>::SeqList(unsigned int maxLens)
{
	data = new T[maxLens];
}

template<class T>
inline SeqList<T>::SeqList(T data[], unsigned int dataLens, unsigned int maxLens)
{
	testOverflowByException(index);
	this->data = new T[maxLens];
	for (int i = 0; i < dataLens; i++) 
		this->data[i] = data[i];
	lens = dataLens;
}

template<class T>
inline SeqList<T>::~SeqList()
{
	delete data;
}

template<class T>
inline int SeqList<T>::getLens()
{
	return lens;
}

template<class T>
inline T & SeqList<T>::get(unsigned int index)
{
	testOverflowByException(index);
	return data[index];
}

template<class T>
inline void SeqList<T>::set(unsigned int index, T & input)
{
	if (index == lens) {
		add(input);
		return;
	}
	testOverflowByException(index);
	data[index] = input;
}

template<class T>
inline void SeqList<T>::update(T & older, T & newer)
{
	int index = findIndex(older);
	set(index, newer);
}

template<class T>
inline void SeqList<T>::add(T & input)
{
	testSpaceByException();
	data[lens++] = input;
}

template<class T>
inline void SeqList<T>::add(unsigned int index, T & input)
{
	if (index == lens) {
		add(input);
		return;
	}
	testOverflowByException(index);
	testSpaceByException();
	// 下面那个(int)是为了解决微软C++ unsigned int和int负数比较时的一个bug
	for (int a = lens - 1; a >= (int)index; a--)
		data[a + 1] = data[a];
	data[index] = input;
	lens++;
}

template<class T>
inline void SeqList<T>::remove(T & input)
{
	int index = findIndex(older);
	removeAt(index);
}

template<class T>
inline void SeqList<T>::removeAt(unsigned int index)
{
	testOverflowByException(index);
	lens--;
	for (int i = index; i < lens; i++)
		data[i] = data[i + 1];
}

template<class T>
inline int SeqList<T>::findIndex(T & input)
{
	for (int i = 0; i < lens; i++)
		if (data[i] == input)
			return i;
	throw "CAN NOT FIND INDEX!";
}

template<class T>
inline void SeqList<T>::testOverflowByException(unsigned int index)
{
	if (index >= lens) throw "INDEX OVERFLOW!";
}

template<class T>
inline void SeqList<T>::testSpaceByException()
{
	if (lens >= MAX_LENS) throw "NO MORE SPACE!";
}

