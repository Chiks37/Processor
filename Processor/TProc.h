#pragma once
#include <iostream>

class TProc
{
	int power;
public:
	TProc(const int& _power);
	bool IsFree(bool prev);
};

