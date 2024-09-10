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
/// �ı�һ��һά���鳤��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">ԭ����</param>
/// <param name="oldLength">�ɳ���</param>
/// <param name="newLength">�³���</param>
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must >= 0");            // illegalParameterValue���Զ���

	T* temp = new T[newLength];                 // ����һ���µĳ�����
	int number = min(oldLength, newLength);     // ��Ҫ���Ƶ�Ԫ�ظ������п���������

	copy(a, a + number, temp);

	delete[]a;

	a = temp;
}

template<class T>
class arrayList :public linearList<T>
{
public:
	// ���캯������������
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; };

	//// ADT����
	inline const bool empty() { return listSize == 0; };
	inline const int size() { return listSize; };
	const T& get(int theIndex);
	const int indexOf(const T& theElement);
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	const void output(ostream& out);

	// ��������
	inline const int capacity() { return arrayLength; };

protected:
	const void checkIndex(int theIndex);

	T* element;
	int arrayLength;
	int listSize;
};

/// <summary>
/// ���캯��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initialCapasity">��ʼ��������Ĭ��Ϊ10</param>
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
	// TODO: �ڴ˴����� return ���

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
