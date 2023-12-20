#include "TStatus.h"

TStatus::TStatus(int _tact, int _intensity, int _counter, int _power) : queue(_counter), taskStream(_intensity), proc(_power), incoming(0), wait(0), ignored(0), completed(0)
{
	if (_tact < 0)
		throw 4;
	tact = _tact;
}

void TStatus::process()
{
	std::cout << "Starting task completing...\n\n";

	bool prev = false;

	if (tact > 20) {

		for (int i = 0; i < tact; i++) {

			if (taskStream.isNewTask()) {

				if (!queue.IsFull()) {

					queue.Push(incoming);
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
					prev = true;
				}

				else {
					prev = false;
					wait++;
				}

			}

		}

	}

	else {

		for (int i = 0; i < tact; i++) {

			std::cout << i << ": ";

			if (taskStream.isNewTask()) {

				std::cout << "New task!";

				if (!queue.IsFull()) {

					std::cout << " Is added to queue.\n";

					queue.Push(incoming);
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

					std::cout << " and took a task #" << queue.Pop() << "\n";
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

	bool err5Flag = false;

	std::cout << "Camed tasks count - " << incoming << std::endl;

	if (ignored == 0 && incoming == 0) {
		err5Flag = true;
		std::cout << "Ignored tasks percent - undefined value.\n";
	}
	else {
		std::cout << "Ignored tasks percent - " << (double)ignored * 100 / (double)(ignored + incoming) << "%\n";
	}

	if (completed == 0) {
		err5Flag = true;
		std::cout << "Average completing tasks time - undefined value.\n";
	}
	else {
		std::cout << "Average completing tasks time - " << (double)(tact - wait) / (double)completed << std::endl;
	}

	if (tact == 0) {
		err5Flag = true;
		std::cout << "Delayed tasks percent - undefined value.\n";
	}
	else {
		std::cout << "Delayed tasks percent - " << (double)wait * 100 / (double)tact << "%\n";
	}

	if (err5Flag)
		throw 5;
}
