#ifndef VECTOR_H
#define VECTOR_H

namespace vecmat {
    class Vector {

        public: 
            Vector(); // Default constructo
            Vector(double input_val1, double input_val2, bool input_isHorizontal); // Two doubles provided

            void transpose();
            void print();

            bool getHorizontal();
            void setHorizontal(bool input);

            double getVal1();
            double getVal2();

        private:
            bool isHorizontal;
            double val1;
            double val2;

    };

    Vector operator+(Vector inputVec1, Vector inputVec2);
    Vector operator+(Vector inputVec, double inputScalar);
    Vector operator+(double inputScalar, Vector inputVec);
            
    Vector operator-(Vector inputVec1, Vector inputVec2);
    Vector operator-(Vector inputVec, double inputScalar);
    Vector operator-(double inputScalar, Vector inputVec);

    Vector operator*(Vector inputVec1, Vector inputVec2);
    Vector operator*(double inputScalar, Vector inputVec);
    Vector operator*(Vector inputVec, double inputScalar);

}

#endif // VECTOR_H