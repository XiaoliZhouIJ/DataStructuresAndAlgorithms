#pragma once
#include <iostream>
#include "IllegalParameterValue.h"

using namespace std;

template<typename T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual const bool empty() = 0;
	virtual const int size() = 0;
	virtual const T& get(int theIndex) = 0;
	virtual const int indexOf(const T& theElement) = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual const void output(ostream& out) = 0;

	int test;
};

/// <summary>
/// 改变一个一维数组长度
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">原数组</param>
/// <param name="oldLength">旧长度</param>
/// <param name="newLength">新长度</param>
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must >= 0");            // illegalParameterValue是自定类

	T* temp = new T[newLength];                 // 创建一个新的长数组
	int number = min(oldLength, newLength);     // 需要复制的元素个数，有可能是缩短

	copy(a, a + number, temp);

	delete[]a;

	a = temp;
}

template<class T>
class arrayList :public linearList<T>
{
public:
	// 构造函数和析构函数
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; };

	//// ADT方法
	inline const bool empty() { return listSize == 0; };
	inline const int size() { return listSize; };
	const T& get(int theIndex);
	const int indexOf(const T& theElement);
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	const void output(ostream& out);

	// 其他方法
	inline const int capacity() { return arrayLength; };

protected:
	const void checkIndex(int theIndex);

	T* element;
	int arrayLength;
	int listSize;
};

/// <summary>
/// 构造函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initialCapasity">初始化容量，默认为10</param>
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	//if (initialCapacity < 1)
	//{
	//	 ostringstream s;
	//	 s << initialCapacity << " Must be > 0";
	//	 s << "Initial capacity = " << initialCapacity << " Must be > 0";
	//	 throw illegalParameterValue(s.str);
	//}

	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;

	// test
	this->test = initialCapacity;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

template<typename T>
inline const T& arrayList<T>::get(int theIndex)
{
	// TODO: 在此处插入 return 语句

	return *new T;
}

template<typename T>
inline const int arrayList<T>::indexOf(const T& theElement)
{
	return 0;
}

template<typename T>
inline void arrayList<T>::erase(int theIndex)
{
}

template<typename T>
inline void arrayList<T>::insert(int theIndex, const T& theElement)
{
}

template<typename T>
inline const void arrayList<T>::output(ostream& out)
{
	return void();
}

template<class T>
inline const void arrayList<T>::checkIndex(int theIndex)
{
	return void();
}
