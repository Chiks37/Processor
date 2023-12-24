#include "TTaskStream.h"

TTaskStream::TTaskStream(const int& _intencity)
{
	if (_intencity < 0 || _intencity > 100)
		throw 2;
	intencity = _intencity;
}

bool TTaskStream::isNewTask()
{
	int num = rand() % 100;
	return (num < intencity);
}
