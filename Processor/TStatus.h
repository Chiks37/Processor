#pragma once
#include "TQueue.h"
#include "TTaskStream.h"
#include "TProc.h"

class TStatus
{
	TQueue queue;
	TTaskStream taskStream;
	TProc proc;
	int tact, incoming, wait, ignored, completed;
public:
	TStatus(int _tact, int _intensity, int _counter, int _power);
	void process();
};

