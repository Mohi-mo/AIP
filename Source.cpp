#include <iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include <math.h>

using namespace std;   

/*task 1 (21/05/2020). Matrix conversion: elements of the column 
where the minimum is located matrix element, replace with zeros.*/

void matrixCreate() {
	const int rows = 7;
	const int cols = 8;
	int matrix[rows][cols];  //first the rows, then the columns!

	srand(0);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = rand() % 100 - 50; //matrix creator

	cout << "Old matrix: " << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;  // Old matrix output
	}

	int min = matrix[0][0]; //min element 
	int mr = 0, mc = 0; //coordinator 

	for (int i = 0; i < rows; i++) //find minimum
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] < min) {
				min = matrix[i][j];
				mr = i;
				mc = j;
			}

	for (int i = 0; i < cols; i++) //zeroing :D
		matrix[mr][i] = 0;  
	
	cout << endl;
	cout <<"Minimum element: " << min << "\t" 
		<< "Row: " << mr+1 <<"\t"
		<< "Columns: " << mc+1 << endl;
	cout << endl;
	
	cout << "New matrix: " << endl;

	for (int i = 0; i < rows; i++) { //New matrix output
		for (int j = 0; j < cols; j++)
			cout << matrix[i][j] << "\t";
		
		cout << endl;
	}

}

int main() {

	matrixCreate();

	getchar();
	getchar();

	return 0;
}

