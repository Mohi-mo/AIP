#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>

int main() {

	float dx, xs, xf;
	const float eps = 0.000001; 

	std::cout << "Enter [xs, xf]: ";
	std::cin >> xs >> xf;

	std::cout << "Enter dx: ";
	std::cin >> dx;

	std::cout << "\tx\t\ty" << std::endl;

	std::cout.precision(5);
	
	float f;
	float x = xs;  
	
	std::ofstream file;
	file.open("result.txt");

	while (x < xf) {
		if (fabs(x - 2) < eps) {
			std::cout << "\t"
				<< x
				<< "\t\t Divide on zero"
				<< std::endl;
			file << "\t" << x << "\t\t Divide on zero" << std::endl;
		}
		else {
			f = (-3 + x)* (-3 + x) + 2*x + 5;

			std::cout << "\t"
				<< x
				<< "\t\t"
				<< f
				<< std::endl;
			file << "\t"<<x << "\t\t" << f << std::endl;
		}
		x += dx;
	}
	file.close();

	std::getchar();
	std::getchar();

	return 0;
}

