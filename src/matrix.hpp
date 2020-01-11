#ifndef MATRIX_HEADER
#define MATRIX_HEADER

namespace MatrixH
{
    struct Matrix
    {
    private:
        double *data;
        int ncol, nrow;

    public:
        Matrix(int ncol, int nrow);

		double get(int ncol, int nrow);
        void set(int ncol, int nrow, double value);
        
		Matrix& operator +(Matrix& m_obj);
		Matrix& operator -(Matrix& m_obj);
		Matrix& operator *(Matrix& m_obj);
		Matrix& operator /(Matrix& m_obj);
		
		Matrix& sum(Matrix m_obj);
		Matrix& subtract(Matrix m_obj);
		Matrix& divide(Matrix m_obj);
		Matrix& matmul(Matrix m_obj);
    };
}

#endif
