#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>

int main() {

	int A;
	int count = 0;
	
	std::ofstream file;
	file.open("result.txt");

	std::cout << "Input A:";
	std::cin >> A;

	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (i + j + k == A)
					count++;
			}

		}
	}
	std::cout<< count <<std::endl;
	file << count << std::endl;
	
	std::getchar();
	std::getchar();

	return 0;
}

