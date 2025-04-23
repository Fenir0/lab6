#ifndef MATRIX
#define MATRIX

#include<iostream>
#include<cstdlib>
struct matrix{
    int** mt;
    int n, m, id;
    static int id_count;
    matrix();
    matrix(int c_n, int c_m);
    matrix(const matrix& res);
    ~matrix();
    
    matrix operator+(matrix& res);
    matrix operator-(matrix& res);
    matrix operator*(int num);
    matrix operator*(matrix& res);
    matrix operator=(const matrix& res);
    int max();
    bool operator==(matrix& res);
    protected:
    bool operate(char operation,matrix* dummy, matrix* res, int temp = 1);
};

std::istream& operator>>(std::istream& s, matrix& res);
std::ostream& operator<<(std::ostream& s, const matrix& res);

#endif
