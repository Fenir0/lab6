#include "matr.h"

struct square_matrix: public matrix{
    square_matrix();
    square_matrix(int n);

    int determinant();
    bool is_symmetrical();
    void power(int n);
    square_matrix& operator* (square_matrix& res);
};