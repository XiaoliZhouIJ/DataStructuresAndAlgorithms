#pragma once
#include <iostream>
#include "IllegalParameterValue.h"

using namespace std;

/* ------------------------------ linearList类 ------------------------------*/
#pragma region lineaerList
/// <summary>
/// 线性表
/// </summary>
/// <typeparam name="T"></typeparam>
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
#pragma endregion

/* ------------------------------ changeLength1D函数 ------------------------------*/
#pragma region changeLength1D
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
	{
		// throw illegalParameterValue("new length must >= 0");            // illegalParameterValue是自定类
		throw illegalParameterValue("new lengtj must >= 0");
	}

	T* temp = new T[newLength];                 // 创建一个新的长数组
	int number = min(oldLength, newLength);     // 需要复制的元素个数，有可能是缩短

	copy(a, a + number, temp);

	delete[]a;

	a = temp;
}
#pragma endregion


/* ------------------------------ arrayList类 ------------------------------*/
#pragma region arrayList
/// <summary>
/// 用数组实现的线性表
/// </summary>
/// <typeparam name="T"></typeparam>
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
	//	 throw illegalParameterValue(s.str());
	//}

	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;

	// test
	this->test = initialCapacity;
}
/// <summary>
/// 拷贝构造函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theList"></param>
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

/// <summary>
/// 获取索引元素
/// 时间复杂度 Setae(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
/// <returns></returns>
template<typename T>
inline const T& arrayList<T>::get(int theIndex)
{
	checkIndex(theIndex);
	return element[theIndex];
}

/// <summary>
/// 查询元素所在索引
/// 时间复杂度 O(max{listSize,1}) =简写=> O(listSize)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theElement"></param>
/// <returns></returns>
template<typename T>
inline const int arrayList<T>::indexOf(const T& theElement)
{
	int theIndex = int(find(element, element + listSize, theElement) - element);		// 查找元素theElement

	if (theIndex == listSize)		// 元素未找到
		return -1;
	else							// 找到
		return theIndex;
}

/// <summary>
/// 删除其索引为theIndex的元素
/// 异常抛出时，时间复杂度 Setae(1)
/// 正常运行时，时间复杂度 Setae(listSiuze-theIndex)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
template<typename T>
inline void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);			// 元素不存在则抛出异常

	copy(element + theIndex + 1, element + listSize, element + theIndex);		// 有效索引，移动其索引大于theIndex的元素

	element[--listSize].~T();			// 最后一位已删除，调用析构函数
}

/// <summary>
/// 在索引theIndex处插入元素theElement
/// 异常抛出时，时间复杂度 Setae(1)
/// 正常运行时，时间复杂度 数组倍长: Setae(arrayLength) == Setae(listSize)
///						 移动元素: Setae(listSize - theIndex)
///			 总时间复杂度 O(litSize)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
/// <param name="theElement"></param>
template<typename T>
inline void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)		// checkIndex函数检查 theIndex >= listSize
		// 插入时可以等于listSize，相当于在尾部追加
	{
		//ostringstream s;
		//s << "index = " << theIndex << "size = " << listSize;
		//throw illegalIndex(s.str());
	}

	// 有效索引，确定数组是否已满
	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);		// 数组空间倍长
	}

	// 元素向右移动
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;

	listSize++;
}

template<typename T>
inline const void arrayList<T>::output(ostream& out)
{
	copy(element, element + listSize, ostream_iterator<T>(cout, ""));
}

/// <summary>
/// 检查索引是否在可查询范围内
/// 时间复杂度 Setae(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
/// <returns></returns>
template<typename T>
inline const void arrayList<T>::checkIndex(int theIndex)
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		//ostringstream s;
		//s << "index = " << theIndex << "size = " << listSize;
		//throw illegalIndex(s.str());
	}
}

/// <summary>
/// 把线性表插入输出流
/// 假设插入一个线性表的时间是O(1)，那么output的时间是O(listSize)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="x"></param>
/// <returns></returns>
template<typename T>
ostream& operator << (ostream& out, const arrayList<T>& x)
{
	x.output(out);
	return out;
}
#pragma endregion


/* ------------------------------ myIterator类 ------------------------------*/
#pragma region myIterator
/// <summary>
/// arrayList的一个迭代器
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class myIterator
{
public:
	// 用C++的typedef语句实现双向迭代器
	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	// 构造函数
	myIterator(T* thePosition = 0)
	{
		position = thePosition;
	}

	// 解引用操作符
	inline const T& operator*() { return *position; }
	inline const T* operator->() { return &*position; }

	// 迭代器的值增加
	inline myIterator& operator++();		// 前加
	inline myIterator operator++(int);		// 后加


	// 迭代器的值减少
	inline myIterator& operator--();		// 前减
	inline myIterator operator--(int);		// 后减

	// 测试是否相等
	inline const bool operator!= (const myIterator right) { return position != right.position; }
	inline const bool operator== (const myIterator right) { return position == right.position; }

protected:
	T* position;			// 指向表元素的指针
};

template<typename T>
inline myIterator<T>& myIterator<T>::operator++()
{
	++position;
	return *this;
}

template<typename T>
inline myIterator<T> myIterator<T>::operator++(int)
{
	myIterator old = *this;
	++position;
	return old;
}

template<typename T>
inline myIterator<T>& myIterator<T>::operator--()
{
	--position;
	return *this;
}

template<typename T>
inline myIterator<T> myIterator<T>::operator--(int)
{
	myIterator<T> old = *this;
	--position;
	return old;
}
#pragma endregion


