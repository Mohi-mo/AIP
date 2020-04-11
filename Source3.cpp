#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

//task 14(d) (11/04/2020). Find the smallest element of an array among elements with odd indices.

int min, newar;
float sum;

void fileWork() {
	std::ofstream file;
	file.open("result.txt");

	file << std::endl;
	file << "Minimum: " << min << std::endl;

	file.close();
}

int main() {

	const int n = 20;
	int array[n];
	
	srand(time(NULL));

	min = array[1];

	for (int i = 0; i < n; i++) {

		array[i] = rand() % 20 - 10;
		std::cout  << array[i]<< "; ";
		
		if (i % 2 != 0) {
			if (array[i] < min)
				min = array[i];
		}

	}
	
	std::cout << std::endl;
	std::cout << "Minimum: " << min << std::endl;

	fileWork();

	getchar();
	getchar();
	
	return 0;
}