#include <iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include <math.h>

using namespace std;

/*task 3(d) 4 and 5 (25/04/2020). Declare the essence and describe its properties. 
Declare entity arrays. Fill attributes with numerical and text values (define the range of values yourself).
Analyze the dependence of the number of permutations on the number of elements in an array.
For each of the arrays, implement a key (structure attribute) search.
For each of the arrays to implement sorting one key.*/

struct Plant {

	string name;
	float weight, caloricValue;
	char vitamins;
	
};

void selelctSort(Plant fruits[], int n) {
	
	int j = 0;
	Plant tmp;
	
	for(int i = 0; i < n; i++){
		
		j = i;

		for (int k = i; k < n; k++){

			if (fruits[j].caloricValue > fruits[k].caloricValue){

				j = k;
			
			}
		}
		tmp = fruits[i];
		fruits[i] = fruits[j];
		fruits[j] = tmp;
	}
}

void fileWork(const Plant parametrs[], const int n) {
	std::ofstream file;
	file.open("result.txt");

	for (int i = 0; i < n; i++) {
		file << parametrs[i].name << "\t"
			<< parametrs[i].caloricValue << "\t"
			<< parametrs[i].vitamins << "\t"
			<< parametrs[i].weight << "\t"
			<< endl;
	}
	file.close();
}

void namesCreate(string& str) {
	static const char alphabet[] =
		"ABCDEFGHIGKLMNOPQRSTUVWXYZ"
		"abcdefghigklmnopqrstuvwxyz"
		"1234567890";

	str = "  ";
	for (int i = 0; i < str.length(); i++) {
		
		int r = rand() % (sizeof(alphabet) - 1);
		str[i] = alphabet[r];

	}
	str[str.length()] = 0;
}

void showParFruit(const Plant parametrs) {
	cout << parametrs.name << "\t"
		<< parametrs.caloricValue << "\t"
		<< parametrs.vitamins << "\t"
		<< parametrs.weight << "\t"
		<< endl;
}

void caloriesSearch(const Plant parametrs[]) {

	const float calkey = 250.75;
	const int lim = 1000;

	for (int i = 0; i < lim; i++) {
		if (parametrs[i].caloricValue >= calkey)
			showParFruit(parametrs[i]);
	}
}

void vitaminsSearch(const Plant parametrs[]){

	const int vKey = 233;
	const int lim1 = 256;

	for (int i = 197; i < lim1; i++) {
		if (parametrs[i].vitamins < vKey) {
			showParFruit(parametrs[i]);
		}
	}
}


int main() {

	const int n = 256;
	Plant fruits[n];
	
	srand(100);

	for (int i = 0; i < n; i++) { 

		fruits[i].caloricValue = rand() % 1000;
		fruits[i].weight = (float) 1000 * rand() / RAND_MAX;
		fruits[i].vitamins = (char)i;
		showParFruit(fruits[i]);
		namesCreate(fruits[i].name);

	}
	
	selelctSort(fruits, n);

	for (int i = 0; i < n; i++)
		showParFruit(fruits[i]);

	fileWork(fruits, n);

	getchar();
	getchar();
	
	return 0;
}

/* ïðè âûïîëíåíèè âîçíèêëà íåèçâåñòíîãî ðîäà îøèáêà*/
