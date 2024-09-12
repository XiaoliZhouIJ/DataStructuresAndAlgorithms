#pragma once
#include <iostream>
using namespace std;

// 自定义异常类
class illegalParameterValue
{
public:
	illegalParameterValue() :
		message("Illegal parameter value") {}
	illegalParameterValue(char* theMessage)
	{
		message = theMessage;
	}
private:
	string message;
};


class illegalIndex
{
public:
	illegalIndex() :
		message("Illegal parameter value") {}
	illegalIndex(char* theMessage)
	{
		message = theMessage;
	}

private:
	string message;
};
