#include <iostream>
using namespace std;

void MatrixOutput(int **squareMatrix, int squareMatrixSize) {
	for(int i = 0; i < squareMatrixSize; i++)
	{
		for(int j = 0; j < squareMatrixSize; j++) cout << squareMatrix[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int squareMatrixSize;
	int **squareMatrix;
	
	cin >> squareMatrixSize;

	squareMatrix = new int* [squareMatrixSize];
	for(int i = 0; i < squareMatrixSize; i++) squareMatrix[i] = new int [squareMatrixSize];
	
	for(int i = 0; i < squareMatrixSize; i++)
		for(int j = 0; j < squareMatrixSize; j++)
			cin >> squareMatrix[i][j];

	cout << endl;
	MatrixOutput( squareMatrix, squareMatrixSize );
	
	int borderOfNulling = 1;
	for(int i = 0; i < squareMatrixSize-1; i++, borderOfNulling++)
	for(int j = squareMatrixSize-1; j >= borderOfNulling; j--)
		squareMatrix[i][j] = 0;

	cout << endl;
	MatrixOutput( squareMatrix, squareMatrixSize );
	
	for(int i = 0; i < squareMatrixSize; i++) delete []squareMatrix[i];
	delete []squareMatrix;
	
	return 0;
}
