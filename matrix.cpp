#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "matrix.h"
#include <iostream>


Matrix::Matrix() : Matrix(1,1){}                                              //default constructor

Matrix::Matrix(unsigned _rows, unsigned _columns)
{
   matrix.resize(_rows);
   for (unsigned i=0; i < matrix.size(); i++){
      matrix[i].resize(_columns, 0);
   }
   rows = _rows;
   columns = _columns;
}

bool Matrix::setValue(unsigned rowset, unsigned columnset, float set)         //function will return false if it's outside of the scope
{
   if ((rowset > rows) | (columnset > columns))
   {
      return false;
   }
   else
   {
      matrix[rowset-1][columnset-1] = set;
      return true;
   }
}
void Matrix::show()                                                           //prints out the matrix
{
    for (int i=0; i<rows; i++) {
      for (int j=0; j<columns; j++) {
         std::cout << matrix[i][j] << ", ";
      }
      std::cout << std::endl;
    } 
}


float Matrix::getValue(unsigned rowget, unsigned columnget)
{
   if(rowget > rows | columnget | columns)
   {
      std::cout << "Element doesn't exist";
      return -1;
   }
   return matrix[rowget][columnget];
}

Matrix Matrix::operator+(const Matrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns){
		std::cout << "Matrix sizes do not match." << std::endl;
		return (*this);
	}
	Matrix new_mat(rows,columns);
	for (int i=0; i<rows; i++){
		for (int j=0; j<columns; j++){
			new_mat.matrix[i][j] = rhs.matrix[i][j] + matrix[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	if(columns != rhs.rows){
      std::cout << "Matrix sizes do not match." << std::endl;
      return (*this);
   }
	Matrix new_mat(rows,rhs.columns);
	for(int i=0; i<rows; i++){	
      for(int j=0; j<rhs.columns; j++){
         for( int k=0; k < columns; k++){
            new_mat.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
	      }
	   }
	}
   return new_mat;

}


Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
   if (lhs.rows != rhs.rows || rhs.columns != rhs.columns){
		std::cout << "Matrix sizes do not match." << std::endl;
		return lhs;
	}
	Matrix new_mat(lhs.rows,lhs.columns);
	for (int i=0; i<lhs.rows; i++){
		for (int j=0; j<lhs.columns; j++){
			new_mat.matrix[i][j] = lhs.matrix[i][j] - rhs.matrix[i][j];
		}
	}
	return new_mat;

}

#endif