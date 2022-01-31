#include "vector.h"

#ifndef MATRIX_H
#define MATRIX_H

namespace vecmat {
    class Matrix {
        public:
            Matrix(); // default constructor
            Matrix(Vector input_vec1, Vector input_vec2); // constructor from two vectors
            Matrix(double input_val1, double input_val2, double input_val3, double input_val4); // Specify all values constructor

            double getVal1();
            double getVal2();
            double getVal3();
            double getVal4();

            void transpose();
            bool is_identity();
            double determinant();
            Matrix inverse();
            static Matrix dot(Matrix input_matrix1, Matrix input_matrix2);
            static Vector dot(Matrix input_matrix, Vector input_vec);
            static Vector dot(Vector input_vec, Matrix input_matrix);
            void print();
            
        private:
            double val1; // top left
            double val2; // top right
            double val3; // bottom left
            double val4; // bottom right
    };
    // Make dot function callable outside of the class 
    Matrix dot(Matrix input_matrix1, Matrix input_matrix2);
    Vector dot(Matrix input_matrix, Vector input_vec);
    Vector dot(Vector input_vec, Matrix input_matrix);

    // other operators
    Matrix operator+(Matrix inputMat1, Matrix inputMat2);
    Matrix operator+(Matrix inputMat, double inputScalar);
    Matrix operator+(double inputScalar, Matrix inputMat);
            
    Matrix operator-(Matrix inputMat1, Matrix inputMat2);
    Matrix operator-(Matrix inputMat, double inputScalar);
    Matrix operator-(double inputScalar, Matrix inputMat);

    Matrix operator*(Matrix inputMat1, Matrix inputMat2);
    Matrix operator*(double inputScalar, Matrix inputMat);
    Matrix operator*(Matrix inputMat, double inputScalar);

}
#endif // MATRIX_H