//matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
   
public:
   unsigned rows;
   unsigned columns;
   std::vector<std::vector<float> > matrix;                       //Matrix of a vector of vectors
   Matrix();                                                      //default constructor
   Matrix(unsigned _rows, unsigned _columns);                     //constructor
   bool setValue(unsigned rowset, unsigned columnset, float set); //set values
   //unsigned getRows();
   //unsigned getColumns();
   float getValue(unsigned rowget, unsigned columnget);
   void show();                                                   //cout the matrix
   
   Matrix operator+(const Matrix& rhs);                           //overloaded addition operator
   Matrix operator*(const Matrix& rhs);                           //overloaded multiplication operator

};

#include "matrix.cpp"

#endif