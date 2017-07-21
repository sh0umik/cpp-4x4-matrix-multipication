// MatrixMultiplication.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "CMatrix.h"

using namespace std;

// Construct the scan matrix
float matrixElements[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};;

CMatrix *identitiMatrix = new CMatrix();

CMatrix *newMatrix = new CMatrix();

CMatrix *resultMatrix = new CMatrix();

void scanMatrix(string line);
void loopFile(ifstream *in);


int main() {


    ifstream in("input.txt");

    if (!in) {
        cout << "Cannot open file.\n";
    }

    // first result is identity matrix
    resultMatrix = newMatrix->Identity();

    if (in.is_open()) {
        loopFile(&in);
    }

    in.close();

    cout << "Final Result : \n" << resultMatrix->ToString();

    //cout << "Final Result Matrix" << endl;
    //cout << resultMatrix->ToString() << endl;

    //system("pause");
    return 0;
}

int x = 0, y = 0;
string task;


void loopFile(ifstream *in) {

    string line;

    while (getline(*in, line)) {
        char f = line.at(0);
        if (!isdigit(f)) {
           task = line;
            continue;
        }

        scanMatrix(line);

        loopFile(in);
    }
}

void scanMatrix(string line) {

    cout << "Result Matrix : \n" << resultMatrix->ToString();

    stringstream ssin(line);

    if (task == "translate") {
        while (ssin.good() && x < 3) {
            ssin >> matrixElements[x][y++];
        }
        y = 0;
        x++;
        if (x == 3) {
            stringstream ssin("1    1   1");
            while (ssin.good()) {
                ssin >> matrixElements[3][y++];
            }
            newMatrix = new CMatrix(matrixElements);
            cout << "Multiplying Translate : \n" << newMatrix->ToString();
            resultMatrix = newMatrix->Multiply(resultMatrix);

            // reset the matrix
            memset(matrixElements, 0, sizeof matrixElements);
            x= 0; y=0;
            cout << "Result : \n" << resultMatrix->ToString();
        }
    }
    else if (task == "scale") {
        while (ssin.good() && x < 3) {
            ssin >> matrixElements[x++][y++];
        }
        y = 0;
        if (x == 3) {
            stringstream ssin("0    0   0   1");
            while (ssin.good()) {
                ssin >> matrixElements[3][y++];
            }
            newMatrix = new CMatrix(matrixElements);
            resultMatrix = newMatrix->Multiply(resultMatrix);
            memset(matrixElements, 0, sizeof matrixElements);
            x= 0; y=0;
            cout << "Scale : \n" << newMatrix->ToString();
        }
    }
    else if (task == "triangle") {
        y = 3;
        while (ssin.good() && x < 3) {
            ssin >> matrixElements[x++][y];
        }
        y = 0;
        if (x == 3) {
            stringstream ssin("0    0   0   1");
            while (ssin.good()) {
                ssin >> matrixElements[3][y++];
            }
            newMatrix = new CMatrix(matrixElements);
            resultMatrix = newMatrix->Multiply(resultMatrix);
            cout << "Triangle : \n" << newMatrix->ToString();
        }
    }


}
