#include "vector.h"
#include "matrix.h"
#include <iostream>
using namespace std;

namespace vecmat {

    Vector::Vector() { // Default constructor
        val1 = 1; // By default, set both values to 1
        val2 = 1;
        isHorizontal = true; // default to horizontal
    }

    Vector::Vector(double input_val1, double input_val2, bool input_isHorizontal) { // Two values provided constructor
        val1 = input_val1;
        val2 = input_val2;
        isHorizontal = input_isHorizontal;
    }

    void Vector::print() {
        if (isHorizontal) {
            cout << "[" << val1 << " " << val2 << "]" << endl;
        } else {
            cout << "[" << val1 << "\n" << val2 << "]" << endl;
        }
    }

    void Vector::transpose() {
        // To transpose, simply switch the isHorizontal value
        isHorizontal = !isHorizontal;
    }

    bool Vector::getHorizontal() {
        return isHorizontal;
    }

    void Vector::setHorizontal(bool input) {
        isHorizontal = input;
    }

    double Vector::getVal1() {
        return val1;
    }

    double Vector::getVal2() {
        return val2;
    }


    //////// Operators

    Vector operator+(Vector inputVec1, Vector inputVec2) {
        // Must be both horizontal or both vertical
        assert( (inputVec1.getHorizontal() && inputVec2.getHorizontal()) || (!inputVec1.getHorizontal() && !inputVec2.getHorizontal()) );

        bool hori = true;

        if (!inputVec1.getHorizontal()) { // already checked that the input vector's direction matches this vector, so you only need to check this vector
            hori = false; // default is horizontal, so only need to check and set vertical
        }

        double outputVal1 = inputVec1.getVal1() + inputVec2.getVal1();
        double outputVal2 = inputVec1.getVal2() + inputVec2.getVal2();

        Vector output(outputVal1, outputVal2, hori);
        return output;
    }

    Vector operator+(Vector inputVec, double inputScalar) {

        bool hori = true;

        if (!inputVec.getHorizontal()) { //copy the inputVec's direction to the new vector
            hori = false; // default is horizontal, so only need to check and set vertical
        }

        double outputVal1 = inputVec.getVal1() + inputScalar;
        double outputVal2 = inputVec.getVal2() + inputScalar;

        Vector output(outputVal1, outputVal2, hori);
        return output;
    }

    Vector operator+(double inputScalar, Vector inputVec) {
        // Simply use our operator declared above, since addition is commutative
        return inputVec + inputScalar; 
    }

    Vector operator-(Vector inputVec1, Vector inputVec2) {
        return inputVec1 + (-1 * inputVec2);
    }

    Vector operator-(Vector inputVec, double inputScalar) {
        return inputVec + (-1 * inputScalar);
    }

    Vector operator-(double inputScalar, Vector inputVec) {
        return inputScalar + (-1 * inputVec);
    }


    Vector operator*(Vector inputVec1, Vector inputVec2) { 
        // If both horizontal or both vertical, return a number
        assert ((inputVec1.getHorizontal() && inputVec2.getHorizontal()) || (!inputVec1.getHorizontal() && !inputVec2.getHorizontal()) );

        bool hori = true;

        if (!inputVec1.getHorizontal()) { //copy the inputVec's direction to the new vector
            hori = false; // default is horizontal, so only need to check and set vertical
        }

        double outputVal1 = inputVec1.getVal1() * inputVec2.getVal1();
        double outputVal2 = inputVec1.getVal2() * inputVec2.getVal2();

        Vector output(outputVal1, outputVal2, hori);
        return output;
    }

    Vector operator*(double inputScalar, Vector inputVec) {
        bool hori = true;

        if (!inputVec.getHorizontal()) { //copy the inputVec's direction to the new vector
            hori = false; // default is horizontal, so only need to check and set vertical
        }

        double outputVal1 = inputVec.getVal1() * inputScalar;
        double outputVal2 = inputVec.getVal2() * inputScalar;

        Vector output(outputVal1, outputVal2, hori);
        return output;
    }

    Vector operator*(Vector inputVec, double inputScalar) {
        return inputScalar * inputVec;
    }

}