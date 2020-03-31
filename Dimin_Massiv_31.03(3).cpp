#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

int main() {

	const int n = 10;
	int array[n];
	int max=0 , min=10, itermax = 0, itermin = 0;
	srand(time(NULL));
	
	for (int i = 0; i < n; i++){
		
		array[i] = rand() % 20 - 10;
		
		std::cout << array[i] << ", ";
		
		if (abs(array[i]) > max){
			max = abs(array[i]);
			itermax = i;
		}
		if (abs(array[i]) < min){
			min = abs(array[i]);
			itermin = i;
		}

	}

	std::cout<<std::endl;
	std::cout<<"Number maximum: "<<itermax<<std::endl;
	std::cout<<"Number minimum: "<<itermin<<std::endl;

	getchar();
	getchar();
	
	return 0;
}