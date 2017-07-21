#pragma once

#include <string>
// CMatrix.h - Used for multiplying 4x4 matrices

using namespace std;

class CMatrix
{
public:
	CMatrix(float elements[4][4]);
	CMatrix* Identity();
	CMatrix* Multiply(CMatrix* matrix);
	CMatrix(void);
	~CMatrix(void);
	string ToString();
	float elements[4][4];
private:
	int rows, columns;
};

