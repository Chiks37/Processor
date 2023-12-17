#include "TQueue.h"

TQueue::TQueue(const int& _size)
{
	if (_size <= 0) {
		throw 1;
	}
	size = _size;
	pMem = new int[size];
	head = 0;
	tail = size - 1;
	count = 0;
}

size_t TQueue::getCount() const
{
	return count;
}

bool TQueue::IsEmpty() const
{
	return count == 0;
}

bool TQueue::IsFull() const
{
	return size == count;
}

void TQueue::Push(const int& val)
{
	pMem[tail++] = val;
	tail %= size;
	count++;
}

int TQueue::Pop()
{
	return 0;
}
