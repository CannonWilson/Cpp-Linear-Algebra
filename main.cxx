// This file includes examples of the various pieces of functionality
// I've created for my custom Vector and Matrix classes.
// You can toggle which part of the output you want to see
// printed out by changing the boolean values at the top
// of main().

#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;
using namespace vecmat;


int main() {
    ///////// Check these variables based on what you want to see printed out to the screen
    bool printVec = true;
    bool printMatrix = true;
    bool printVecOp = true;
    bool printMatOp = true;
    bool printLA = true;


    /////////  Check vector functionality
    if (printVec) cout << "vector1: Create default vector and print it out" << endl;
    Vector vector1;
    if (printVec) vector1.print();

    if (printVec) cout << "vector2: Create horizontal vector and print it out" << endl;
    Vector vector2(2.0, 2.2, true);
    if (printVec) vector2.print();

    if (printVec) cout << "vector3: Create vertical vector and print it out" << endl;
    Vector vector3(3.0, 3.3, false);
    if (printVec) vector3.print();

    if (printVec) cout << "vector4: Create horizontal vector, transpose it, and print it out" << endl;
    Vector vector4(4.0, 4.4, true);
    vector4.transpose();
    if (printVec) vector4.print();

    if (printVec) cout << "vector5: Create vertical vector, transpose it, and print it out" << endl;
    Vector vector5(5.0, 5.5, false);
    vector5.transpose();
    if (printVec) vector5.print(); 



    /////////  Check matrix functionality
    if (printMatrix) cout << "matrix1: Create default matrix and print it out" << endl;
    Matrix matrix1;
    if (printMatrix) matrix1.print();

    if (printMatrix) cout << "matrix 2: Create matrix from horizontal vectors 2 and 5" << endl;
    Matrix matrix2(vector2, vector5);
    if (printMatrix) matrix2.print();

    if (printMatrix) cout << "matrix 3: Create matrix from vertical vectors 3 and 4" << endl;
    Matrix matrix3(vector3, vector4);
    if (printMatrix) matrix3.print();

    if (printMatrix) cout << "matrix 4: Create matrix from specified values" << endl;
    Matrix matrix4(1.0, 2.0, 3.0, 4.0);
    if (printMatrix) matrix4.print();

    if (printMatrix) cout << "Transpose matrix4 from above and print out the result" << endl;
    matrix4.transpose();
    if (printMatrix) matrix4.print();

    if (printMatrix) cout << "Check if matrix1 is an identity matrix" << endl;
    if (printMatrix) cout << matrix1.is_identity() << endl;

    if (printMatrix) cout << "Check if matrix2 is an identity matrix" << endl;
    if (printMatrix) cout << matrix2.is_identity() << endl;

    if (printMatrix) cout << "Compute the determinant of matrix4^T" << endl;
    if (printMatrix) cout << matrix4.determinant() << endl;

    if (printMatrix) cout << "matrix5: Compute the inverse of matrix4^T" << endl;
    Matrix matrix5 = matrix4.inverse();
    if (printMatrix) matrix5.print();
    
    if (printMatrix) cout << "matrix6: Calculate the dot product of matrix3 and matrix5" << endl;
    Matrix matrix6 = dot(matrix3, matrix5);
    if (printMatrix) matrix6.print();

    if (printMatrix) cout << "vector6: Calculate the dot product of matrix2 and vector4" << endl;
    Vector vector6 = dot(matrix2, vector4);
    // Also works with horizontal vectors like this:
    // Vector vector6 = dot(vector2, matrix2);
    if (printMatrix) vector6.print();




    ///////// Check vector operator functionality
    if (printVecOp) cout << "vector7: Add vector3 and vector4" << endl;
    Vector vector7 = vector3 + vector4;
    if (printVecOp) vector7.print();

    if (printVecOp) cout << "vector8: Add 3.7 to vector1" << endl;
    Vector vector8 = 3.7 + vector1; // same as below:
    // Vector vector8 = vector1 + 3.7;
    if (printVecOp) vector8.print();

    if (printVecOp) cout << "vector9: vector2 - vector1" << endl;
    Vector vector9 = vector2 - vector1;
    if (printVecOp) vector9.print();

    if (printVecOp) cout << "vector10: vector4 - 1.6" << endl;
    Vector vector10 = vector4 - 1.6;
    if (printVecOp) vector10.print();

    if (printVecOp) cout << "vector11: 1 - vector5" << endl;
    Vector vector11 = 1 - vector5;
    if (printVecOp) vector11.print();

    if (printVecOp) cout << "vector12: -2 * vector3" << endl;
    Vector vector12 = -2 * vector3;
    if (printVecOp) vector12.print(); 

    if (printVecOp) cout << "vector13: vector10 * vector12" << endl;
    Vector vector13 = vector10 * vector12;
    if (printVecOp) vector13.print();




    ///////// Check matrix operator functionality
    if (printMatOp) cout << "matrix7: matrix2 + matrix3" << endl;
    Matrix matrix7 = matrix2 + matrix3;
    if (printMatOp) matrix7.print();

    if (printMatOp) cout << "matrix8: matrix1 + 4.2" << endl;
    Matrix matrix8 = matrix1 + 4.2; // Same as:
    // Matrix matrix8 = 4.2 + matrix1;
    if (printMatOp) matrix8.print();

    if (printMatOp) cout << "matrix9: matrix1 - 0.9" << endl;
    Matrix matrix9 = matrix1 -0.9;
    if (printMatOp) matrix9.print();

    if (printMatOp) cout << "matrix10: 0.9 - matrix1" << endl;
    Matrix matrix10 = 0.9 - matrix1;
    if (printMatOp) matrix10.print();

    if (printMatOp) cout << "matrix11: matrix2 * 11" << endl;
    Matrix matrix11 = matrix2 * 11; // Same as:
    // Matrix matrix11 = 11 * matrix2;
    if (printMatOp) matrix11.print();

    if (printMatOp) cout << "matrix12: matrix2 * matrix3" << endl;
    Matrix matrix12 = matrix2 * matrix3;
    if (printMatOp) matrix12.print();




    ///////// Solve Linear Equations
    if (printLA) cout << "1. Solve this system of linear equations with two unknowns: 2x + 3y = 26, 3x - 4y = 5." << endl;
    if (printLA) cout << "First value in output vector is x, second value is y." << endl;
    Matrix A1(2, 3, 3, -4); // coefficient matrix
    Vector b1(26, 5, false); // horizontal answer vector
    Vector x1 = dot(A1.inverse(), b1);
    if (printLA) x1.print();

    if (printLA) cout << "2. Solve this system of linear equations with two unknowns: 4x + y = 27, 2x - 3y = -11." << endl;
    if (printLA) cout << "First value in output vector is x, second value is y." << endl;
    Matrix A2(4, 1, 2, -3); // coefficient matrix
    Vector b2(27, -11, false); // horizontal answer vector
    Vector x2 = dot(A2.inverse(), b2);
    if (printLA) x2.print();




    return 0;
} 