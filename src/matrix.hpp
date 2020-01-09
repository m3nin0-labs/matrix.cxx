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
        double set(int ncol, int nrow);

    };
}

#endif
