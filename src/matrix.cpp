#include <omp.h>
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
	
	#pragma omp parallel
	{
		for(int i = 0; i < this->ncol * this->nrow; i++)
		{
			m->data[i] = this->data[i] + m_obj.data[i];
		}
	}
	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::subtract(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	#pragma omp parallel
	{
		for(int i = 0; i < this->ncol * this->nrow; i++)
		{
			m->data[i] = this->data[i] - m_obj.data[i];
		}
	}
	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::divide(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	#pragma omp parallel
	{
		for(int i = 0; i < this->ncol * this->nrow; i++)
		{
			m->data[i] = this->data[i] / m_obj.data[i];
		}		
	}

	return *m;
}

MatrixH::Matrix& MatrixH::Matrix::matmul(MatrixH::Matrix m_obj)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(this->ncol, this->nrow);
	
	#pragma omp parallel
	{
		for(int i = 0; i < this->ncol * this->nrow; i++)
		{
			m->data[i] = this->data[i] * m_obj.data[i];
		}
	}
	
	return *m;
}

int* MatrixH::Matrix::shape()
{
	int* shp = new int[2];
	shp[0] = this->ncol;
	shp[1] = this->nrow;
	
	return shp;
}

void MatrixH::Matrix::print()
{
	for(int i = 0; i < this->ncol; i++)
	{
		for(int j = 0; j < this->nrow; j++)
		{
			std::cout << this->get(i, j);
		}
		std::cout << std::endl;
	}
}

MatrixH::Matrix& MatrixH::zeros(int ncol, int nrow)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(ncol, nrow);
	
	for(int i = 0; i < ncol; i++)
	{
		for(int j = 0; j < nrow; j++)
		{
			m->set(i, j, 0);
		}
	}
	return *m;
}

MatrixH::Matrix& MatrixH::ones(int ncol, int nrow)
{
	MatrixH::Matrix* m = new MatrixH::Matrix(ncol, nrow);
	
	for(int i = 0; i < ncol; i++)
	{
		for(int j = 0 ; j < nrow; j++)
		{
			m->set(i, j, 1);
		}
	}
	return *m;
}

int main()
{
	MatrixH::Matrix m_ones = MatrixH::ones(5, 5);
	MatrixH::Matrix m_zeros = MatrixH::zeros(10, 10);

	m_ones.print();
	m_zeros.print();

	return 0;
}
