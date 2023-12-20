#include "TProc.h"

TProc::TProc(const int& _power)
{
	if (_power < 0)
		throw 3;
	power = _power;
}

bool TProc::IsFree(bool prev)
{
	bool res = true;
	if (prev) {
		int num = rand() % 100;
		res = num < power;
	}
	return res;
}
