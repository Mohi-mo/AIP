#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

/*task 1(d) 2(a,b,c) (18/04/2020). Generate an array with random numbers in the range [-70;50]. 
Create a program that will count the number of shuffling actions. 
Analyze the dependence of the number of permutations on the number of elements in an array.*/

int iterPermutationsSort1 = 0;
int iterPermutationsSort = 0;
int iterSort = 0;

void insertionSort(int array[], int n) {
	
	float key = 0;
	int j;

	for (int i = 1; i < n; i++){
		
		key = array[i]; 
		j = i - 1;
		

		while (j >= 0 && array[j] > key){
			
			array[j + 1] = array[j];
			j = j - 1;
			array[j + 1] = key;
			iterSort += 1;

		}
	}
	std::cout << std::endl;
	std::cout << "Number of permutations for insertion sort: " << iterSort << std::endl;
	
}

void selelctSort(int array[], int n) {
	
	int j = 0;
	int passing = 0;
	
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
	std::cout << "Number of permutations for selection sort: " << iterPermutationsSort << std::endl;
}

void bubbleSort(int array[], int n){
	
	float passing = 0;
	
	for (int i = 0; i < n; i++) {
		
		for (int j = n - 1; j >= i + 1; j--) {

			if (array[j] < array[j - 1]) {  
				
				passing = array[j];
				array[j] = array[j - 1];
				array[j - 1] = passing;
				iterPermutationsSort1 += 1;

			}
		}
	}
	std::cout << std::endl;
	std::cout << "Number of permutations for bubbles sort: " << iterPermutationsSort1 << std::endl;
}

void fileWork(int iterSort, int iterPermutationsSort, int iterPermutationsSort1) {
	std::ofstream file;
	file.open("result.txt");

	file << "Number of permutations for insertion sort: " << iterSort << std::endl
		<< "Number of permutations for selection sort: " << iterPermutationsSort << std::endl
		<< "Number of permutations for bubbles sort: " << iterPermutationsSort1 << std::endl;

	file.close();
}

void sorts(int array[], int n) {

	//selelctSort(array, n); //375 Permutations. n = 120.
	insertionSort(array, n); // 3573 Permutations. n = 120.
	//bubbleSort(array, n); // 3573 Permutations. n = 120.

}

int main() {

	const int n = 120;
	int array[n];
	
	srand(100);
	
	for (int i = 0; i < n; i++){

		array[i] = rand() % 121 - 70;
		std::cout << array[i] << " ";

	}
	
	std::cout << std::endl << std::endl;
	sorts(array, n);
	
	fileWork(iterSort, iterPermutationsSort, iterPermutationsSort1);

	std::cout << std::endl << std::endl;
	for (int i = 0; i < n; i++){

		std::cout << array[i] << " ";

	}

	

	getchar();
	getchar();
	
	return 0;
}

/* при выполнении заметил, что сортировка выбором быстрее, чем вставками и пузырьками в силу того, 
что для последних двух способов требуется несколько проходов по массиву и перестановок*/
