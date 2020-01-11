#include <iostream>
#include "matrix.hpp"


MatrixH::Matrix::Matrix(int ncol, int nrow)
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

MatrixH::Matrix& MatrixH::Matrix::operator +(MatrixH::Matrix& m_obj)
{
	return sum(m_obj);
}

MatrixH::Matrix& MatrixH::Matrix::operator -(MatrixH::Matrix& m_obj)
{
	return subtract(m_obj);
}

MatrixH::Matrix& MatrixH::Matrix::operator *(MatrixH::Matrix& m_obj)
{
	return matmul(m_obj);
}

MatrixH::Matrix& MatrixH::Matrix::operator /(MatrixH::Matrix& m_obj)
{
	return divide(m_obj);
}

MatrixH::Matrix& MatrixH::Matrix::sum(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	for(int i = 0; i < this->ncol * this->nrow; i++)
	{
		m->data[i] = this->data[i] + m_obj.data[i];
	}
	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::subtract(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	for(int i = 0; i < this->ncol * this->nrow; i++)
	{
		m->data[i] = this->data[i] - m_obj.data[i];
	}
	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::divide(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	for(int i = 0; i < this->ncol * this->nrow; i++)
	{
		m->data[i] = this->data[i] / m_obj.data[i];
	}
	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::matmul(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	for(int i = 0; i < this->ncol * this->nrow; i++)
	{
		m->data[i] = this->data[i] * m_obj.data[i];
	}
	return *m;
}

int main()
{
	MatrixH::Matrix m1 = MatrixH::Matrix(1, 1);
	MatrixH::Matrix m2 = MatrixH::Matrix(2, 2);
	
	m1 + m2;
}
