#define _CRT_SECURE_NO_WARNINGS 1
#include "Part_1.h"
#include "Part_2.h"

int main()
{
	// 创建两个容量为100的线性表
	linearList<int>* x = new arrayList<int>(100);
	arrayList<double> y(100);	
	// 利用容量的缺省值创建一个线性表
	arrayList<char>z;
	// 用线性表要复制创建一个线性表
	arrayList<double> w(y);

	cout << x->test << endl;

    return 0;
}
