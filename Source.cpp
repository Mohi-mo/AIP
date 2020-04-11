#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

//задача 5 (11/04/2020). Ќайти наибольший/наименьший элемент массива и его номер по пор€дку.

const int n = 20;
int array[n];
int numbmin, numbmax, min, max;

void Filework() {
	std::ofstream file;
	file.open("result.txt");

	file << "Max element: " << max << std::endl;
	file << "Min element: " << min << std::endl;

	file << "Number maximum: " << numbmax << std::endl;
	file << "Number minimum: " << numbmin << std::endl;

	file.close();
}

int main() {
	
	srand(time(NULL));
	
	min = array[0];
	max = array[0];

	for (int i = 0; i < n; i++) {

		array[i] = rand() % 20 - 10;
		std::cout << array[i] << "; ";
		//file << array[i] << "; ";

		if (array[i]>max){
			max = array[i];
			numbmax = i;
		}

		if (array[i] < min) {
			min = array[i];
			numbmin = i;
		}
	}

	std::cout << std::endl;
	std::cout<<"Max element: " << max << std::endl;
	std::cout <<"Min element: "<< min << std::endl;
	
	std::cout<<std::endl;
	std::cout << "Number maximum: " << numbmax << std::endl;
	std::cout << "Number minimum: " << numbmin << std::endl;
	
	Filework();

	getchar();
	getchar();
	
	return 0;
}