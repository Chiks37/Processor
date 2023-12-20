#include "TQueue.h"

TQueue::TQueue(const int& _size)
{
	if (_size < 0) {
		throw 1;
	}
	size = _size;
	pMem = new int[size];
	head = 0;
	tail = 0;
	count = 0;
}

TQueue::TQueue(const TQueue& que2)
{
	size = que2.size;
	count = que2.count;
	head = que2.head;
	tail = que2.tail;
	pMem = new int[size];
	for (int i = 0; i < size; i++) {
		pMem[i] = que2.pMem[i];
	}
}

TQueue::~TQueue()
{
	delete[] pMem;
}

size_t TQueue::getCount() const
{
	return count;
}

TQueue& TQueue::operator=(const TQueue& que2)
{
	return *this;
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
	pMem[tail] = val;
	tail = (tail + 1) % size;
	count++;
}

int TQueue::Pop()
{
	int res = pMem[head];
	head = (head + 1) % size;
	count--;
	return res;
}
