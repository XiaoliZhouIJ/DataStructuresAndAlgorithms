#define _CRT_SECURE_NO_WARNINGS 1
#include "Part_1.h"
#include "Part_2.h"

int main()
{
	// ������������Ϊ100�����Ա�
	linearList<int>* x = new arrayList<int>(100);
	arrayList<double> y(100);	
	// ����������ȱʡֵ����һ�����Ա�
	arrayList<char>z;
	// �����Ա�Ҫ���ƴ���һ�����Ա�
	arrayList<double> w(y);

	cout << x->test << endl;

    return 0;
}
