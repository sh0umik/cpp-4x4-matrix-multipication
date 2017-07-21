// MatrixMultiplication.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "CMatrix.h"

using namespace std;

// Construct the first matrix
float matrixElements[4][4];

CMatrix *identitiMatrix = new CMatrix();

CMatrix *newMatrix = new CMatrix();

CMatrix *resultMatrix = new CMatrix();

void loopFile(ifstream *in);


int main2() {


    ifstream in("input.txt");

    if (!in) {
        cout << "Cannot open file.\n";
    }

    if (in.is_open())
    {
        loopFile(&in);
    }

    in.close();

    //cout << "Final Result Matrix" << endl;
    //cout << resultMatrix->ToString() << endl;

    //system("pause");
    return 0;
}

void loopFile(ifstream *in) {

    string line;
    int x = 0, y = 0;
    while (getline(*in, line)) {

        if (line == "pop") {
            continue;
        }

        // continue to next line if push found
        if (line == "push") {
            // Construct the identity matrix
            identitiMatrix = newMatrix->Identity();
            resultMatrix = identitiMatrix;

            cout << "First Matrix :" << endl;
            cout << resultMatrix->ToString() << endl;
            continue;
        }else {

            // scan line and insert in to 4x4 matrix
            stringstream ssin(line);
            while (ssin.good() && x < 4) {
                ssin >> matrixElements[x][y++];
            }
            y = 0;
            x++;

            // if the scan is complete and no pop then multiply
            if (line != "pop" && x == 4) {
                newMatrix = new CMatrix(matrixElements);

                cout << "Multiplying With :" << endl;
                cout << newMatrix->ToString() << endl;

                resultMatrix = newMatrix->Multiply(resultMatrix);

                cout << "Result Matrix :" << endl;
                cout << resultMatrix->ToString() << endl;

                loopFile(in);
            }
        }
    }

}