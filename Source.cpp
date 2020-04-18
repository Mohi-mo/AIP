#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

//task 1(d) 2(a,b) (18/04/2020). Generate an array with random numbers in the range [-70;50].

void insertionSort(int array[], int n) {
	
	float key = 0;
	int j, iterIsort = 0;

	for (int i = 1; i < n; i++){
		
		key = array[i]; 
		j = i - 1;
		iterIsort += 1;

		while (j >= 0 && array[j] > key){
			
			array[j + 1] = array[j];
			j = j - 1;
			array[j + 1] = key;
		}
		
	}
	
	std::cout << std::endl;
	std::cout << "Number of permutations: " << iterIsort << std::endl;

}

void selelctSort(int array[], int n) {
	int j = 0;
	int passing = 0;
	int iterPermutationsSort = 0;
	
	for (int i = 0; i < n; i++){
		
		j = i;

		for (int k = i; k < n; k++){

			if (array[j] > array[k]){

				j = k;
				iterPermutationsSort += 1;

			}
		}

		passing = array[i];
		array[i] = array[j];
		array[j] = passing;

	}

	std::cout<<std::endl;
	std::cout << "Number of permutations: " << iterPermutationsSort << std::endl;

}

void fileWork() {
	std::ofstream file;
	file.open("result.txt");
	file.close();
}

int main() {
	
	const int n = 1200;
	int array[n];
	
	srand(100);
	
	for (int i = 0; i < n; i++){

		array[i] = rand() % 121 - 70;
		std::cout << array[i] << " ";

	}
	
	//selelctSort(array, n); //

	insertionSort(array, n); // 
	
	std::cout << std::endl << std::endl;
	
	for (int i = 0; i < n; i++){

		std::cout << array[i] << " ";

	}

	//fileWork();


	getchar();
	getchar();
	
	return 0;
}
/* при выполнении заметил, что сортировка вставками быстрее подбором, разница была примерно 256 перестановок*/