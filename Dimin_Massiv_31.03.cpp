#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>

int main() {
	
	const int max=30;
	int array[max];

	srand(300);

	for (int i = -10; i <= max; i++) {
		array[i] = rand() % 31-10;
		std::cout << array[i]<<std::endl;
	}

	getchar();
	getchar();

	return 0;
}
