#include "TStatus.h"

int main() {
	srand(time(0));
	try {
		TStatus status(10, 50, 3, 50);
		status.process();
	}
	catch (int& e) {
		if (e == 1) {
			std::cout << "Tacts count is incorrect.\n";
		}
		else {
			std::cout << "Unknown error.\n";
		}
	}
}