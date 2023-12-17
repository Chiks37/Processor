#include "TStatus.h"

TStatus::TStatus(int _tact, int _intensity, int _counter, int _power) : queue(_counter), taskStream(_intensity), proc(_power), tact(_tact), incoming(0), wait(0), ignored(0), completed(0)
{
}

void TStatus::process()
{
	std::cout << "Starting task completing...\n";

	if (tact > 20) {

		for (int i = 0; i < tact; i++) {

			bool prev = false;

			if (taskStream.isNewTask()) {

				if (!queue.IsFull()) {

					queue.Push(i);
					prev = true;
					incoming++;

				}

				else {
					ignored++;
				}

			}

			if (proc.IsFree(prev)) {

				if (!queue.IsEmpty()) {
					queue.Pop();
					completed++;
				}
				
				else {
					wait++;
				}

			}

		}

	}
	
	else {
		for (int i = 0; i < tact; i++) {

			bool prev = false;
			std::cout << i << ": ";

			if (taskStream.isNewTask()) {

				std::cout << "New task!";

				if (!queue.IsFull()) {

					std::cout << " Is added to queue.\n";

					queue.Push(i);
					prev = true;
					incoming++;

				}

				else {
					std::cout << " Is ignored, because queue is full.\n";
					ignored++;
				}

			}

			else {
				std::cout << "There is no any new tasks.\n";
			}

			if (proc.IsFree(prev)) {

				std::cout << "Processor is free";

				if (!queue.IsEmpty()) {

					std::cout << " and took a task.\n";

					queue.Pop();
					prev = true;
					completed++;

				}

				else {

					std::cout << ", but there is no any waiting tasks. Processor is still free.\n";
					wait++;
					prev = false;
				}

			}

			else {
				std::cout << "Processor is busy.\n";
			}

			std::cout << std::endl;
		}

	}
	
	std::cout << "Camed tasks count - " << incoming << std::endl;
	std::cout << "Ignored tasks percent - " << (double)ignored * 100 / (double)(ignored + incoming) << "%\n";
	std::cout << "Average completing tasks time - " << (double)(tact - wait) / (double)completed << std::endl;
	std::cout << "Delayed tasks percent - " << (double)wait * 100 / (double)tact  << "%\n";
}
