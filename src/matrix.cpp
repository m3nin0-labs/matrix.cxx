#include "matrix.hpp"


MatrixH::Matrix(int ncol, int nrow)
{
	this->ncol = ncol;
	this->nrow = nrow;
	
	this->data = new double[ncol * nrow];
}

double MatrixH::Matrix::get(const int col, const int row)
{
	return this->data[col * row + col];
}

void MatrixH::Matrix::set(const int col, const int row, double value)
{
	data[col * row + col] = value;
}
