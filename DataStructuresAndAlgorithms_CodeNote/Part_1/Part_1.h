/*
#ifndef PART_1			// #ifndef -- #endif 中的代码只编译一次
#define PART_1
	// / 头文件的内容
#endif // !PART_1
*/

#pragma once			// 实际上用 #pragma once 就行
#include <iostream>
using namespace std;

/// <summary>
/// 例1-1[阶乘]
/// 递归
/// 计算 n!
/// </summary>
/// <param name="n">阶乘n!</param>
/// <returns></returns>
int factorial(int n)
{
	if (n <= 1) return 1;
	else return factorial(n - 1);
}

/// <summary>
/// 例1-2 累加
/// 顺序
/// 累加数组元素a[0:n-1]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">数组</param>
/// <param name="n">数组长度</param>
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
/// 例1-2 累加
/// 递归
/// 累加数组元素a[0:n-1]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">数组</param>
/// <param name="n">数组长度</param>
/// <returns></returns>
template<typename T>
T rSum(T a[], int n)
{
    if (n > 0)
        return rSum(a, n - 1) + a[n - 1];
    else return 0;           // 不加这句 n = 0 时超出索引范围a[0-1]，系统返回了1，所以要手动加上返回0
}

/// <summary>
/// 例1-3[排列]
/// 递归
/// 对数组元素进行排列
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list"></param>
/// <param name="k">从第k个元素开始排列</param>
/// <param name="m">数组长度</param>
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
            swap(list[k], list[i]); // 回溯
        }
    }
}

/// <summary>
/// 例2-2 [顺序查找]
/// 顺序
/// 从数组中查找x，返回第一次出现的位置。如果没有找到则返回-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">数组</param>
/// <param name="n">数组长度</param>
/// <param name="x">查找目标</param>
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
/// 例2-2 [顺序查找]
/// 递归
/// 从数组中查找x，返回第一次出现的位置。如果没有找到则返回-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">数组</param>
/// <param name="n">数组长度</param>
/// <param name="x">查找目标</param>
/// <returns></returns>
template<typename T>
int rSequengtialSearch(T a[], int n, const T& x)
{
    if (n < 1) return -1;                       // 没有找到，返回-1
    if (a[n - 1] == x) return n - 1;            // 找到，返回索引
    return  rSequengtialSearch(a, n - 1, x);    // 从后往前，继续查找
}

/// <summary>
/// 例2-9 [名次计算（ranking）]
/// 顺序
/// 返回元素在序列中的名次
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">数组</param>
/// <param name="n">数组长度</param>
/// <param name="r">名次序列</param>
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
/// 例2-10 [按名次排序（rank sort）]
/// 顺序
/// 利用附加数组的计数排序
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">原数组</param>
/// <param name="n">数组长度</param>
/// <param name="r">排序数组</param>
template<typename T>
void rearrange(T a[], int n, int r[])
{
    T* u = new T[n];

    for (int i = 0; i < n; i++)         // 把a中元素移到中正确位置
    {
        u[r[i]] = a[i];
    }

    for (int i = 0; i < n; i++)             // 把u中元素移回a
    {
        a[i] = u[i];
    }

    delete[]u;
}

// 原地重排
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
/// 例2-11 [选择排序]
/// 顺序
/// 选择排序，每趟循环将最大数与未排序数列的队尾交换
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">未排序数组</param>
/// <param name="n">数组长度</param>
template<typename T>
void selectionSort(T a[], int n)
{
    for (int size = n; size > 1; size--)
    {
        int j = indexOfMax(a, size);            // 获取数组中最大数的索引
        swap(a[j], a[size - 1]);                // 将最大数放到队尾
    }
}

// 及时终止的选择排序
template<typename T>
void selectionSort_2(T a[], int n)
{
    bool sorted = false;                // 标志位

    for (int size = n; !sorted and (size > 1); size--)      // 循环，直到确认排好 或 只剩最后一个元素
    {
        int indexOfMax = 0;         // 最大值的索引
        sorted = true;              // 每轮默认排好

        for (int i = 1; i < size; i++)
        {
            if (a[indexOfMax] <= a[i])      // 更新最大值索引
            {
                indexOfMax = i;
            }
            else                            // 如果出现不更新索引的情况则说明前端有更大的数
                                            // 只有每一次比较都更新了索引，说明每一个数都比它后面的数小，也就意味着排序完成
                                            // sorted标志不被更新未false，此时结束排序
            {   
                sorted = false;
            }
        }

        swap(a[indexOfMax], a[size - 1]);   // (!!)结束循环的时候，如果通过标志位结束排序，则indexOfMax = size - 1，不影响排序
                                            // 如果size == 2，indexOfMax = 1，则正常交换。
    }
}

/// <summary>
/// 例2-12 [冒泡排序]
/// 顺序
/// 冒泡排序，每趟循环依次将较大的数与较小的数交换，每一趟最后将最大未排序的最大数移至队尾
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">未排序数组</param>
/// <param name="n">进行冒泡的数组长度</param>
template<typename T>
void bubble(T a[], int n)               // 一次冒泡过程
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1]) 
            swap(a[i], a[i + 1]);
    }
}

template<typename T>
void bubbleSort(T a[], int n)           // 冒泡排序
{
    for (int i = n; i > 1; i--)
    {
        bubble(a, i);
    }
}

// 及时终止的冒泡排序
template<typename T>
void bubble_2(T a[], int n)         // 一次冒泡过程
{
    bool swapped = false;           // 目前为止没有交换
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
void bubbleSort_2(T a[], int n)           // 冒泡排序
{
    for (int i = n; i > 1 && bubble(a, i); i--)；       // 如果本轮比较没有进行交换，bubble函数返回false，则表示已经排序完成，可以直接结束排序
                                                        // 排序已经在for循环条件判断中完成
}

/// <summary>
/// 例2-14 [在有序数组中插入元素]
/// 顺序
/// 在有序数组中插入一个新元素，插入之后数组依然有序
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a">目标数组</param>
/// <param name="n">数组长度</param>
/// <param name="x">插入数</param>
template<typename T>
void insert(T a[], int& n, const T& x)
{
    int i;
    for (i = n - 1; i >= 0 && x < a[i]; i--)        // 从后向前比较，依次后移
    {
        a[i + 1] = a[i];
    }
    a[i + 1] = x;
    n++;
}