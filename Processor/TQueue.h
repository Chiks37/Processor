#pragma once
#include <vector>
class TQueue
{
	size_t size;
	size_t count;
	int head;
	int tail;
	int* pMem;

public:
	TQueue(const int& _size);
	size_t getCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(const int& val);
	int Pop();
};

