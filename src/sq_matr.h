#ifndef SQ_MATRIX
#define SQ_MATRIX

#include "matr.h"

class square_matrix: public matrix{
    public:
    square_matrix();
    square_matrix(int n);

    int determinant();
    bool is_symmetrical();
    void power(int n);
    protected:
    square_matrix& operator* (square_matrix& res);
};

#endif