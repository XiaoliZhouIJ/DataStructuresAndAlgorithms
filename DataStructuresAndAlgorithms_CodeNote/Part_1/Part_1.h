/*
#ifndef PART_1			// #ifndef -- #endif �еĴ���ֻ����һ��
#define PART_1
	// / ͷ�ļ�������
#endif // !PART_1
*/

#pragma once			// ʵ������ #pragma once ����
#include <iostream>
using namespace std;

/// <summary>
/// ��1-1[�׳�]
/// �ݹ�
/// ���� n!
/// </summary>
/// <param name="n">�׳�n!</param>
/// <returns></returns>
int factorial(int n)
{
	if (n <= 1) return 1;
	else return factorial(n - 1);
}

/// <summary>
/// ��1-2 �ۼ�
/// ˳��
/// �ۼ�����Ԫ��a[0:n-1]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">����</param>
/// <param name="n">���鳤��</param>
/// <returns></returns>
template<typename T>
T sum(T a[], int n)
{
	T theSum = 0;
	for (int i = 0; i < n; i++)
		theSum += a[i];
	return theSum;
}

/// <summary>
/// ��1-2 �ۼ�
/// �ݹ�
/// �ۼ�����Ԫ��a[0:n-1]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">����</param>
/// <param name="n">���鳤��</param>
/// <returns></returns>
template<typename T>
T rSum(T a[], int n)
{
    if (n > 0)
        return rSum(a, n - 1) + a[n - 1];
    else return 0;           // ������� n = 0 ʱ����������Χa[0-1]��ϵͳ������1������Ҫ�ֶ����Ϸ���0
}

/// <summary>
/// ��1-3[����]
/// �ݹ�
/// ������Ԫ�ؽ�������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list"></param>
/// <param name="k">�ӵ�k��Ԫ�ؿ�ʼ����</param>
/// <param name="m">���鳤��</param>
template<typename T>
void permutations(T list[], int k, int m)
{
    if (k == m)
    {
        copy(list, list + m + 1, ostream_iterator<T>(cout, " "));
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            permutations(list, k + 1, m);
            swap(list[k], list[i]); // ����
        }
    }
}

/// <summary>
/// ��2-2 [˳�����]
/// ˳��
/// �������в���x�����ص�һ�γ��ֵ�λ�á����û���ҵ��򷵻�-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">����</param>
/// <param name="n">���鳤��</param>
/// <param name="x">����Ŀ��</param>
/// <returns></returns>
template<typename T>
int sequengtialSearch(T a[], int n, const T& x)
{
    int i;
    for (i = 0; i < n && a[i] != x; i++)
    {
        if (i == 0) return -1;
        else return i;
    }
}

/// <summary>
/// ��2-2 [˳�����]
/// �ݹ�
/// �������в���x�����ص�һ�γ��ֵ�λ�á����û���ҵ��򷵻�-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">����</param>
/// <param name="n">���鳤��</param>
/// <param name="x">����Ŀ��</param>
/// <returns></returns>
template<typename T>
int rSequengtialSearch(T a[], int n, const T& x)
{
    if (n < 1) return -1;                       // û���ҵ�������-1
    if (a[n - 1] == x) return n - 1;            // �ҵ�����������
    return  rSequengtialSearch(a, n - 1, x);    // �Ӻ���ǰ����������
}

/// <summary>
/// ��2-9 [���μ��㣨ranking��]
/// ˳��
/// ����Ԫ���������е�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">����</param>
/// <param name="n">���鳤��</param>
/// <param name="r">��������</param>
template<typename T>
void rank(T a[], int n, int r[])
{
    for (int i = 0; i < n; i++)
    {
        r[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (a[j] <= a[i]) r[i]++;
            else r[j]++;
        }
    }
}

/// <summary>
/// ��2-10 [����������rank sort��]
/// ˳��
/// ���ø�������ļ�������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">ԭ����</param>
/// <param name="n">���鳤��</param>
/// <param name="r">��������</param>
template<typename T>
void rearrange(T a[], int n, int r[])
{
    T* u = new T[n];

    for (int i = 0; i < n; i++)         // ��a��Ԫ���Ƶ�����ȷλ��
    {
        u[r[i]] = a[i];
    }

    for (int i = 0; i < n; i++)             // ��u��Ԫ���ƻ�a
    {
        a[i] = u[i];
    }

    delete[]u;
}

// ԭ������
template<typename T>
void rearrange_2(T a[], int n, int r[])
{
    for (int i = 0; i < n; i++)
    {
        while(r[i] != i)
        {
            int t = r[i];
            swap(a[i], a[t]);
            swap(r[i], r[t]);
        }
    }
}

/// <summary>
/// ��2-11 [ѡ������]
/// ˳��
/// ѡ������ÿ��ѭ�����������δ�������еĶ�β����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">δ��������</param>
/// <param name="n">���鳤��</param>
template<typename T>
void selectionSort(T a[], int n)
{
    for (int size = n; size > 1; size--)
    {
        int j = indexOfMax(a, size);            // ��ȡ�����������������
        swap(a[j], a[size - 1]);                // ��������ŵ���β
    }
}

// ��ʱ��ֹ��ѡ������
template<typename T>
void selectionSort_2(T a[], int n)
{
    bool sorted = false;                // ��־λ

    for (int size = n; !sorted and (size > 1); size--)      // ѭ����ֱ��ȷ���ź� �� ֻʣ���һ��Ԫ��
    {
        int indexOfMax = 0;         // ���ֵ������
        sorted = true;              // ÿ��Ĭ���ź�

        for (int i = 1; i < size; i++)
        {
            if (a[indexOfMax] <= a[i])      // �������ֵ����
            {
                indexOfMax = i;
            }
            else                            // ������ֲ����������������˵��ǰ���и������
                                            // ֻ��ÿһ�αȽ϶�������������˵��ÿһ�����������������С��Ҳ����ζ���������
                                            // sorted��־��������δfalse����ʱ��������
            {   
                sorted = false;
            }
        }

        swap(a[indexOfMax], a[size - 1]);   // (!!)����ѭ����ʱ�����ͨ����־λ����������indexOfMax = size - 1����Ӱ������
                                            // ���size == 2��indexOfMax = 1��������������
    }
}

/// <summary>
/// ��2-12 [ð������]
/// ˳��
/// ð������ÿ��ѭ�����ν��ϴ�������С����������ÿһ��������δ����������������β
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">δ��������</param>
/// <param name="n">����ð�ݵ����鳤��</param>
template<typename T>
void bubble(T a[], int n)               // һ��ð�ݹ���
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1]) 
            swap(a[i], a[i + 1]);
    }
}

template<typename T>
void bubbleSort(T a[], int n)           // ð������
{
    for (int i = n; i > 1; i--)
    {
        bubble(a, i);
    }
}

// ��ʱ��ֹ��ð������
template<typename T>
void bubble_2(T a[], int n)         // һ��ð�ݹ���
{
    bool swapped = false;           // ĿǰΪֹû�н���
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            swapped = true;
        }
    }

    return swapped;
}

template<typename T>
void bubbleSort_2(T a[], int n)           // ð������
{
    for (int i = n; i > 1 && bubble(a, i); i--)��       // ������ֱȽ�û�н��н�����bubble��������false�����ʾ�Ѿ�������ɣ�����ֱ�ӽ�������
                                                        // �����Ѿ���forѭ�������ж������
}

/// <summary>
/// ��2-14 [�����������в���Ԫ��]
/// ˳��
/// �����������в���һ����Ԫ�أ�����֮��������Ȼ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">Ŀ������</param>
/// <param name="n">���鳤��</param>
/// <param name="x">������</param>
template<typename T>
void insert(T a[], int& n, const T& x)
{
    int i;
    for (i = n - 1; i >= 0 && x < a[i]; i--)        // �Ӻ���ǰ�Ƚϣ����κ���
    {
        a[i + 1] = a[i];
    }
    a[i + 1] = x;
    n++;
}