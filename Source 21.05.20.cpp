#include <iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include <math.h>

using namespace std;

/*task 8 (21/05/20). Creation of a matrix with two lines, the first of which
characterizes the motor power, the second - its class.*/

void matrixCreator() {
	int max = 70;
	const int row = 2;
	const int col = 10;
	int matrix[row][col]; //first the row, then columns!
	
	srand(0);

	for (int i = 0; i < row; i++){ //matrix creator
		for (int j = 0; j < col; j++) {
			matrix[0][j] = rand() % 99;
			matrix[1][j] = rand() % 3 + 1;
		}
	}
	
	cout << "Engine performance matrix: " << endl;
	cout << endl;

    for(int i = 0; i<row; i++) {    //matrix output
        for(int j = 0; j<col; j++){
             cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout<<endl;

    for(int j = 0; j<col; j++) { //selector
		
        if(matrix[1][j]==3){ 

            for(int j = 0; j<col; j++){

                if(matrix[0][j]>max){

                    max=matrix[0][j];
                    cout << "Maximum: " << max << " ";
                }
            }
        }
    }
    cout << endl;
    cout << " " <<endl;
    cout << endl;
}

int main()
{
	matrixCreator();

	getchar();
	getchar();
	
	return 0;
}
