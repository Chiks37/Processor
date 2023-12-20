#include "TStatus.h"

int main() {
	srand(time(0));
	try {
		TStatus status(10, 90, 3, -10); //(tacts, intencity, queue size, power)
		status.process();
	}
	catch (int& e) {
		std::cout << "Error. ";
		switch (e) {
		case 1:
			std::cout << "Queue size is incorrect.\n";
			break;
		case 2:
			std::cout << "Intencity is incorrect.\n";
			break;
		case 3:
			std::cout << "Power is incorrect.\n";
			break;
		case 4:
			std::cout << "Tacts count is incorrect.\n";
			break;
		case 5:
			std::cout << "Divide by zero.\n";
			break;
		default:
			std::cout << "\n";
			//std::cout << "Error.\n";
			break;
		}
	}
}