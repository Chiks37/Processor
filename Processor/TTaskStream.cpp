#include "TTaskStream.h"

TTaskStream::TTaskStream(const int& _intencity) : intencity(_intencity)
{
}

bool TTaskStream::isNewTask()
{
	int num = rand() % 100;
	return (num < intencity);
}
