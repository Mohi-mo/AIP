#include <iostream>

int main() {
	
	float a, b,res,res2;

	std::cout << "Enter your prices: "<<std::endl; 
	std::cin >> a >> b;

	res = (a * 0.3) + (b * 0.4); // a)

	res2 = ((a * 1.8) + (b * 2)) * 3; //b)

	std::cout << "Result:" << res <<std::endl
						<< res2 << std::endl;

	std::getchar();
	std::getchar();
	
	return 0;
}