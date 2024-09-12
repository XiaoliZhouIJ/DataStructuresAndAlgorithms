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
	//	 throw illegalParameterValue(s.str());
	//}

	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;

	// test
	this->test = initialCapacity;
}
/// <summary>
/// �������캯��
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
/// ��ȡ����Ԫ��
/// ʱ�临�Ӷ� Setae(1)
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
/// ��ѯԪ����������
/// ʱ�临�Ӷ� O(max{listSize,1}) =��д=> O(listSize)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theElement"></param>
/// <returns></returns>
template<typename T>
inline const int arrayList<T>::indexOf(const T& theElement)
{
	int theIndex = int(find(element, element + listSize, theElement) - element);		// ����Ԫ��theElement

	if (theIndex == listSize)		// Ԫ��δ�ҵ�
		return -1;
	else							// �ҵ�
		return theIndex;
}

/// <summary>
/// ɾ��������ΪtheIndex��Ԫ��
/// �쳣�׳�ʱ��ʱ�临�Ӷ� Setae(1)
/// ��������ʱ��ʱ�临�Ӷ� Setae(listSiuze-theIndex)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
template<typename T>
inline void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);			// Ԫ�ز��������׳��쳣

	copy(element + theIndex + 1, element + listSize, element + theIndex);		// ��Ч�������ƶ�����������theIndex��Ԫ��

	element[--listSize].~T();			// ���һλ��ɾ����������������
}

/// <summary>
/// ������theIndex������Ԫ��theElement
/// �쳣�׳�ʱ��ʱ�临�Ӷ� Setae(1)
/// ��������ʱ��ʱ�临�Ӷ� ���鱶��: Setae(arrayLength) == Setae(listSize)
///						 �ƶ�Ԫ��: Setae(listSize - theIndex)
///			 ��ʱ�临�Ӷ� O(litSize)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
/// <param name="theElement"></param>
template<typename T>
inline void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)		// checkIndex������� theIndex >= listSize
													// ����ʱ���Ե���listSize���൱����β��׷��
	{
		//ostringstream s;
		//s << "index = " << theIndex << "size = " << listSize;
		//throw illegalIndex(s.str());
	}

	// ��Ч������ȷ�������Ƿ�����
	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);		// ����ռ䱶��
	}

	// Ԫ�������ƶ�
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;

	listSize++;
}

template<typename T>
inline const void arrayList<T>::output(ostream& out)
{
	return void();
}

/// <summary>
/// ��������Ƿ��ڿɲ�ѯ��Χ��
/// ʱ�临�Ӷ� Setae(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="theIndex"></param>
/// <returns></returns>
template<class T>
inline const void arrayList<T>::checkIndex(int theIndex)
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		//ostringstream s;
		//s << "index = " << theIndex << "size = " << listSize;
		//throw illegalIndex(s.str());
	}
}
