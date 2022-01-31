# Cpp-Linear-Algebra

---

To practice my C++ skills, I created my own implementation of 2x1 and 1x2 vectors, as 
well as 2x2 arrays. This project supports:
1. Dot product
2. Transpose
3. Addition, multiplication, and Subtraction with C++ operator overloading
4. Matrix inversion
5. Printing out values in a nice format

The main.cxx file shows examples of these features. This project uses
separate header and implementation files. All classes and
functions are part of the namespace "vecmat" (a mashup of vector and
matrix).

To execute this code, use your C++ compiler of choice to compile the
.cxx files with this shell command:
``` 
g++ vector.cxx matrix.cxx main.cxx
```

You can see the output by running:
```
./a.out 
```

This is a project I made to learn more about C++, so I left out some
functionality for convenience. Some useful features to implement in the future
would include setting values outside of the constructors, calculating 
eigenvalues/eigenvectors, creating objects
of variable length, and supporting the creation and operation on vectors/matrices
longer than 2.

Cheers, I hope you find this useful.
