#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>





int main() {

	int count;
	
	std::cout << "Enter the number: " << std::endl;
	std::cin >> count;

	std::ofstream file;
	file.open("result.txt");
	for (int i = 0; i < count; i++) {
		for (int j = 1; j < i; j++) {
			std::cout << 0;
			file << 0;
		}
		file <<std::endl;
		std::cout << std::endl;
	}
	file << std::endl;
	std::cout << std::endl;
	
	file.close();

	std::getchar();
	std::getchar();

	return 0;
}

