#pragma once
#include <iostream>
using namespace std;

// �Զ����쳣��
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