#include "matrix.h"
#include "vector.h"
#include <iostream>
#include <assert.h>
using namespace std;

namespace vecmat {

    Matrix::Matrix() { // default constructor, make identity matrix
        val1 = 1;
        val2 = 0;
        val3 = 0;
        val4 = 1;
    }

    Matrix::Matrix(Vector input_vec1, Vector input_vec2) {
        // Must be both horizontal or both vertical
        assert( (input_vec1.getHorizontal() && input_vec2.getHorizontal()) || (!input_vec1.getHorizontal() && !input_vec2.getHorizontal()) );

        if (input_vec1.getHorizontal() && input_vec2.getHorizontal()) {
            // Both vectors are horizontal
            val1 = input_vec1.getVal1();
            val2 = input_vec1.getVal2();
            val3 = input_vec2.getVal1();
            val4 = input_vec2.getVal2(); 
        }

        if (!input_vec1.getHorizontal() && !input_vec2.getHorizontal()) {
            // Both vectors are vertical
            val1 = input_vec1.getVal1();
            val2 = input_vec2.getVal1();
            val3 = input_vec1.getVal2();
            val4 = input_vec2.getVal2(); 
        }
    }

    Matrix::Matrix(double input_val1, double input_val2, double input_val3, double input_val4) { // specify all values constructor
        val1 = input_val1;
        val2 = input_val2;
        val3 = input_val3;
        val4 = input_val4;
    }

    double Matrix::getVal1() {
        return val1;
    }

    double Matrix::getVal2() {
        return val2;
    }

    double Matrix::getVal3() {
        return val3;
    }

    double Matrix::getVal4() {
        return val4;
    }

    void Matrix::transpose() {
        // To transpose a 2x2 array, we only need to swap the top
        // right and bottom left values.
        swap(val2, val3);
    }

    bool Matrix::is_identity() {
        if ( val1 == 1 && val2 == 0 && val3 == 0 && val4 ==1 ) {
            return true;
        }
        else {
            return false;
        }
    }

    double Matrix::determinant() {
        double det = (val1 * val4) - (val3 * val2);
        // Check for values close to 0
        if (det < 0.00000000001 && det > -0.00000000001) {
            return 0;
        }
        return det;
    }

    Matrix Matrix::inverse() {
        // determinant cannot be 0
        assert( determinant() != 0 );

        double newVal1 = 0, newVal2 = 0, newVal3 = 0, newVal4 = 0;
        double multiplier = 1 / determinant();

        newVal1 = multiplier * val4;
        newVal2 = -1 * multiplier * val2;
        newVal3 = -1 * multiplier * val3;
        newVal4 = multiplier * val1;

        Matrix newMatrix(newVal1, newVal2, newVal3, newVal4);
        return newMatrix;
    }

    Matrix Matrix::dot(Matrix input_matrix1, Matrix input_matrix2) { 
        double newVal1 = 0, newVal2 = 0, newVal3 = 0, newVal4 = 0;

        newVal1 = input_matrix1.getVal1() * input_matrix2.getVal1() + input_matrix1.getVal2() * input_matrix2.getVal3();
        newVal2 = input_matrix1.getVal1() * input_matrix2.getVal2() + input_matrix1.getVal2() * input_matrix2.getVal4();
        newVal3 = input_matrix1.getVal3() * input_matrix2.getVal1() + input_matrix1.getVal4() * input_matrix2.getVal3();
        newVal4 = input_matrix1.getVal3() * input_matrix2.getVal2() + input_matrix1.getVal4() * input_matrix2.getVal4();

        Matrix newMatrix(newVal1, newVal2, newVal3, newVal4);
        return newMatrix;
    } 

    Vector Matrix::dot(Matrix input_matrix, Vector input_vec) {
        assert( input_vec.getHorizontal() == false); // make sure vector is vertical

        double newVal1 = input_matrix.getVal1() * input_vec.getVal1() + input_matrix.getVal2() * input_vec.getVal2();
        double newVal2 = input_matrix.getVal3() * input_vec.getVal1() + input_matrix.getVal4() * input_vec.getVal2();

        Vector result(newVal1, newVal2, false); // make new vertical vector
        return result;
    }

    Vector Matrix::dot(Vector input_vec, Matrix input_matrix) { 
        assert( input_vec.getHorizontal() == true); // make sure vector is horizontal

        double newVal1 = input_vec.getVal1() * input_matrix.getVal1() + input_vec.getVal2() * input_matrix.getVal3();
        double newVal2 = input_vec.getVal1() * input_matrix.getVal2() + input_vec.getVal2() * input_matrix.getVal4();

        Vector result(newVal1, newVal2, true); // make new horizontal vector
        return result;
    }

    // Makes 'dot' function available in main.cpp without saying "Matrix::dot"
    Matrix dot(Matrix input_matrix1, Matrix input_matrix2) { 
        return Matrix::dot(input_matrix1, input_matrix2);
    } 

    Vector dot(Matrix input_matrix, Vector input_vec) {
        return Matrix::dot(input_matrix, input_vec);
    }

    Vector dot(Vector input_vec, Matrix input_matrix) { 
        return Matrix::dot(input_vec, input_matrix);
    }

    void Matrix::print() {
        cout << "[" << val1 << " " << val2 << "\n " << val3 << " " << val4 << "]" << endl;
    }



    ///////// Operators
    Matrix operator+(Matrix inputMat1, Matrix inputMat2) {

        double outputVal1 = inputMat1.getVal1() + inputMat2.getVal1();
        double outputVal2 = inputMat1.getVal2() + inputMat2.getVal2();
        double outputVal3 = inputMat1.getVal3() + inputMat2.getVal3();
        double outputVal4 = inputMat1.getVal4() + inputMat2.getVal4();

        Matrix output(outputVal1, outputVal2, outputVal3, outputVal4);
        return output;
    }

    Matrix operator+(Matrix inputMat, double inputScalar) {

        double outputVal1 = inputMat.getVal1() + inputScalar;
        double outputVal2 = inputMat.getVal2() + inputScalar;
        double outputVal3 = inputMat.getVal3() + inputScalar;
        double outputVal4 = inputMat.getVal4() + inputScalar;

        Matrix output(outputVal1, outputVal2, outputVal3, outputVal4);
        return output;
    }

    Matrix operator+(double inputScalar, Matrix inputMat) {
        return inputMat + inputScalar; 
    }

    Matrix operator-(Matrix inputMat1, Matrix inputMat2) {
        return inputMat1 + (-1 * inputMat2);
    }

    Matrix operator-(Matrix inputMat, double inputScalar) {
        return inputMat + (-1 * inputScalar);
    }

    Matrix operator-(double inputScalar, Matrix inputMat) {
        return inputScalar + (-1 * inputMat);
    }

    Matrix operator*(Matrix inputMat1, Matrix inputMat2) {
        double outputVal1 = inputMat1.getVal1() * inputMat2.getVal1();
        double outputVal2 = inputMat1.getVal2() * inputMat2.getVal2();
        double outputVal3 = inputMat1.getVal3() * inputMat2.getVal3();
        double outputVal4 = inputMat1.getVal4() * inputMat2.getVal4();

        Matrix output(outputVal1, outputVal2, outputVal3, outputVal4);
        return output;
    }

    Matrix operator*(double inputScalar, Matrix inputMat) {
        double outputVal1 = inputScalar * inputMat.getVal1();
        double outputVal2 = inputScalar * inputMat.getVal2();
        double outputVal3 = inputScalar * inputMat.getVal3();
        double outputVal4 = inputScalar * inputMat.getVal4();

        Matrix output(outputVal1, outputVal2, outputVal3, outputVal4);
        return output;
    }

    Matrix operator*(Matrix inputMat, double inputScalar)  {
        return inputScalar * inputMat;
    }

}