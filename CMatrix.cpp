// CMatrix.cpp - Used for multiplying 4x4 matrices

#include "CMatrix.h"


CMatrix::CMatrix(float elements[4][4]){
	for(int row=0;row<4;row++){
		for(int column=0;column<4;column++){
			this->elements[row][column] = elements[row][column];
		}
	}
}

// Returns the identity matrix
CMatrix* CMatrix::Identity(){
	float matrixElements[4][4] = {
									{1,0,0,0},
									{0,1,0,0},
									{0,0,1,0},
									{0,0,0,1}};

	CMatrix* matrix = new CMatrix(matrixElements);

	return matrix;
}

// Multiplies this matrix with another matrix
CMatrix* CMatrix::Multiply(CMatrix* matrix){
	CMatrix* resultMatrix = new CMatrix();
	
	for(int row=0;row<4;row++){
		for(int column=0;column<4;column++){
			resultMatrix->elements[row][column] = 0;

			for(int n=0;n<4;n++){
				resultMatrix->elements[row][column]+= 
					elements[row][n]*matrix->elements[n][column];
			}
		}
	}

	return resultMatrix;
}

// Converts the matrix to a string representation
string CMatrix::ToString(){
	string matrixString = "";

	for(int row=0;row<4;row++){
		for(int column=0;column<4;column++){
			float matrixElement = this->elements[row][column];
			char* matrixElementChar = new char[32];
			sprintf(matrixElementChar,"%.0f",matrixElement);
			matrixString += matrixElementChar;
			matrixString += "\t";
		}

		matrixString += "\n";
	}

	return matrixString;
}

CMatrix::CMatrix(void)
{

}

CMatrix::~CMatrix(void)
{
}
