#include <iostream>

int main() {
	
	float a, cube, quad;
	

	std::cout << "Please, insert the number: " << std::endl;
	std::cin >> a;
	
	quad = a * a;
	cube = quad * a;

	std::cout << quad << std::endl
			  << cube << std::endl;
	
	std::getchar();
	std::getchar();
	
	return 0;
}